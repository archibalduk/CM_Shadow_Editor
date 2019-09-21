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

// --- Get text --- //
QString PtrNation::getText()
{
    if(!this->isValid())
        return s_ErrorMessageInvalidId;
    else
        return Database::nations.Data[m_Id].getName();
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrNation::isValid()
{
    return(m_Id >= -1 && m_Id < Database::nations.Data.size());
}

// --- Check whether the chosen value is within range --- //
bool PtrNation::isValid(const qint32 &id)
{
    return(id >= -1 && id < Database::nations.Data.size());
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrNation::set(const qint32 &id)
{
    // Sanity check
    if(!this->isValid(id))
        return false;
    else {
        m_Id = id;
        return true;
    }
}
