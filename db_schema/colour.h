#ifndef COLOUR_H
#define COLOUR_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/u_char.h"
#include "../data_types/int.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Colour data --- //
class Colour : public SchemaBaseClass
{
private:
    String Name;
    UChar RedIntensity;
    UChar GreenIntensity;
    UChar BlueIntensity;

    // Friend classes
    friend class ColourData;
    friend class ColourModel;

public:
    // Constructor
    Colour();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // COLOUR_H
