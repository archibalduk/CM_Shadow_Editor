#include "ptr_club.h"

// Application headers
#include "../db_modules/database.h"


/* ====================== */
/*      Club Pointer      */
/* ====================== */

// --- Default constructor --- //
PtrClub::PtrClub(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrClub::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrClub::getText() const
{
    return this->getText_Actual(Database::clubs.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrClub::isValid()
{
    return this->isValid_Actual(Database::clubs.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrClub::set(const qint32 &id)
{
    return this->set_Actual(Database::clubs.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrClub::set(const QVariant &value)
{
    return this->set_Actual(Database::clubs.Data, value.toInt());
}
