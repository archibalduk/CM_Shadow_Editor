#ifndef OFFICIAL_H
#define OFFICIAL_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/attribute.h"
#include "../data_types/date.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "../pointer/ptr_first_name.h"
#include "../pointer/ptr_second_name.h"
#include "schema_base_class.h"

// --- Official data --- //
class Official : public SchemaBaseClass
{
private:
    PtrFirstName FirstName;
    PtrSecondName SecondName;
    Date DateOfBirth;
    Short YearOfBirth;
    Int Nation;
    Int City;
    Short CurrentAbility;
    Short PotentialAbility;
    Short Reputation;
    Attribute AllowingFlow;
    Attribute Discipline;
    Attribute ImportantMatches;
    Attribute Pressure;
    Attribute Refereeing;
    Attribute RunningLine;
    Attribute Timekeeping;

    // Friend classes
    friend class OfficialData;
    friend class OfficialModel;

public:
    // Constructor
    Official();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // OFFICIAL_H
