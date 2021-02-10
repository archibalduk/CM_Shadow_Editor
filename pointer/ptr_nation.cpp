#include "ptr_nation.h"

// Application headers
#include "../db_modules/database.h"


/* ======================== */
/*      Nation Pointer      */
/* ======================== */

// --- Default constructor --- //
PtrNation::PtrNation(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrNation::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrNation::getText() const
{
    return this->getText_Actual(Database::nations.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrNation::isValid()
{
    return this->isValid_Actual(Database::nations.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrNation::set(const qint32 &id)
{
    return this->set_Actual(Database::nations.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrNation::set(const QVariant &value)
{
    return this->set_Actual(Database::nations.Data, value.toInt());
}
