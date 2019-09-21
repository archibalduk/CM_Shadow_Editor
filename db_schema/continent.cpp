#include "continent.h"

/* ==================== */
/*      Continents      */
/* ==================== */

// --- Default constructor -- //
Continent::Continent()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void Continent::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::SHORT_TEXT_LENGTH);
    GenderName.read(in);
    NameThreeLetter.read(in, String::THREE_LETTER_LENGTH);
    NameContinentality.read(in, String::SHORT_TEXT_LENGTH);
    FederationName.read(in, String::LONG_TEXT_LENGTH);
    GenderFederationName.read(in);
    FederationNameShort.read(in, String::SHORT_TEXT_LENGTH);
    GenderFederationNameShort.read(in);
    RegionalStrength.read(in);
}

// --- Write data --- //
void Continent::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::SHORT_TEXT_LENGTH);
    GenderName.write(out);
    NameThreeLetter.write(out, String::THREE_LETTER_LENGTH);
    NameContinentality.write(out, String::SHORT_TEXT_LENGTH);
    FederationName.write(out, String::LONG_TEXT_LENGTH);
    GenderFederationName.write(out);
    FederationNameShort.write(out, String::SHORT_TEXT_LENGTH);
    GenderFederationNameShort.write(out);
    RegionalStrength.write(out);
}
