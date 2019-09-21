#ifndef DATABASE_H
#define DATABASE_H

// Qt headers
#include <QDataStream>
#include <QObject>
#include <QString>
#include <QWidget>

// Application headers
#include "../ui/progress_dialog.h"
#include "version.h"

// Database headers
#include "../db_containers/database_container.h"
#include "../db_containers/city_data.h"
#include "../db_containers/club_comp_data.h"
#include "../db_containers/club_data.h"
#include "../db_containers/colour_data.h"
#include "../db_containers/continent_data.h"
#include "../db_containers/index_data.h"
#include "../db_containers/name_data.h"
#include "../db_containers/nation_data.h"
#include "../db_containers/official_data.h"
#include "../db_containers/stadium_data.h"
#include "../db_containers/staff_comp_data.h"
#include "../db_containers/staff_data.h"

// Model headers (for templated classes only)
#include "../model/common_name_model.h"
#include "../model/first_name_model.h"
#include "../model/second_name_model.h"

// --- Database interface --- //
class Database : public QObject
{
    Q_OBJECT

private:
    // File I/O - Read
    bool openDatabase(const QString &path);
    template<typename T1, typename T2>  bool read(ProgressDialog *progress, const QString &path, const QString &fileName,
                                                  DatabaseContainer<T1, T2> *container, const qint32 &offset = 0, const qint32 &count = -1);

    // File I/O - Write
    bool saveDatabase(const QString &path);
    template<typename T1, typename T2>  bool write(ProgressDialog *progress, const QString &path, const QString &fileName,
                                                  DatabaseContainer<T1, T2> *container, const bool &truncateFile = true);

    // Version
    Version m_Version;

signals:
    // Model
    void beginResetModel();
    void endResetModel();

public:
    // Constructor
    Database();
    virtual ~Database();

    // File I/O - Read
    bool open(QWidget *parent = nullptr);

    // File I/O - Write
    bool saveAs(QWidget *parent = nullptr);
    bool save();

    // Database data
    static CityData cities;
    static ClubCompData clubComps;
    static ClubData clubs;
    static ColourData colours;
    static ContinentData continents;
    static IndexData index;
    static NameData<CommonNameModel> commonNames;
    static NameData<FirstNameModel> firstNames;
    static NameData<SecondNameModel> secondNames;
    static NationData nations;
    static OfficialData officials;
    static StadiumData stadia;
    static StaffCompData staffComps;
    static StaffData staff;
};

#endif // DATABASE_H
