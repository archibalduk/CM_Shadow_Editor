#include "database.h"

// Qt headers
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QSettings>

// Application headers
#include "../db_containers/non_player_data.h"
#include "../db_containers/player_data.h"
#include "../db_containers/staff_preferences_data.h"
#include "history_manager.h"

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
    ProgressDialog *progress = new ProgressDialog("Opening database", 0, 24);

    // Temporary containers
    NonPlayerData nonplayers;
    PlayerData players;
    StaffPreferencesData preferences;

    // Read the index first
    this->read(progress, path, "index.dat", index);

    // Read the rest of the database
    this->read(progress, path, "city.dat", cities);
    this->read(progress, path, "club.dat", "nat_club.dat", clubs);
    this->read(progress, path, "club_comp.dat", "nation_comp.dat", clubComps);
    this->read(progress, path, "colour.dat", colours);
    this->read(progress, path, "continent.dat", continents);
    this->read(progress, path, "common_names.dat", commonNames);
    this->read(progress, path, "first_names.dat", firstNames);
    this->read(progress, path, "second_names.dat", secondNames);
    this->read(progress, path, "nation.dat", nations);
    this->read(progress, path, "officials.dat", officials);
    this->read(progress, path, "stadium.dat", stadia);
    this->read(progress, path, "staff.dat", staff,
               index.Data[IndexData::STAFF_TABLE].getOffset(),
               index.Data[IndexData::STAFF_TABLE].getRecordCount());
    this->read(progress, path, "staff.dat", nonplayers,
               index.Data[IndexData::NON_PLAYER_TABLE].getOffset(),
               index.Data[IndexData::NON_PLAYER_TABLE].getRecordCount());
    this->read(progress, path, "staff.dat", players,
               index.Data[IndexData::PLAYER_TABLE].getOffset(),
               index.Data[IndexData::PLAYER_TABLE].getRecordCount());
    this->read(progress, path, "staff.dat", preferences,
               index.Data[IndexData::STAFF_PREFERENCES_TABLE].getOffset(),
               index.Data[IndexData::STAFF_PREFERENCES_TABLE].getRecordCount());
    this->read(progress, path, "staff_comp.dat", staffComps);

    // Read the history data
    HistoryManager<ClubCompHistory, ClubComp> mgrClubCompHistory(clubComps.Data);
    mgrClubCompHistory.read(progress, path, "club_comp_history.dat");
    mgrClubCompHistory.read(progress, path, "nation_comp_history.dat");

    HistoryManager<StaffCompHistory, StaffComp> mgrStaffCompHistory(staffComps.Data);
    mgrStaffCompHistory.read(progress, path, "staff_comp_history.dat");

    HistoryManager<StaffHistory, Staff> mgrStaffHistory(staff.Data);
    mgrStaffHistory.read(progress, path, "staff_history.dat");

    // Process staff data
    progress->increment("Assigning staff data");
    staff.transferToDatabase(nonplayers, players, preferences);

    progress->reset();
    delete progress;
    return true;
}

// --- Read .dat file/table (Database Container: Standard/single file) --- //
template<typename T1, typename T2> bool Database::read(ProgressDialog *progress, const QString &path, const QString &fileName,
                                                       DatabaseContainer<T1, T2> &container,
                                                       const qint32 &offset, const qint32 &count)
{
    progress->increment(fileName);

    // Open the file (read only)
    QFile file(QString("%1/%2").arg(path).arg(fileName));
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << QString("Unable to open %1").arg(file.fileName());
        return false;
    }

    // Data stream
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.skipRawData(offset);

    // Read the data
    /*const qint32 result = */container.read(in, m_Version, count);

    file.close();
    return true;
}

// --- Read .dat file/table (Database Container: Domestic and international data) --- //
template<typename T1, typename T2> bool Database::read(ProgressDialog *progress, const QString &path,
                                                       const QString &fileNameDomestic, const QString &fileNameInternational,
                                                       DatabaseContainer<T1, T2> &container,
                                                       const qint32 &offset, const qint32 &count)
{
    bool result = true;

    // Domestic data
    container.setNextItemsAsDomestic();
    if(this->read(progress, path, fileNameDomestic, container, offset, count) == false)
        result = false;

    // International data
    container.setNextItemsAsInternational();
    if(this->read(progress, path, fileNameInternational, container, offset, count) == false)
        result = false;

    // Default back to domestic
    container.setNextItemsAsDomestic();

    return result;
}

// --- Read .dat file/table (Simple Container) --- //
template<typename T> bool Database::read(ProgressDialog *progress, const QString &path, const QString &fileName,
                                         SimpleContainer<T> &container,
                                         const qint32 &offset, const qint32 &count)
{
    progress->increment(fileName);

    // Open the file (read only)
    QFile file(QString("%1/%2").arg(path).arg(fileName));
    if(!file.open(QIODevice::ReadOnly)) {
        qCritical() << QString("Unable to open %1").arg(file.fileName());
        return false;
    }

    // Data stream
    QDataStream in(&file);
    in.setByteOrder(QDataStream::LittleEndian);
    in.skipRawData(offset);

    // Read the data
    /*const qint32 result = */container.read(in, m_Version, count);

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
    ProgressDialog *progress = new ProgressDialog("Saving database", 0, 23);

    // Write each table of the database to the .dat files and update index.dat at the same time
    this->write(progress, path, "city.dat", cities, IndexData::CITY_TABLE);
    this->write(progress, path, "club.dat", clubs, IndexData::CLUB_TABLE);
    this->write(progress, path, "nat_club.dat", clubs, IndexData::NATION_CLUBS_TABLE, false);
    this->write(progress, path, "club_comp.dat", clubComps, IndexData::CLUB_COMP_TABLE);
    this->write(progress, path, "nation_comp.dat", clubComps, IndexData::NATION_COMP_TABLE, false);
    this->write(progress, path, "colour.dat", colours, IndexData::COLOUR_TABLE);
    this->write(progress, path, "continent.dat", continents, IndexData::CONTINENT_TABLE);
    this->write(progress, path, "common_names.dat", commonNames, IndexData::COMMON_NAME_TABLE);
    this->write(progress, path, "first_names.dat", firstNames, IndexData::FIRST_NAME_TABLE);
    this->write(progress, path, "second_names.dat", secondNames, IndexData::SECOND_NAME_TABLE);
    this->write(progress, path, "nation.dat", nations, IndexData::NATION_TABLE);
    this->write(progress, path, "officials.dat", officials, IndexData::OFFICIALS_TABLE);
    this->write(progress, path, "stadium.dat", stadia, IndexData::STADIUM_TABLE);
    this->write(progress, path, "staff.dat", staff, IndexData::STAFF_TABLE);
    this->write(progress, path, "staff.dat", staff, &StaffData::writeNonPlayerData,
                QIODevice::Append, IndexData::NON_PLAYER_TABLE);
    this->write(progress, path, "staff.dat", staff, &StaffData::writePlayerData,
                QIODevice::Append, IndexData::PLAYER_TABLE);
    this->write(progress, path, "staff.dat", staff, &StaffData::writePreferencesData,
                QIODevice::Append, IndexData::STAFF_PREFERENCES_TABLE);
    this->write(progress, path, "staff_comp.dat", staffComps, IndexData::STAFF_COMP_TABLE);

    // Write the history data
    HistoryManager<ClubCompHistory, ClubComp> mgrClubCompHistory(clubComps.Data);
    mgrClubCompHistory.write(progress, path, "club_comp_history.dat", true);
    index.setCount(IndexData::CLUB_COMP_HISTORY_TABLE, mgrClubCompHistory.size());
    mgrClubCompHistory.write(progress, path, "nation_comp_history.dat", false);
    index.setCount(IndexData::NATION_COMP_HISTORY_TABLE, mgrClubCompHistory.size());

    HistoryManager<StaffCompHistory, StaffComp> mgrStaffCompHistory(staffComps.Data);
    mgrStaffCompHistory.write(progress, path, "staff_comp_history.dat");
    index.setCount(IndexData::STAFF_COMP_HISTORY_TABLE, mgrStaffCompHistory.size());

    HistoryManager<StaffHistory, Staff> mgrStaffHistory(staff.Data);
    mgrStaffHistory.write(progress, path, "staff_history.dat");
    index.setCount(IndexData::STAFF_HISTORY_TABLE, mgrStaffHistory.size());

    // Write index.dat last
    this->write(progress, path, "index.dat", index);

    progress->reset();
    delete progress;
    return true;
}

// --- Write .dat file/table (Database Container: Standard/single file) --- //
template<typename T1, typename T2> bool Database::write(ProgressDialog *progress, const QString &path, const QString &fileName,
                    DatabaseContainer<T1, T2> &container, const qint32 &tableId, const bool &domestic)
{
    progress->increment(fileName);

    // Open the file
    QFile file(QString("%1/%2").arg(path).arg(fileName));

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qCritical() << QString("Unable to save (truncate) %1").arg(file.fileName());
        return false;
    }

    // Data stream
    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);

    // Write the data
    const qint32 count = container.write(out, domestic);

    // Update the index
    index.setCount(tableId, count);

    file.close();
    return true;
}

// --- Write .dat file/table (Special tables - pass write function by reference) --- //
template<typename T> bool Database::write(ProgressDialog *progress, const QString &path, const QString &fileName,
                     T &container, qint32 (T::*fnWrite)(QDataStream &, const bool &),
                     const QIODevice::OpenModeFlag &method, const qint32 &tableId, const bool &domestic)
{
    progress->increment(fileName);

    // Open the file
    QFile file(QString("%1/%2").arg(path).arg(fileName));

    if(!file.open(QIODevice::WriteOnly | method)) {
        qCritical() << QString("Unable to save (%1) %2").arg(method).arg(file.fileName());
        return false;
    }

    // Data stream
    QDataStream out(&file);
    out.setByteOrder(QDataStream::LittleEndian);

    // Get offset of first byte to be written
    const qint32 pos = static_cast<qint32>(out.device()->pos());

    // Write the data
    const qint32 count = (container.*fnWrite)(out, domestic);

    // Update the index
    index.setCount(tableId, count, pos);

    file.close();
    return true;
}
