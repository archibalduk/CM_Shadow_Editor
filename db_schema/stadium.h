#ifndef STADIUM_H
#define STADIUM_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Stadia data --- //
class Stadium : public SchemaBaseClass
{
private:
    String  Name;
    Char    GenderName;
    Int     City;
    Int     Capacity;
    Int     SeatingCapacity;
    Int     ExpansionCapacity;
    Int     NearbyStadium;
    Char    Covered;
    Char    UnderSoilHeating;

    // Friend classes
    friend class StadiumData;
    friend class StadiumModel;

public:
    // Constructor
    Stadium();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // STADIUM_H
