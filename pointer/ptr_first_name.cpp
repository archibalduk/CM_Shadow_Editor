#include "ptr_first_name.h"

// Application headers
#include "../db_modules/database.h"


/* ============================ */
/*      First Name Pointer      */
/* ============================ */

// --- Default constructor --- //
PtrFirstName::PtrFirstName(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrFirstName::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrFirstName::getText() const
{
    return this->getText_Actual(Database::firstNames.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrFirstName::isValid()
{
    return this->isValid_Actual(Database::firstNames.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id (integer) --- //
bool PtrFirstName::set(const qint32 &id)
{
    return this->set_Actual(Database::firstNames.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrFirstName::set(const QVariant &value)
{
    return this->set_Actual(Database::firstNames.Data, value.toInt());
}
