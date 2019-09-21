#ifndef NATION_H
#define NATION_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/double.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Nation data --- //
class Nation : public SchemaBaseClass
{
private:
    String Name;
    Char GenderName;
    String NameShort;
    Char GenderNameShort;
    String NameThreeLetter;
    String NameNationality;
    Int Continent;
    Char Region;
    Char ActualRegion;
    Char FirstLanguage;
    Char SecondLanguage;
    Char ThirdLanguage;
    Int CapitalCity;
    Char StateOfDevelopment;
    Char GroupMembership;
    Int NationalStadium;
    Char GameImportance;
    Char LeagueStandard;
    Short NumberClubs;
    Int NumberStaff; // Version 0x02 - Added
    Short SeasonUpdateDay; // Version 0x02 - Added
    Short Reputation; // Version 0x02 - Changed char->short
    Int ForegroundColour1;
    Int BackgroundColour1;
    Int ForegroundColour2;
    Int BackgroundColour2;
    Int ForegroundColour3;
    Int BackgroundColour3;
    Double FIFACoefficient;
    Double FIFACoefficient91;
    Double FIFACoefficient92;
    Double FIFACoefficient93;
    Double FIFACoefficient94;
    Double FIFACoefficient95;
    Double FIFACoefficient96;
    Double UEFACoefficient91;
    Double UEFACoefficient92;
    Double UEFACoefficient93;
    Double UEFACoefficient94;
    Double UEFACoefficient95;
    Double UEFACoefficient96;
    Int Rivals1;
    Int Rivals2;
    Int Rivals3;

    // Runtime data
    Char LeagueSelected;
    Int ShortlistOffset; // Version 0x02 - Added
    Char GamesPlayed; // Version 0x02 - Moved to runtime

    // Friend classes
    friend class NationData;
    friend class NationModel;

public:
    // Constructor
    Nation();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QString getName();
};

#endif // NATION_H
