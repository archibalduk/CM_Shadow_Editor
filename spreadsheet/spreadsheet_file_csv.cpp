#include "spreadsheet_file_csv.h"

// Qt headers
#include <QLocale>
#include <QTextCodec>

// Application headers
#include "../ui/progress_dialog.h"


/* ========================= */
/*      CSV Spreadsheet      */
/* ========================= */

// --- Default constructor --- //
SpreadsheetFileCSV::SpreadsheetFileCSV() :
    SpreadsheetFile()
{

}

// --- Actual constructor --- //
SpreadsheetFileCSV::SpreadsheetFileCSV(QFile &file) :
    SpreadsheetFile(file)
{
    //m_File->setCodec(QTextCodec::codecForName("Latin-1"));    // ASCII
}


/* =================== */
/*      Delimiter      */
/* =================== */

// --- Get standard delimiter based upon the system locale --- //
QChar SpreadsheetFileCSV::getSystemDelimiter()
{
    QLocale locale;
    return (locale.decimalPoint() == '.') ? ',' : ';';
}

// --- Get delimiter description based upon system locale --- //
QString SpreadsheetFileCSV::getSystemDelimiterDescription()
{
    return (getSystemDelimiter() == ',') ? QStringLiteral("Comma") : QStringLiteral("Semi colon");
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read cells --- //
bool SpreadsheetFileCSV::read(QVector<QVector<QVariant>> &cells, const qint32 &headerCount)
{
    // Progress window
    m_ProgressDialog.set("Loading csv spreadsheet", m_File->size());

    // Detect the file delimiter
    QString dSample = m_File->read(256); // Read the first few characters rather than readLine() in case the line has no delimiter
    qint32 comma = dSample.count(',');
    qint32 semicolon = dSample.count(';');
    qint32 tab = dSample.count('\t');

    // Set delimiter to comma or semicolon according to which appears the most in the first line
    QChar d = (comma > semicolon) ? ',' : ';';

    // Use tab as a delimiter if there are more tabs than commas and semicolons
    if(tab > (comma + semicolon))
        d = '\t';

    // Return the stream to the beginning of the file
    m_File->seek(0);

    // Skip header rows
    for(unsigned char i = 0; i < headerCount; ++i)
        m_File->readLine();

    // Read data rows
    while(!m_File->atEnd())
    {
        // Progress
        m_ProgressDialog.increment(m_File->pos());

        // Buffer line
        QString row = QString::fromLatin1(m_File->readLine());  // Read from Latin-1

        // Remove any text qualifiers (i.e. speech marks)
        row.remove(QChar(0x22));

        // Parse the row and add it to the string list
        QStringList list = row.split(d);

        // Convert the list to a QVector<QString>
        QVector<QVariant> vect;
        const qint32 size = list.size();
        for(qint32 i = 0; i < size; ++i)
            vect.push_back(list[i].remove("\n"));   // Remove any new line characters

        cells.push_back(vect);
    }

    // Return true if at least on row was read
    return(cells.size() > 0);
}

// --- Write cells --- //
bool SpreadsheetFileCSV::writeCells(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &cells)
{
    // Progress window
    m_ProgressDialog.set("Saving csv spreadsheet", cells.size());

    // Delimiter
    QChar d = this->getSystemDelimiter();

    // Validate rows
    validate(prefix, d);
    validate(cells, d);

    const qint32 rowCount = cells.size();
    for(qint32 row = 0; row < rowCount; ++row)
    {
        // Progress
        m_ProgressDialog.increment();

        // Iterate over each prefix cell
        if(row < prefix.size())
        {
            const qint32 preCount = prefix[row].size();
            for(qint32 col = 0; col < preCount; ++col)
            {
                m_File->write(prefix[row][col].toString().toLatin1());
                m_File->write(reinterpret_cast<char*>(&d), 1);
            }
        }

        // Iterate over each cell
        const qint32 colCount = cells[row].size()-1; // Subtract 1 as the final element will be added after the loop
        for(qint32 col = 0; col < colCount; ++col) {
            m_File->write(cells[row][col].toString().toLatin1());
            m_File->write(reinterpret_cast<char*>(&d), 1);
        }

        // Add final cell
        m_File->write(cells[row][colCount].toString().toLatin1());
        m_File->write("\n");
    }

    return true;
}

// --- Write header cells --- //
bool SpreadsheetFileCSV::writeHeader(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &header)
{
    // Delimiter
    QChar d = this->getSystemDelimiter();

    // Validate rows
    validate(prefix, d);
    validate(header, d);

    const qint32 rowCount = header.size();
    for(qint32 row = 0; row < rowCount; ++row) {

        // Iterate over each prefix header cell
        if(row < prefix.size())
        {
            const qint32 preCount = prefix[row].size();
            for(qint32 col = 0; col < preCount; ++col)
            {
                m_File->write(prefix[row][col].toString().toLatin1());
                m_File->write(reinterpret_cast<char*>(&d), 1);
            }
        }

        // Iterate over each header cell
        const qint32 colCount = header[row].size()-1; // Subtract 1 as the final element will be added after the loop
        for(qint32 col = 0; col < colCount; ++col) {
            m_File->write(header[row][col].toString().toLatin1());
            m_File->write(reinterpret_cast<char*>(&d), 1);
        }

        // Add final cell
        m_File->write(header[row][colCount].toString().toLatin1());
        m_File->write("\n");
    }

    return true;
}


/* ==================== */
/*      Validation      */
/* ==================== */

// --- Validate cells --- //
void SpreadsheetFileCSV::validate(QVector<QVector<QVariant>> &cells, const QChar &delimiter)
{
    const qint32 rows = cells.size();

    for(qint32 r = 0; r < rows; ++r) {
        const qint32 cols = cells[r].size();

        for(qint32 c = 0; c < cols; ++c) {
            // Encapsulate cells containing delimiter text with speechmarks
            if(cells[r][c].toString().contains(delimiter))
            {
                cells[r][c].toString().prepend("\"");
                cells[r][c].toString().append("\"");
            }

            // Replace/remove special characters
            cells[r][c].toString().remove(0x2122); // Trademark
        }
    }
}
