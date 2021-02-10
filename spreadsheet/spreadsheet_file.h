#ifndef SPREADSHEET_FILE_H
#define SPREADSHEET_FILE_H

// Qt headers
#include <QFile>
#include <QVariant>
#include <QVector>

// Application header
#include "../ui/progress_dialog.h"

// --- Spreadsheet file base class --- //
class SpreadsheetFile
{
protected:
    // A digit (\d), zero or more times (*)
    static const QRegExp s_Numerical;

    // Stream
    QFile *m_File;

    // Header row count
    qint32 m_HeaderCount;

    // Progress dialog
    bool m_HideProgress;
    ProgressDialog m_ProgressDialog;

public:
    // Constructor
    SpreadsheetFile();
    SpreadsheetFile(QFile &file);

    // Destructor
    virtual ~SpreadsheetFile();

    // File I/O
    virtual bool read(QVector<QVector<QVariant>> &cells, const qint32 &headerCount = 0);
    virtual bool writeCells(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &cells);
    virtual bool writeHeader(QVector<QVector<QVariant>> &prefix, QVector<QVector<QVariant>> &header);

    // Set silent
    void setSilent(const bool silent);
};

#endif // SPREADSHEET_FILE_H
