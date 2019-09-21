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
#include "../data_types/u_char.h"
#include "../pointer/ptr_common_name.h"
#include "../pointer/ptr_first_name.h"
#include "../pointer/ptr_second_name.h"
#include "../pointer/ptr_nation.h"
#include "schema_base_class.h"

// --- Staff Data --- //
class Staff : public SchemaBaseClass
{
private:
    // Extra data
    QString m_DisplayText;

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
    Int NationContracted;
    Char JobForNation;
    Date DateJoinedNation;
    Date ContractExpiresNation;
    Int ClubContracted;
    Char JobForClub;
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
    Attribute PlayingSquad;
    Attribute Classification;
    Attribute ClubValuation;
    Int PlayerData;
    Int Preferences; // Version 0x02 - New ptr type
    Int NonPlayerData;

    // Runtime data
    Char EuroSquadFlag;

    // Friend classes
    friend class StaffModel;
    friend class StaffData;

    // Set data
    void setDisplayText();
    void setIdentifier();

public:
    // Constructor
    Staff();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QString getDisplayText();
};

#endif // STAFF_H
