#include "colour.h"


/* ================= */
/*      Colours      */
/* ================= */

// --- Default constructor -- //
Colour::Colour()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Colour data --- //
void Colour::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    RedIntensity.read(in);
    GreenIntensity.read(in);
    BlueIntensity.read(in);

    // Set data
    this->setIdentifier(Name.get());
}

// --- Write data --- //
void Colour::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    RedIntensity.write(out);
    GreenIntensity.write(out);
    BlueIntensity.write(out);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get QColor --- //
QColor Colour::getColour()
{
    return QColor(RedIntensity.get(), GreenIntensity.get(), BlueIntensity.get());
}
