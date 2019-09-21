#include "double.h"

/* ======================== */
/*      Double Wrapper      */
/* ======================== */

// --- Default constructor --- //
Double::Double(const qreal &i) :
    value(i)
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Double::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(qreal));
}

// --- Write --- //
void Double::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(qreal));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
qreal Double::get() const
{
    return value;
}

// --- Get QVariant --- //
const QVariant Double::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set from QVariant --- //
void Double::set(const QVariant &data)
{
    value = data.toDouble();
}
