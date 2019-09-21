#include "nation.h"

/* ================= */
/*      Nations      */
/* ================= */

// --- Default constructor -- //
Nation::Nation()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void Nation::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    GenderName.read(in);
    NameShort.read(in, String::SHORT_TEXT_LENGTH);
    GenderNameShort.read(in);
    NameThreeLetter.read(in, String::THREE_LETTER_LENGTH);
    NameNationality.read(in, String::SHORT_TEXT_LENGTH);
    Continent.read(in);
    Region.read(in);
    ActualRegion.read(in);
    FirstLanguage.read(in);
    SecondLanguage.read(in);
    ThirdLanguage.read(in);
    CapitalCity.read(in);
    StateOfDevelopment.read(in);
    GroupMembership.read(in);
    NationalStadium.read(in);
    GameImportance.read(in);
    LeagueStandard.read(in);
    NumberClubs.read(in);
    NumberStaff.read(in);
    SeasonUpdateDay.read(in);
    Reputation.read(in);
    ForegroundColour1.read(in);
    BackgroundColour1.read(in);
    ForegroundColour2.read(in);
    BackgroundColour2.read(in);
    ForegroundColour3.read(in);
    BackgroundColour3.read(in);
    FIFACoefficient.read(in);
    FIFACoefficient91.read(in);
    FIFACoefficient92.read(in);
    FIFACoefficient93.read(in);
    FIFACoefficient94.read(in);
    FIFACoefficient95.read(in);
    FIFACoefficient96.read(in);
    UEFACoefficient91.read(in);
    UEFACoefficient92.read(in);
    UEFACoefficient93.read(in);
    UEFACoefficient94.read(in);
    UEFACoefficient95.read(in);
    UEFACoefficient96.read(in);
    Rivals1.read(in);
    Rivals2.read(in);
    Rivals3.read(in);
    LeagueSelected.read(in);
    ShortlistOffset.read(in);
    GamesPlayed.read(in);
}

// --- Write data --- //
void Nation::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    GenderName.write(out);
    NameShort.write(out, String::SHORT_TEXT_LENGTH);
    GenderNameShort.write(out);
    NameThreeLetter.write(out, String::THREE_LETTER_LENGTH);
    NameNationality.write(out, String::SHORT_TEXT_LENGTH);
    Continent.write(out);
    Region.write(out);
    ActualRegion.write(out);
    FirstLanguage.write(out);
    SecondLanguage.write(out);
    ThirdLanguage.write(out);
    CapitalCity.write(out);
    StateOfDevelopment.write(out);
    GroupMembership.write(out);
    NationalStadium.write(out);
    GameImportance.write(out);
    LeagueStandard.write(out);
    NumberClubs.write(out);
    NumberStaff.write(out);
    SeasonUpdateDay.write(out);
    Reputation.write(out);
    ForegroundColour1.write(out);
    BackgroundColour1.write(out);
    ForegroundColour2.write(out);
    BackgroundColour2.write(out);
    ForegroundColour3.write(out);
    BackgroundColour3.write(out);
    FIFACoefficient.write(out);
    FIFACoefficient91.write(out);
    FIFACoefficient92.write(out);
    FIFACoefficient93.write(out);
    FIFACoefficient94.write(out);
    FIFACoefficient95.write(out);
    FIFACoefficient96.write(out);
    UEFACoefficient91.write(out);
    UEFACoefficient92.write(out);
    UEFACoefficient93.write(out);
    UEFACoefficient94.write(out);
    UEFACoefficient95.write(out);
    UEFACoefficient96.write(out);
    Rivals1.write(out);
    Rivals2.write(out);
    Rivals3.write(out);
    LeagueSelected.write(out);
    ShortlistOffset.write(out);
    GamesPlayed.write(out);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Name --- //
QString Nation::getName()
{
    return Name.get();
}
