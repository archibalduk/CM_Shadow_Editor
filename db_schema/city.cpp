#include "city.h"


/* ================ */
/*      Cities      */
/* ================ */

// --- Default constructor -- //
City::City()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void City::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::SHORT_TEXT_LENGTH);
    GenderName.read(in);
    Nation.read(in);
    Latitude.read(in);
    Longitude.read(in);
    Attraction.read(in);
    Weather.read(in);
}

// --- Write data --- //
void City::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::SHORT_TEXT_LENGTH);
    GenderName.write(out);
    Nation.write(out);
    Latitude.write(out);
    Longitude.write(out);
    Attraction.write(out);
    Weather.write(out);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Display text --- //
QString City::getDisplayText()
{
    return Name.get();
}
