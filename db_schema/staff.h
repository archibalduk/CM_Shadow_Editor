#ifndef STAFF_H
#define STAFF_H

// Qt headers
#include <QDataStream>
#include <QString>

// Application headers
#include "../data_types/attribute.h"
#include "../data_types/char.h"
#include "../data_types/date.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "../data_types/u_char.h"
#include "../db_containers/staff_history_data.h"
#include "../pointer/ptr_club.h"
#include "../pointer/ptr_common_name.h"
#include "../pointer/ptr_first_name.h"
#include "../pointer/ptr_second_name.h"
#include "../pointer/ptr_nation.h"
#include "../value_pointer/ptr_job_for_club.h"
#include "../value_pointer/ptr_staff_classification.h"
#include "non_player.h"
#include "player.h"
#include "staff_history.h"
#include "staff_preferences.h"
#include "schema_base_class.h"

// --- Staff Data --- //
class Staff : public SchemaBaseClass
{
private:
    // Extra data
    QString m_DisplayText;

    // Name strings
    String FirstNameText;
    String SecondNameText;
    String CommonNameText;

    // Database data
    PtrFirstName FirstNameId;
    PtrSecondName SecondNameId;
    PtrCommonName CommonNameId;
    Date DateOfBirth;
    Short YearOfBirth;
    PtrNation Nation;
    PtrNation SecondNation;
    UChar InternationalApps;
    UChar InternationalGoals;
    PtrNation NationContracted;
    PtrJobForClub JobForNation;
    Date DateJoinedNation;
    Date ContractExpiresNation;
    PtrClub ClubContracted;
    PtrJobForClub JobForClub;
    Date DateJoinedClub;
    Date ContractExpiresClub;
    Int EstimatedWage;
    Int EstimatedValue;
    Attribute Adaptability;
    Attribute Ambition;
    Attribute Determination;
    Attribute Loyalty;
    Attribute Pressure;
    Attribute Professionalism;
    Attribute Sportsmanship;
    Attribute Temperament;
    Char PlayingSquad;
    PtrStaffClassification Classification;
    Attribute ClubValuation;

    // Pointers to linked data
    Int PlayerData_Id;
    Int Preferences_Id; // Version 0x02 - New ptr type
    Int NonPlayerData_Id;

    // Linked data
    NonPlayer nonplayer;
    Player player;
    StaffPreferences preferences;

    // History
    StaffHistoryData History;

    // Runtime data
    Char EuroSquadFlag;

    // Friend classes
    friend class StaffModel;
    friend class StaffData;

    // Set data
    void setDisplayText();
    void setIdentifier();
    void setNameCache();

public:
    // Constructor
    Staff();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QString getDisplayText();

    // History
    void addHistory(const StaffHistory &history);
    qint32 writeHistory(QDataStream &out, const bool &/*domestic*/);
};

#endif // STAFF_H
