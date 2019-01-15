#include "database.h"

// Qt headers
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>

// Application headers
#include "../db_containers/index_data.h"


/* ================== */
/*      Database      */
/* ================== */

// --- Default constructor --- //
Database::Database()
{

}

// --- Default destructor --- //
Database::~Database()
{
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Display a dialog window and open the database --- //
bool Database::open(QWidget *parent)
{
    QSettings settings;

    const QString path = QFileDialog::getOpenFileName(parent, QObject::tr("Open Database"),
                                                      settings.value("database_path", "C:/").toString(),
                                                      QStringLiteral("CM 01/02 Database (index.dat)"));

    // Sanity check (e.g. if user clicks on cancel)
    if(path.isEmpty())
        return false;

    // Parse the path to the selected index.dat file and save to the application settings
    const QFileInfo file(path);
    settings.setValue("database_path", file.path());

    return this->openDatabase(file.path());
}

// --- Open database --- //
bool Database::openDatabase(const QString &path)
{
    // Read the index first
    this->read(path, "index.dat", &IndexData::read, IndexData::INDEX_HEADER_SIZE);

    // Read the rest of the database
    //this->read(path, "common_names.dat", &CommonName::readAll);
    //this->read(path, "first_names.dat", &FirstName::readAll);
    //this->read(path, "second_names.dat", &SecondName::readAll);
    //this->read(path, "staff.dat", &Staff::readAll, Index::db[Index::STAFF_TABLE].getOffset(), Index::db[Index::STAFF_TABLE].getRecordCount());

    return true;
}

// --- Read .dat file/table --- //
bool Database::read(const QString &path, const QString &fileName, qint32 (*fnRead)(QDataStream &, Version &), const qint32 &offset)
{
    // Open the file (read only)
    QFile file(QString("%1/%2").arg(path).arg(fileName));
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    // Data stream
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.skipRawData(offset);

    // Read the data
    /*const qint32 result = */fnRead(in, m_Version);

    file.close();
    return true;
}

// --- Read .dat file/table (defined number of records) --- //
bool Database::read(const QString &path, const QString &fileName, qint32 (*fnRead)(QDataStream &, Version &, const qint32 &),
                    const qint32 &offset, const qint32 &count)
{
    // Open the file (read only)
    QFile file(QString("%1/%2").arg(path).arg(fileName));
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    // Data stream
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.skipRawData(offset);

    // Read the data
    /*const qint32 result = */fnRead(in, m_Version, count);

    file.close();
    return true;
}
