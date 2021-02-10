#include "int.h"

/* ===================== */
/*      Int Wrapper      */
/* ===================== */

// --- Default constructor --- //
Int::Int(const qint32 &i) :
    value(i)
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Int::read(QDataStream &in)
{
    in.readRawData((char*)&value, sizeof(qint32));
}

// --- Write --- //
void Int::write(QDataStream &out)
{
    out.writeRawData((char*)&value, sizeof(qint32));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
qint32 Int::get() const
{
    return value;
}

// --- Is a pointer value --- //
bool Int::isPointer() const
{
    return(value >= 0);
}

// --- Get QVariant --- //
const QVariant Int::variant() const
{
    return QVariant(value);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Copy value from another Int item --- //
void Int::copy(const Int &data)
{
    value = data.value;
}

// --- Set from QVariant --- //
void Int::set(const QVariant &data)
{
    value = data.toInt();
}

// --- Set from an integer --- //
void Int::set(const qint32 &i)
{
    value = i;
}
