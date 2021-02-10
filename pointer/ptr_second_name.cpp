#include "ptr_second_name.h"

// Application headers
#include "../db_modules/database.h"


/* ============================= */
/*      Second Name Pointer      */
/* ============================= */

// --- Default constructor --- //
PtrSecondName::PtrSecondName(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrSecondName::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrSecondName::getText() const
{
    return this->getText_Actual(Database::secondNames.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrSecondName::isValid()
{
    return this->isValid_Actual(Database::secondNames.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id (integer) --- //
bool PtrSecondName::set(const qint32 &id)
{
    return this->set_Actual(Database::secondNames.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrSecondName::set(const QVariant &value)
{
    return this->set_Actual(Database::secondNames.Data, value.toInt());
}
