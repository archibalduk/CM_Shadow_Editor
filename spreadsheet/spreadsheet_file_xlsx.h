#ifndef SPREADSHEET_FILE_XLSX_H
#define SPREADSHEET_FILE_XLSX_H

// Application headers
#include "spreadsheet_file.h"
#include "xlsx/header/xlsxdocument.h"

class SpreadsheetFileXLSX : public SpreadsheetFile
{
private:
    // File path (for QXlsx which cannot use the device)
    QString m_Filename;

    // Xlsx document
    QXlsx::Document *m_Xlsx;

public:
    // Constructor
    SpreadsheetFileXLSX();
    SpreadsheetFileXLSX(QFile &file, const QString &filename);

    // Destructor
    ~SpreadsheetFileXLSX();

    // File I/O
    bool read(QVector<QVector<QVariant>> &cells, const qint32 &headerCount = 0);
    bool writeCells(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &cells);
    bool writeHeader(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &header);
};

#endif // SPREADSHEET_FILE_XLSX_H
