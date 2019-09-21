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

// --- Get text --- //
QString PtrSecondName::getText()
{
    if(!this->isValid())
        return s_ErrorMessageInvalidId;
    else
        return Database::secondNames.Data[m_Id].getName();
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrSecondName::isValid()
{
    return(m_Id >= -1 && m_Id < Database::secondNames.Data.size());
}

// --- Check whether the chosen value is within range --- //
bool PtrSecondName::isValid(const qint32 &id)
{
    return(id >= -1 && id < Database::secondNames.Data.size());
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrSecondName::set(const qint32 &id)
{
    // Sanity check
    if(!this->isValid(id))
        return false;
    else {
        m_Id = id;
        return true;
    }
}
