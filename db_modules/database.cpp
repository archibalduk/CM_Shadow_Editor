#include "database.h"

// Qt headers
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>

// --- Database data --- //
CityData Database::cities;
ClubCompData Database::clubComps;
ClubData Database::clubs;
ColourData Database::colours;
ContinentData Database::continents;
IndexData Database::index;
NameData<CommonNameModel> Database::commonNames;
NameData<FirstNameModel> Database::firstNames;
NameData<SecondNameModel> Database::secondNames;
NationData Database::nations;
OfficialData Database::officials;
StadiumData Database::stadia;
StaffCompData Database::staffComps;
StaffData Database::staff;


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


/* ======================== */
/*      File I/O - Read     */
/* ======================== */

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
    // Progress dialog
    ProgressDialog *progress = new ProgressDialog("Opening database", 0, 5);

    // Read the index first
    this->read(progress, path, "index.dat", &index, IndexData::INDEX_HEADER_SIZE);

    // Read the rest of the database
    this->read(progress, path, "city.dat", &cities);
    this->read(progress, path, "club.dat", &clubs);
    this->read(progress, path, "club_comp.dat", &clubComps);
    this->read(progress, path, "colour.dat", &colours);
    this->read(progress, path, "continent.dat", &continents);
    this->read(progress, path, "common_names.dat", &commonNames);
    this->read(progress, path, "first_names.dat", &firstNames);
    this->read(progress, path, "second_names.dat", &secondNames);
    this->read(progress, path, "nation.dat", &nations);
    this->read(progress, path, "officials.dat", &officials);
    this->read(progress, path, "stadium.dat", &stadia);
    this->read(progress, path, "staff.dat", &staff,
               index.Data[IndexData::STAFF_TABLE].getOffset(), index.Data[IndexData::STAFF_TABLE].getRecordCount());
    this->read(progress, path, "staff_comp.dat", &staffComps);

    progress->reset();
    delete progress;
    return true;
}

// --- Read .dat file/table --- //
template<typename T1, typename T2> bool Database::read(ProgressDialog *progress, const QString &path, const QString &fileName,
                    DatabaseContainer<T1, T2> *container,
                    const qint32 &offset, const qint32 &count)
{
    progress->increment(fileName);

    // Open the file (read only)
    QFile file(QString("%1/%2").arg(path).arg(fileName));
    if(!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    // Data stream
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.skipRawData(offset);

    // Read the data
    /*const qint32 result = */container->read(in, m_Version, count);

    file.close();
    return true;
}


/* ========================= */
/*      File I/O - Write     */
/* ========================= */

// --- Save the database without displaying a dialog window --- //
bool Database::save()
{
    QSettings settings;
    const QString path = settings.value("database_path", "").toString();

    if(path.isEmpty())
        return false;
    else
        return this->openDatabase(path);
}

// --- Display a dialog window and save the database --- //
bool Database::saveAs(QWidget *parent)
{
    QSettings settings;

    const QString path = QFileDialog::getSaveFileName(parent, QObject::tr("Save Database"),
                                                      QString("%1/index.dat").arg(settings.value("database_path", "C:/").toString()),
                                                      QStringLiteral("CM 01/02 Database (index.dat)"));

    // Sanity check (e.g. if user clicks on cancel)
    if(path.isEmpty())
        return false;

    // Parse the path to the selected index.dat file and save to the application settings
    const QFileInfo file(path);
    settings.setValue("database_path", file.path());

    return this->saveDatabase(file.path());
}

// --- Save database --- //
bool Database::saveDatabase(const QString &path)
{
    // Progress dialog
    ProgressDialog *progress = new ProgressDialog("Saving database", 0, 5);

    // Write each table of the database to the .dat files
    this->write(progress, path, "city.dat", &cities);
    this->write(progress, path, "club.dat", &clubs);
    this->write(progress, path, "club_comp.dat", &clubComps);
    this->write(progress, path, "colour.dat", &colours);
    this->write(progress, path, "continent.dat", &continents);
    this->write(progress, path, "common_names.dat", &commonNames);
    this->write(progress, path, "first_names.dat", &firstNames);
    this->write(progress, path, "second_names.dat", &secondNames);
    this->write(progress, path, "nation.dat", &nations);
    this->write(progress, path, "officials.dat", &officials);
    this->write(progress, path, "stadium.dat", &stadia);
    this->write(progress, path, "staff.dat", &staff);
    this->write(progress, path, "staff_comp.dat", &staffComps);

    progress->reset();
    delete progress;
    return true;
}

// --- Write .dat file/table --- //
template<typename T1, typename T2> bool Database::write(ProgressDialog *progress, const QString &path, const QString &fileName,
                    DatabaseContainer<T1, T2> *container, const bool &truncateFile)
{
    progress->increment(fileName);

    // Open the file
    QFile file(QString("%1/%2").arg(path).arg(fileName));

    if(truncateFile) {
        if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return false;
    }
    else {
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append))
            return false;
    }

    // Data stream
    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);

    // Read the data
    container->write(out);

    file.close();
    return true;
}
