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

// --- Get text --- //
QString PtrFirstName::getText()
{
    if(!this->isValid())
        return s_ErrorMessageInvalidId;
    else
        return Database::firstNames.Data[m_Id].getName();
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrFirstName::isValid()
{
    return(m_Id >= -1 && m_Id < Database::firstNames.Data.size());
}

// --- Check whether the chosen value is within range --- //
bool PtrFirstName::isValid(const qint32 &id)
{
    return(id >= -1 && id < Database::firstNames.Data.size());
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrFirstName::set(const qint32 &id)
{
    // Sanity check
    if(!this->isValid(id))
        return false;
    else {
        m_Id = id;
        return true;
    }
}
