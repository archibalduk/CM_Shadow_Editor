#include "pointer.h"

// Qt headers
#include <QObject>

// --- Static text strings --- //
const QString Pointer::s_ErrorMessageInvalidId = QObject::tr("Invalid ID");
const QString Pointer::s_None = QObject::tr("[None]");

/* ===================================== */
/*      Database Pointer Base Class      */
/* ===================================== */

// --- Default constructor --- //
Pointer::Pointer(const qint32 &id) :
    m_Id(id)
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read --- //
void Pointer::read(QDataStream &in)
{
    in.readRawData((char*)&m_Id, sizeof(qint32));
}

// --- Write --- //
void Pointer::write(QDataStream &out)
{
    out.writeRawData((char*)&m_Id, sizeof(qint32));
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text (empty base function) --- //
QString Pointer::getText() const
{
    return QString("Pointer::getText");
}

// --- Is _None --- //
bool Pointer::isNone() const
{
    return(m_Id < 0);
}

// --- Is pointing to a value (as opposed to _None) --- //
bool Pointer::isPointer() const
{
    return(m_Id >= 0);
}
