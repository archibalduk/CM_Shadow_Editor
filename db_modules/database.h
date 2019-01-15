#ifndef DATABASE_H
#define DATABASE_H

// Qt headers
#include <QDataStream>
#include <QString>
#include <QWidget>

// Application headers
#include "version.h"

// --- Database interface --- //
class Database
{
private:
    // File I/O
    bool openDatabase(const QString &path);
    bool read(const QString &path, const QString &fileName, qint32 (*fnRead)(QDataStream &, Version &), const qint32 &offset = 0);
    bool read(const QString &path, const QString &fileName, qint32 (*fnRead)(QDataStream &, Version &, const qint32 &), const qint32 &offset, const qint32 &count);

    // Version
    Version m_Version;

public:
    // Constructor
    Database();
    ~Database();

    // File I/O
    bool open(QWidget *parent = nullptr);
};

#endif // DATABASE_H
