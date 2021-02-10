#include "value_pointer.h"

// Qt headers
#include <QObject>

// --- Static text strings --- //
const QString ValuePointer::s_ErrorMessageInvalidId = QObject::tr("Invalid ID");
const QString ValuePointer::s_None = QObject::tr("[None]");


/* ================================== */
/*      Value Pointer Base Class      */
/* ================================== */

// --- Default constructor --- //
ValuePointer::ValuePointer(const qint8 &value) :
    Char(value)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text --- //
QString ValuePointer::getText_Actual(QStringList &data)
{
    const qint16 value = m_Value.get();

    // Sanity check
    if(value < 0)
        return s_None;
    else if(value >= data.size())
        return s_ErrorMessageInvalidId;
    else
        return data[value];
}

// --- Is none --- //
bool ValuePointer::isNone()
{
    return m_Value.get() < 1;   // 0 = None
}

// --- Is pointer --- //
bool ValuePointer::isPointer()
{
    return m_Value.get() >= 0;
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool ValuePointer::isValid_Actual(const QStringList &data)
{
    const qint16 value = m_Value.get();
    return(value >= 0 && value < data.size());
}

// --- Check whether the selected value is within range --- //
bool ValuePointer::isValid_Actual(const QStringList &data, const qint32 &value)
{
    return(value >= 0 && value < data.size());
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id/value --- //
bool ValuePointer::set_Actual(const QStringList &data, const qint32 &value)
{
    // Sanity check
    if(!this->isValid_Actual(data, value))
        return false;
    else {
        m_Value.set(value);
        return true;
    }

}
