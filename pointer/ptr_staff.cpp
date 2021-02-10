#include "ptr_staff.h"

// Application headers
#include "../db_modules/database.h"


/* ======================= */
/*      Staff Pointer      */
/* ======================= */

// --- Default constructor --- //
PtrStaff::PtrStaff(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrStaff::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrStaff::getText() const
{
    return this->getText_Actual(Database::staff.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrStaff::isValid()
{
    return this->isValid_Actual(Database::staff.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrStaff::set(const qint32 &id)
{
    return this->set_Actual(Database::staff.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrStaff::set(const QVariant &value)
{
    return this->set_Actual(Database::staff.Data, value.toInt());
}
