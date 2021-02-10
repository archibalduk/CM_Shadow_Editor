#include "staff_data.h"


/* ============================== */
/*      Staff Database Table      */
/* ============================== */

// --- Default constructor --- //
StaffData::StaffData() :
    DatabaseContainer<Staff, StaffModel>()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Write non-player data --- //
qint32 StaffData::writeNonPlayerData(QDataStream &out, const bool &)
{
    qint32 count = 0;
    const qint32 size = Data.size();

    // Write each record
    for(qint32 i = 0; i < size; ++i) {
        if(Data[i].NonPlayerData_Id.isPointer()) {
            Data[i].nonplayer.write(out);
            ++count;
        }
    }

    return count;
}

// --- Write player data --- //
qint32 StaffData::writePlayerData(QDataStream &out, const bool &)
{
    qint32 count = 0;
    const qint32 size = Data.size();

    // Write each record
    for(qint32 i = 0; i < size; ++i) {
        if(Data[i].PlayerData_Id.isPointer()) {
            Data[i].player.write(out);
            ++count;
        }
    }

    return count;
}

// --- Write staff preferences data --- //
qint32 StaffData::writePreferencesData(QDataStream &out, const bool &)
{
    const qint32 size = Data.size();

    // Write each record
    for(qint32 i = 0; i < size; ++i) {
        Data[i].preferences.write(out);
    }

    return size;
}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void StaffData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool StaffData::sortMethod(const Staff &a, const Staff &b)
{
    if(a.SecondNameId.get() != b.SecondNameId.get())
        return a.SecondNameId.get() < b.SecondNameId.get();

    else if(a.FirstNameId.get() != b.FirstNameId.get())
        return a.FirstNameId.get() < b.FirstNameId.get();

    else if(a.CommonNameId.get() != b.CommonNameId.get())
        return a.CommonNameId.get() < b.CommonNameId.get();

    else if(a.Nation.get() != b.Nation.get())
        return a.Nation.get() < b.Nation.get();

    else return(a.ID.get() < b.ID.get());
}


/* ======================= */
/*      Transfer Data      */
/* ======================= */

// --- Transfer data to the database --- //
void StaffData::transferToDatabase(NonPlayerData &nonPlayerData, PlayerData &playerData, StaffPreferencesData &preferencesData)
{
    const qint32 nonPlayerSize = nonPlayerData.size();
    const qint32 playerSize = playerData.size();
    const qint32 preferencesSize = preferencesData.size();
    const qint32 staffSize = Data.size();

    for(qint32 i = 0; i < staffSize; ++i) {

        Staff &staff = Data[i];
        const qint32 nonPlayerId = staff.NonPlayerData_Id.get();
        const qint32 playerId = staff.PlayerData_Id.get();
        const qint32 preferencesId = staff.Preferences_Id.get();

        // Non-player data
        if(nonPlayerId >= 0 && nonPlayerId < nonPlayerSize)
            staff.nonplayer = nonPlayerData.Data[nonPlayerId];

        // Player data
        if(playerId >= 0 && playerId < playerSize)
            staff.player = playerData.Data[playerId];

        // Preference data
        if(preferencesId >= 0 && preferencesId < preferencesSize)
            staff.preferences = preferencesData.Data[preferencesId];
    }
}
