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

// --- Get text --- //
QString PtrCommonName::getText()
{
    if(!this->isValid())
        return s_ErrorMessageInvalidId;
    else
        return Database::commonNames.Data[m_Id].getName();
}

// --- Is _None --- //
bool PtrCommonName::isNone()
{
    return(m_Id <= 0);  // 0 = No/blank common name
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrCommonName::isValid()
{
    return(m_Id >= -1 && m_Id < Database::commonNames.Data.size());
}

// --- Check whether the chosen value is within range --- //
bool PtrCommonName::isValid(const qint32 &id)
{
    return(id >= -1 && id < Database::commonNames.Data.size());
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrCommonName::set(const qint32 &id)
{
    // Sanity check
    if(!this->isValid(id))
        return false;
    else {
        m_Id = id;
        return true;
    }
}
