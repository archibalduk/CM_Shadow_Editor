#ifndef CLUB_COMP_HISTORY_H
#define CLUB_COMP_HISTORY_H

// Application headers
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "schema_base_class.h"

// --- Club competition history data --- //
class ClubCompHistory : public SchemaBaseClass
{
private:
    // Data
    Int Comp;
    Short Year;
    Int Winners;
    Int RunnersUp;
    Int ThirdPlaced;
    Int Hosts;

public:
    // Constructor
    ClubCompHistory();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // CLUB_COMP_HISTORY_H
