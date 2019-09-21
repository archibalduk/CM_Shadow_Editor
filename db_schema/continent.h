#ifndef CONTINENT_H
#define CONTINENT_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/double.h"
#include "../data_types/int.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Continent data --- //
class Continent : public SchemaBaseClass
{
private:
    // Data
    String Name;
    Char GenderName;
    String NameThreeLetter;
    String NameContinentality;
    String FederationName;
    Char GenderFederationName;
    String FederationNameShort;
    Char GenderFederationNameShort;
    Double RegionalStrength;

    // Friend classes
    friend class ContinentData;
    friend class ContinentModel;

public:
    // Constructor
    Continent();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // CONTINENT_H
