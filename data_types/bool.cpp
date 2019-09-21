#include "bool.h"

/* ========================= */
/*      Boolean Wrapper      */
/* ========================= */

// --- Default constructor --- //
Bool::Bool(const bool &b) :
    value(b)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
bool Bool::get() const
{
    return value;
}

// --- Get QVariant --- //
const QVariant Bool::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Bool::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(bool));
}

// --- Write --- //
void Bool::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(bool));
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set from QVariant --- //
void Bool::set(const QVariant &data)
{
    value = data.toBool();
}
