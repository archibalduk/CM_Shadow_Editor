#include "ptr_job_for_club.h"

// Application headers
#include "../db_modules/database_values.h"


/* ====================== */
/*      Job For Club      */
/* ====================== */

// --- Default constructor --- //
PtrJobForClub::PtrJobForClub(const qint8 &value) :
    ValuePointer(value)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text --- //
QString PtrJobForClub::getText()
{
    return this->getText_Actual(DatabaseValues::dataJobForClub.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrJobForClub::isValid()
{
    return this->isValid_Actual(DatabaseValues::dataJobForClub.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrJobForClub::set(const qint32 &value)
{
    return this->set_Actual(DatabaseValues::dataJobForClub.Data, value);
}

// --- Set id (QVariant) --- //
bool PtrJobForClub::set(const QVariant &value)
{
    return this->set_Actual(DatabaseValues::dataJobForClub.Data, value.toInt());
}
