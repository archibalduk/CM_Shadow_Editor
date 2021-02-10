#include "spreadsheet_file_xlsx.h"

// Qt headers
#include <QTextCodec>

// Application headers
#include "../ui/progress_dialog.h"


/* ========================== */
/*      XLSX Spreadsheet      */
/* ========================== */

// --- Default constructor --- //
SpreadsheetFileXLSX::SpreadsheetFileXLSX() :
    SpreadsheetFile()
{
    m_Xlsx = nullptr;
}

// --- Actual constructor --- //
SpreadsheetFileXLSX::SpreadsheetFileXLSX(QFile &file, const QString &filename) :
    SpreadsheetFile(file),
    m_Filename(filename)
{
    // Set initial progress dialog value as the xlsx constructor may take some time when reading a new file
    m_ProgressDialog.set("Processing xlsx spreadsheet", 1);
    m_Xlsx = new QXlsx::Document(filename);
}

// --- Destructor --- //
SpreadsheetFileXLSX::~SpreadsheetFileXLSX()
{
    if(m_Xlsx != nullptr)
        delete m_Xlsx;
}

/* ================== */
/*      File I/O      */
/* ================== */

// --- Read cells --- //
bool SpreadsheetFileXLSX::read(QVector<QVector<QVariant>> &cells, const qint32 &headerCount)
{
    // Progress window
    const qint64 size = m_File->size();
    m_ProgressDialog.set("Loading xlsx spreadsheet", size);

    // Header count
    m_HeaderCount = headerCount;

    // Spreadsheet dimensions
    const qint32 colCount = m_Xlsx->dimension().lastColumn() + 1;
    const qint32 rowCount = m_Xlsx->dimension().lastRow() + 1;

    // Read data rows
    for(qint32 row = m_HeaderCount + 1; row < rowCount; ++row) {
        // Progress
        m_ProgressDialog.increment(m_File->pos());

        // Buffer
        QVector<QVariant> vect;

        // Read the data columns
        for(qint32 col = 1; col < colCount; ++col)
            vect.push_back(m_Xlsx->read(row, col));

        // Save buffer to data
        cells.push_back(vect);
    }

    // Return true if at least on row was read
    return(cells.size() > 0);
}

// --- Write cells --- //
bool SpreadsheetFileXLSX::writeCells(QVector<QVector<QVariant> > &prefix, QVector<QVector<QVariant> > &cells)
{
    // Progress window
    m_ProgressDialog.set("Saving xlsx spreadsheet", cells.size());

    /*
    // Number format
    QXlsx::Format numFormat;
    numFormat.setNumberFormatIndex(0);  // 0 = General
*/
    // Data rows
    const qint32 rowCount = cells.size();
    for(qint32 row = 0; row < rowCount; ++row) {
        // Progress
        m_ProgressDialog.increment();

        // Iterate over each prefix cell
        qint32 preCount = 0;
        if(row < prefix.size()) {
            preCount = prefix[row].size();
            for(qint32 col = 0; col < preCount; ++col)
                m_Xlsx->write(row+m_HeaderCount+1, col+1, prefix[row][col]);
        }

        // Iterate over each cell
        const qint32 colCount = cells[row].size();
        for(qint32 col = 0; col < colCount; ++col)
            m_Xlsx->write(row+m_HeaderCount+1, col+1+preCount, cells[row][col]);
    }

    return m_Xlsx->saveAs(m_Filename);
}

// --- Write header cells --- //
bool SpreadsheetFileXLSX::writeHeader(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &header)
{
    // Header format
    QXlsx::Format format;
    format.setFontBold(true);
    format.setPatternBackgroundColor(QColor(189, 215, 238));

    // Header rows
    m_HeaderCount = header.size();
    for(qint32 row = 0; row < m_HeaderCount; ++row) {

        // Iterate over each prefix cell
        qint32 preCount = 0;
        if(row < prefix.size()) {
            preCount = prefix[row].size();
            for(qint32 col = 0; col < preCount; ++col)
                m_Xlsx->write(row+1, col+1, prefix[row][col]);
        }

        // Iterate over each cell
        const qint32 colCount = header[row].size();
        for(qint32 col = 0; col < colCount; ++col)
            m_Xlsx->write(row+1, col+1+preCount, header[row][col], format);
    }

    return true;
}
