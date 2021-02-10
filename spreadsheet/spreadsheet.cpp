#include "spreadsheet.h"
#include "spreadsheet_file_csv.h"
#include "spreadsheet_file_xlsx.h"

// Qt headers
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QRegExp>
#include <QSettings>

// --- Static members --- //
QHash<QString, unsigned char> Spreadsheet::s_FileExtensions;


/* ===================== */
/*      Spreadsheet      */
/* ===================== */

// --- Default constructor --- //
Spreadsheet::Spreadsheet() :
    m_HeaderCount(2),   // Default header count = 2
    m_HideProgress(false)
{
    // Initialise file extensions if not already done
    if(s_FileExtensions.size() < 1)
        initFileExtensions();
}

// --- Default destructor --- //
Spreadsheet::~Spreadsheet()
{
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Open a file without showing a dialog window --- //
bool Spreadsheet::open(const QString &folder, const QString &filename)
{
    this->setFile(QString("%1/%2").arg(folder).arg(filename));
    return this->read();
}

// --- Read file --- //
bool Spreadsheet::read()
{
    // File
    QFile f(this->file());
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    // Spreadsheet
    bool result = false;

    if(m_FileExtension == XLSX) {
        SpreadsheetFileXLSX *sheet = new SpreadsheetFileXLSX(f, this->file());
        sheet->setSilent(m_HideProgress);
        result = sheet->read(m_Cells, m_HeaderCount);
        delete sheet;
        f.close();
        return result;
    }
    else {
        SpreadsheetFileCSV *sheet = new SpreadsheetFileCSV(f);
        sheet->setSilent(m_HideProgress);
        result = sheet->read(m_Cells, m_HeaderCount);
        delete sheet;
        f.close();
        return result;
    }
}

// --- Save spreadsheet without showing a dialog window --- //
bool Spreadsheet::save(const QString &folder, const QString &filename)
{
    this->setFile(QString("%1/%2").arg(folder).arg(filename));
    return this->write();
}

// --- Write file --- //
bool Spreadsheet::write()
{
    // File
    QFile f(this->file());
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
        return false;

    // Spreadsheet
    SpreadsheetFile *sheet = this->newSpreadsheet(f);
    bool result = sheet->writeHeader(m_HeaderPrefix, m_Header);

    if(result)
        result = sheet->writeCells(m_CellsPrefix, m_Cells); // Write cells if writing the header was a success

    delete sheet;
    f.close();
    return result;
}

// --- Create new spreadsheet file and return pointer --- //
SpreadsheetFile *Spreadsheet::newSpreadsheet(QFile &f)
{
    if(m_FileExtension == XLSX) {
        SpreadsheetFileXLSX *sheet = new SpreadsheetFileXLSX(f, this->file());
        sheet->setSilent(m_HideProgress);
        return sheet;
    }
    else {
        SpreadsheetFileCSV *sheet = new SpreadsheetFileCSV(f);
        sheet->setSilent(m_HideProgress);
        return sheet;
    }
}


/* ==================== */
/*      File I/O UI     */
/* ==================== */

// --- Show open dialog --- //
bool Spreadsheet::showOpenDialog(QString path)
{
    // Settings
    QSettings settings;

    // Use existing path if passed path is empty
    if(path.isEmpty())
        path = settings.value("paths/import", "C:/").toString();

    path = QFileDialog::getOpenFileName(nullptr,
                                        "Open Spreadsheet",
                                        path,
                                        this->fileExtensionList(true));

    // Abort if the user has clicked Cancel
    if(this->setFile(path) == false)
        return false;

    // Read the file
    else {
        settings.setValue("paths/import", m_Path);
        return this->read();
    }
}

// --- Show save dialog --- //
bool Spreadsheet::showSaveDialog(const QString &filename, QString path)
{
    // Settings
    QSettings settings;

    // Use existing path if passed path is empty
    if(path.isEmpty())
        path = settings.value("paths/export", "C:/").toString();

    // Default filter
    QString filter = this->filter(static_cast<unsigned char>(this->getDefaultFileExtension()));

    // Add default filename to path and remove extension
    path.append(filename);
    this->setFile(path);
    path = QString("%1%2").arg(m_Path).arg(m_FileName);

    path = QFileDialog::getSaveFileName(nullptr,
                                        "Save Spreadsheet",
                                        path,
                                        this->fileExtensionList(false),
                                        &filter);
    // Set file/abort if cancelled
    if(this->setFile(path) == false)
        return false;
    else {
        settings.setValue("paths/export", m_Path);
        return true;
    }
}

void Spreadsheet::setSilent(const bool &silent)
{
    m_HideProgress = silent;
}


/* ======================== */
/*      File Extension      */
/* ======================== */

// --- Return full file path, name and extension --- //
const QString Spreadsheet::file()
{
    return QString("%1%2.%3").arg(m_Path).arg(m_FileName).arg(s_FileExtensions.key(m_FileExtension, "csv"));
}

// --- Return file extension list for a dialog window --- //
QString Spreadsheet::fileExtensionList(const bool &mergedList)
{
    QString tmp;

    // Merged list (all file types under one filter
    if(mergedList) {

        tmp.append("Spreadsheet Files (");

        for(unsigned char i = 0; i < FILE_EXTENSION_COUNT; ++i)
            tmp.append("*." + s_FileExtensions.key(i) + " ");

        tmp.append(")");
    }

    // Separate list (individual filters)
    else {
        for(unsigned char type = CSV; type < FILE_EXTENSION_COUNT; ++ type) {

            // Don't add txt filter as it is part of the csv filter
            if(type == TXT)
                continue;

            // Add filter
            tmp.append(QString("%1;;").arg(filter(type)));
        }

        // Remove two trailing semi-colons as they are not required for the final filter
        tmp.chop(2);
    }

    return tmp;
}

// --- Return current file extension --- //
QString Spreadsheet::fileExtensionText()
{
    return s_FileExtensions.key(m_FileExtension);
}

// --- Return file name without the extension --- //
const QString Spreadsheet::fileName()
{
    return m_FileName;
}

// --- Return spreadsheet identifier --- //
const QString Spreadsheet::identifier()
{
    return this->headerCell(0,0).toString().replace(" ", "_").toLower();
}

// --- Get filter from file type --- //
const QString Spreadsheet::filter(const quint8 &type)
{
    if(type == XLSX)
        return QObject::tr("Excel Workbook (*.xlsx)");
    else
        return QObject::tr("Comma Separated Values (*.csv *.txt)");
}

// --- Get default file extension flag --- //
qint32 Spreadsheet::getDefaultFileExtension()
{
    QSettings settings;
    return settings.value("default_file_format", XLSX).toInt();
}

// --- Set default file extension flag --- //
void Spreadsheet::setDefaultFileExtension(const qint32 &i)
{
    QSettings settings;
    return settings.setValue("default_file_format", i);
}

// --- Initialise file extension hash --- //
void Spreadsheet::initFileExtensions()
{
    s_FileExtensions.insert("csv", CSV);
    s_FileExtensions.insert("txt", TXT);
    s_FileExtensions.insert("xlsx", XLSX);
}

// --- Set file name --- //
void Spreadsheet::setFileName(const QString &name)
{
    m_FileName = name;
}


/* ==================== */
/*      Folder Path     */
/* ==================== */

// --- Set file details from concatenated path string --- //
bool Spreadsheet::setFile(const QString &path)
{
    // Abort if empty
    if(path.isEmpty())
        return false;

    // Index of path/filename separator
    qint32 extPos = path.size() - path.lastIndexOf(".") - 1;
    qint32 namePos = path.lastIndexOf("/") + 1;

    // Folder path
    m_Path = path.left(namePos);

    // File name
    m_FileName = path.right(path.size() - namePos);

    // File extension
    m_FileExtension = s_FileExtensions.value(m_FileName.right(extPos), static_cast<unsigned char>(this->getDefaultFileExtension()));

    // Remove file extension from file name (if one exists)
    if(m_FileName.lastIndexOf(".") > 0)
        m_FileName.truncate(m_FileName.lastIndexOf("."));

    return true;
}


/* ======================= */
/*      Add Cell Data      */
/* ======================= */

// --- Add blank column to the current row --- //
void Spreadsheet::add()
{
    // Add row if vector is empty
    if(m_Cells.size() == 0)
        m_Cells.resize(1);

    m_Cells[m_Cells.size()-1].push_back("");
}

// --- Add column to the current row --- //
void Spreadsheet::add(const QVariant &data)
{
    // Add row if vector is empty
    if(m_Cells.size() == 0)
        m_Cells.resize(1);

    m_Cells[m_Cells.size()-1].push_back(data);
}

// --- Add a new row ready for adding columns to it --- //
void Spreadsheet::addNewRow()
{
    // As of Qt 5.6 QVector::resize() does not shrink the capacity anymore
    m_Cells.resize(m_Cells.size()+1);
}

// --- Add a QStringList as a new row --- //
void Spreadsheet::addNewRow(const QStringList &list)
{
    const qint32 row = m_Cells.size();

    // As of Qt 5.6 QVector::resize() does not shrink the capacity anymore
    m_Cells.resize(row+1);

    const qint32 size = list.size();
    for(qint32 i = 0; i < size; ++i)
        m_Cells[row].append(list[i]);
}


/* ========================= */
/*      Add Header Data      */
/* ========================= */

// --- Add column to the current header row --- //
void Spreadsheet::addHeader(const QVariant &data)
{
    // Add row if vector is empty
    if(m_Header.size() == 0)
        m_Header.resize(1);

    m_Header[m_Header.size()-1].push_back(data);
}

// --- Add a new header row ready for adding columns to it --- //
void Spreadsheet::addNewHeaderRow()
{
    // As of Qt 5.6 QVector::resize() does not shrink the capacity anymore
    m_Header.resize(m_Header.size()+1);
}

// --- Add a QStringList as a new header row --- //
void Spreadsheet::addNewHeaderRow(const QStringList &list)
{
    const qint32 row = m_Header.size();

    // As of Qt 5.6 QVector::resize() does not shrink the capacity anymore
    m_Header.resize(row+1);

    const qint32 size = list.size();
    for(qint32 i = 0; i < size; ++i)
        m_Header[row].append(list[i]);
}


/* ======================= */
/*      Get Cell Data      */
/* ======================= */

// --- Get cell --- //
QVariant Spreadsheet::cell(const qint32 &row, const qint32 &col)
{
    // Row sanity check
    if(row < 0 || row >= m_Cells.size())
        return QVariant();

    // Cell sanity check
    else if(col < 0 || col >= m_Cells[row].size())
        return QVariant();

    else
        return m_Cells[row][col];
}

// --- Get pointer to row of data (read only) --- //
const QVector<QVariant> *Spreadsheet::row(const qint32 &row)
{
    if(row < m_Cells.size())
        return &(m_Cells.at(row));
    else
        return nullptr;
}

// --- Get row count --- //
qint32 Spreadsheet::rowCount()
{
    return m_Cells.size();
}


/* ========================= */
/*      Get Header Data      */
/* ========================= */

// --- Get pointer to header row of data (read only) --- //
const QVector<QVariant> *Spreadsheet::header(const qint32 &row)
{
    if(row < m_Header.size())
        return &(m_Header.at(row));
    else
        return nullptr;
}

// --- Get header cell --- //
QVariant Spreadsheet::headerCell(const qint32 &row, const quint16 &col)
{
    // Row sanity check
    if (row < 0 || row >= m_Header.size())
        return QVariant();

    // Cell sanity check
    else if (col < 0 || col >= m_Header[row].size())
        return QVariant();

    else
        return m_Header[row][col];
}

// --- Get header row count --- //
qint32 Spreadsheet::headerCount()
{
    return m_Header.size();
}


/* ====================== */
/*      Get Settings      */
/* ====================== */

// --- Get export path --- //
QString Spreadsheet::exportPath()
{
    QSettings settings;
    return settings.value("paths/export", "C:/").toString();
}

// --- Get import path --- //
QString Spreadsheet::importPath()
{
    QSettings settings;
    return settings.value("paths/import", "C:/").toString();
}


/* ======================= */
/*      Set Cell Data      */
/* ======================= */

// --- Set cell from integer --- //
void Spreadsheet::set(const QVariant &data, const qint32 &row, const quint16 &col)
{
    if(row < m_Cells.size() && col < static_cast<quint16>(m_Cells[row].size()))
        m_Cells[row][col] = data;
}


/* ========================= */
/*      Set Header Data      */
/* ========================= */

// --- Set header cell from integer --- //
void Spreadsheet::setHeader(const QVariant &data, const qint32 &row, const quint16 &col)
{
    if(row < m_Header.size() && col < static_cast<quint16>(m_Header[row].size()))
        m_Header[row][col] = data;
}


// --- Set column count for header row --- //
void Spreadsheet::setHeaderColumnCount(const unsigned char &count, const qint32 &row)
{
    if(m_Header.size() < 1)
        return;

    // Set size for current row
    if(row < 0)
        m_Header[m_Header.size()-1].resize(count);
    // Else set size for selected row
    else
        m_Header[row].resize(count);
}

// --- Set header row count --- //
void Spreadsheet::setHeaderRowCount(const unsigned char &count)
{
    m_HeaderCount = count;
}


/* ================================= */
/*      Set Spanned Header Data      */
/* ================================= */

// --- Set spanned header cell from string --- //
void Spreadsheet::setSpannedHeader(const QVariant &data, const quint16 &col, const quint16 &span)
{
    // Skip invalid rows
    const qint32 row = m_Header.size() - 1;
    if(row < 0)
        this->addNewHeaderRow();

    // Resize columns if needed
    const quint16 last = col + span - 1;
    if(last >= m_Header[row].size())
        m_Header[row].resize(last + 1);

    // Add spanning: 3+ columns
    if(span > 2)
    {
        const quint16 mid = (col + last) / 2;
        m_Header[row][col] = QStringLiteral("|--");
        m_Header[row][mid] = data.toString().toUpper();
        m_Header[row][last] = QStringLiteral("--|");
        return;
    }
    // Add spanning: 2 columns
    else if(span == 2)
    {
        m_Header[row][col] = QString("%1 %2").arg(QStringLiteral("|--")).arg(data.toString().toUpper());
        m_Header[row][last] = QStringLiteral("--|");
        return;
    }
    // No span
    else
    {
        this->setHeader(data, row, col);
        return;
    }
}
