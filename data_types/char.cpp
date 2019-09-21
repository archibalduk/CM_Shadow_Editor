#include "char.h"

/* ====================== */
/*      Char Wrapper      */
/* ====================== */

// --- Default constructor --- //
Char::Char(const qint32 &i) :
    value(static_cast<qint8>(i))
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Char::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(qint8));
}

// --- Write --- //
void Char::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(qint8));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
short Char::get() const
{
    return static_cast<qint16>(value);
}

// --- Get QVariant --- //
const QVariant Char::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set from QVariant --- //
void Char::set(const QVariant &data)
{
    value = static_cast<char>(data.toInt());
}
