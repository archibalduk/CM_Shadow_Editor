#include "name.h"


/* =================== */
/*      Name Data      */
/* =================== */

// --- Default constructor --- //
Name::Name() :
    Count(0)
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read row of data --- //
void Name::read(QDataStream &in)
{
    NameText.read(in, String::STANDARD_TEXT_LENGTH);
    ID.read(in);
    Nation.read(in);
    Count.read(in);
}

// --- Write data --- //
void Name::write(QDataStream &out)
{
    NameText.write(out, String::STANDARD_TEXT_LENGTH);
    ID.write(out);
    Nation.write(out);
    Count.write(out);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text --- //
QString Name::getName()
{
    return NameText.get();
}
