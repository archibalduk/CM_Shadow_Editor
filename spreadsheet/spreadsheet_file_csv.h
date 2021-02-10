#ifndef SPREADSHEET_FILE_CSV_H
#define SPREADSHEET_FILE_CSV_H

// Application headers
#include "spreadsheet_file.h"

// --- CSV spreadsheet --- //
class SpreadsheetFileCSV : public SpreadsheetFile
{
private:
    // Delimiter
    static QChar getSystemDelimiter();

    // Validation
    static void validate(QVector<QVector<QVariant>> &cells, const QChar &delimiter);

public:
    // Constructor
    SpreadsheetFileCSV();
    SpreadsheetFileCSV(QFile &file);

    // Delimiter
    static QString getSystemDelimiterDescription();

    // File I/O
    bool read(QVector<QVector<QVariant>> &cells, const qint32 &headerCount = 0);
    bool writeCells(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &cells);
    bool writeHeader(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &header);
};

#endif // SPREADSHEET_FILE_CSV_H
