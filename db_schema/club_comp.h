#ifndef CLUB_COMP_H
#define CLUB_COMP_H

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Club competition data --- //
class ClubComp : public SchemaBaseClass
{
private:
    // Data
    String Name;
    Char GenderName;
    String NameShort;
    Char GenderNameShort;
    String NameThreeLetter;
    Char Scope;
    Char Selected;
    Int Continent;
    Int Nation;
    Int ForegroundColour;
    Int BackgroundColour;
    Short Reputation; // Version 0x02 - Changed char->short

    // Friend classes
    friend class ClubCompData;
    friend class ClubCompModel;

public:
    // Constructor
    ClubComp();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // CLUB_COMP_H
