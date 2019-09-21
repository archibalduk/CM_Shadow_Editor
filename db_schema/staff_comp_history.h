#ifndef STAFF_COMP_HISTORY_H
#define STAFF_COMP_HISTORY_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../pointer/ptr_first_name.h"
#include "../pointer/ptr_second_name.h"
#include "schema_base_class.h"

// --- Staff competition/award history data --- //
class StaffCompHistory : public SchemaBaseClass
{
private:
    Int StaffComp;
    Short Year;
    PtrFirstName FirstPlacedFirstName;
    PtrSecondName FirstPlacedSecondName;
    Int FirstPlacedIndex;
    Int FirstPlacedInfo;
    PtrFirstName SecondPlacedFirstName;
    PtrSecondName SecondPlacedSecondName;
    Int SecondPlacedIndex;
    Int SecondPlacedInfo;
    PtrFirstName ThirdPlacedFirstName;
    PtrSecondName ThirdPlacedSecondName;
    Int ThirdPlacedIndex;
    Int ThirdPlacedInfo;

public:
    // Constructor
    StaffCompHistory();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // STAFF_COMP_HISTORY_H
