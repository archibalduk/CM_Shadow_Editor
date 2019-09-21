#include "short.h"

/* ======================= */
/*      Short Wrapper      */
/* ======================= */

// --- Default constructor --- //
Short::Short(const qint16 &i) :
    value(i)
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Short::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(qint16));
}

// --- Write --- //
void Short::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(qint16));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
qint16 Short::get() const
{
    return value;
}

// --- Get QVariant --- //
const QVariant Short::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set from QVariant --- //
void Short::set(const QVariant &data)
{
    value = static_cast<qint16>(data.toInt());
}
