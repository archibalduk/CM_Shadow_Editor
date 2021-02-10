#ifndef SPREADSHEET_H
#define SPREADSHEET_H

// Qt Headers
#include <QHash>
#include <QString>
#include <QTextStream>
#include <QVariant>
#include <QVector>

// Applicaion headers
#include "spreadsheet_file.h"

// --- Spreadsheet interface class --- //
class Spreadsheet
{
private:
    // Spreadsheet data
    QVector<QVector<QVariant>> m_Cells;
    QVector<QVector<QVariant>> m_CellsPrefix;
    QVector<QVector<QVariant>> m_Header;
    QVector<QVector<QVariant>> m_HeaderPrefix;

    unsigned char m_HeaderCount;

    // File extension (functions)
    QString fileExtensionText();
    QString fileExtensionList(const bool &mergedList = true);
    static void initFileExtensions();
    static const QString filter(const quint8 &type);

    // File extension (members)
    static QHash<QString, unsigned char> s_FileExtensions;

    enum ENUM_FILE_EXTENSIONS {
        CSV,
        TXT,
        XLSX,
        FILE_EXTENSION_COUNT
    };

    // File details
    unsigned char m_FileExtension;
    QString m_FileName;
    QString m_Title;

    // Folder details
    QString m_Path;

    // Progress display
    bool m_HideProgress;

    // Spreadsheet file
    SpreadsheetFile *newSpreadsheet(QFile &f);

public:
    // Constructor
    Spreadsheet();

    // Destructor
    ~Spreadsheet();

    // File details
    const QString file();
    const QString fileName();
    const QString identifier();
    bool setFile(const QString &path);
    void setFileName(const QString &name);

    // File extension
    static qint32 getDefaultFileExtension();
    static void setDefaultFileExtension(const qint32 &i);

    // File I/O
    bool open(const QString &folder, const QString &filename);
    bool read();
    bool save(const QString &folder, const QString &filename);
    bool write();

    // File I/O dialog windows
    bool showOpenDialog(QString path = "");
    bool showSaveDialog(const QString &filename = "output.csv", QString path = "");

    // Progress display
    void setSilent(const bool &silent = true);

    // Add cell data
    void add();
    void add(const QVariant &data);
    void addNewRow();
    void addNewRow(const QStringList &list);

    // Add header data
    void addHeader(const QVariant &data);
    void addNewHeaderRow();
    void addNewHeaderRow(const QStringList &list);

    // Get cell data
    QVariant cell(const qint32 &row, const qint32 &col);
    const QVector<QVariant> *row(const qint32 &row);
    qint32 rowCount();

    // Get header data
    const QVector<QVariant> *header(const qint32 &row);
    QVariant headerCell(const qint32 &row, const quint16 &col);
    qint32 headerCount();

    // Get settings
    static QString exportPath();
    static QString importPath();

    // Set cell data
    void set(const QVariant &data, const qint32 &row, const quint16 &col);

    // Set header data
    void setHeader(const QVariant &data, const qint32 &row, const quint16 &col);
    void setHeaderColumnCount(const quint8 &count, const qint32 &row = -1);
    void setHeaderRowCount(const quint8 &count);

    // Set header span data
    void setSpannedHeader(const QVariant &data, const quint16 &col, const quint16 &span);
};

#endif // SPREADSHEET_H
