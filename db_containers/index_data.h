#ifndef INDEX_DATA_H
#define INDEX_DATA_H

// Qt headers
#include <QAbstractTableModel>

// Application headers
#include "../db_schema/index.h"
#include "../model/index_model.h"
#include "database_container.h"

// --- Index database table --- //
class IndexData : public DatabaseContainer<Index, IndexModel>
{
public:
    // Constructor
    IndexData();

    // File I/O
    qint32 read(QDataStream &in, Version &version, const qint32 &/*count*/);

    // Index header
    enum ENUM_HEADER_SIZE { INDEX_HEADER_SIZE = 8 };

    enum ENUM_INDEX_POSITIONS {
        CLUB_TABLE,
        NATION_CLUBS_TABLE,
        COLOUR_TABLE,
        CONTINENT_TABLE,
        NATION_TABLE,
        OFFICIALS_TABLE,
        STADIUM_TABLE,
        STAFF_TABLE,
        //YOUTH_PLAYER_TABLE = 8, // Not used
        NON_PLAYER_TABLE,
        PLAYER_TABLE,
        STAFF_COMP_TABLE,
        CITY_TABLE,
        CLUB_COMP_TABLE,
        NATION_COMP_TABLE,
        FIRST_NAME_TABLE,
        SECOND_NAME_TABLE,
        COMMON_NAME_TABLE,
        STAFF_HISTORY_TABLE,
        STAFF_COMP_HISTORY_TABLE,
        CLUB_COMP_HISTORY_TABLE,
        NATION_COMP_HISTORY_TABLE,
        STAFF_PREFERENCES_TABLE, // MUX with youth player table
        INDEX_TABLE_COUNT
    };

private:
    // Index header
    qint8 s_Header[INDEX_HEADER_SIZE];

    // Version
    qint32 findHighestVersion();
};

#endif // INDEX_DATA_H
