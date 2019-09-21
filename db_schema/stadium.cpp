#include "stadium.h"

/* ================ */
/*      Stadia      */
/* ================ */

// --- Default constructor -- //
Stadium::Stadium()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void Stadium::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    GenderName.read(in);
    City.read(in);
    Capacity.read(in);
    SeatingCapacity.read(in);
    ExpansionCapacity.read(in);
    NearbyStadium.read(in);
    Covered.read(in);
    UnderSoilHeating.read(in);
}

// --- Write data --- //
void Stadium::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    GenderName.write(out);
    City.write(out);
    Capacity.write(out);
    SeatingCapacity.write(out);
    ExpansionCapacity.write(out);
    NearbyStadium.write(out);
    Covered.write(out);
    UnderSoilHeating.write(out);
}
