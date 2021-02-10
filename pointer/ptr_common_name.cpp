#include "ptr_common_name.h"

// Application headers
#include "../db_modules/database.h"


/* ============================= */
/*      Common Name Pointer      */
/* ============================= */

// --- Default constructor --- //
PtrCommonName::PtrCommonName(const qint32 &id) :
    Pointer(id)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get id or text depending on whether UserRole is invoked --- //
QVariant PtrCommonName::get(const qint32 &role) const
{
    if(role != Qt::UserRole)
        return this->getId();
    else
        return this->getText();
}

// --- Get text --- //
QString PtrCommonName::getText() const
{
    return this->getText_Actual(Database::commonNames.Data);
}

// --- Is _None --- //
bool PtrCommonName::isNone() const
{
    return(m_Id <= 0);  // 0 = No/blank common name
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrCommonName::isValid()
{
    return this->isValid_Actual(Database::commonNames.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id (integer) --- //
bool PtrCommonName::set(const qint32 &id)
{
    return this->set_Actual(Database::commonNames.Data, id);
}

// --- Set id (QVariant) --- //
bool PtrCommonName::set(const QVariant &value)
{
    return this->set_Actual(Database::commonNames.Data, value.toInt());
}
