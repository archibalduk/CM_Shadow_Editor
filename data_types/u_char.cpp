#include "u_char.h"

/* =============================== */
/*      Unsigned Char Wrapper      */
/* =============================== */

// --- Default constructor --- //
UChar::UChar(const qint32 &i) :
    value(static_cast<quint8>(i))
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void UChar::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(qint8));
}

// --- Write --- //
void UChar::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(qint8));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
qint16 UChar::get() const
{
    return static_cast<qint16>(value);
}

// --- Get QVariant --- //
const QVariant UChar::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set from QVariant --- //
void UChar::set(const QVariant &data)
{
    const qint32 tmp = data.toInt();

    if(tmp >=0 && tmp <= 255)
        value = static_cast<quint8>(tmp);
}
