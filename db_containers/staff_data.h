#ifndef STAFF_DATA_H
#define STAFF_DATA_H

// Application headers
#include "../db_containers/non_player_data.h"
#include "../db_containers/player_data.h"
#include "../db_containers/staff_preferences_data.h"
#include "../db_schema/staff.h"
#include "../model/staff_model.h"
#include "database_container.h"

// --- Staff database table --- //
class StaffData : public DatabaseContainer<Staff, StaffModel>
{
public:
    // Constructor
    StaffData();

    // File I/O
    qint32 writeNonPlayerData(QDataStream &out, const bool &/*domestic*/);
    qint32 writePlayerData(QDataStream &out, const bool &/*domestic*/);
    qint32 writePreferencesData(QDataStream &out, const bool &/*domestic*/);

    // Transfer data
    void transferToDatabase(NonPlayerData &nonPlayerData, PlayerData &playerData, StaffPreferencesData &preferencesData);

private:
    // Sort data
    void sortData();
    static bool sortMethod(const Staff &a, const Staff &b);
};

#endif // STAFF_DATA_H
