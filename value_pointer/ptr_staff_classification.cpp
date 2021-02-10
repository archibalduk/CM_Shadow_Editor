#include "ptr_staff_classification.h"

// Application headers
#include "../db_modules/database_values.h"


/* ============================== */
/*      Staff Classification      */
/* ============================== */

// --- Default constructor --- //
PtrStaffClassification::PtrStaffClassification(const qint8 &value) :
    ValuePointer(value)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text --- //
QString PtrStaffClassification::getText()
{
    return this->getText_Actual(DatabaseValues::dataStaffClassification.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrStaffClassification::isValid()
{
    return this->isValid_Actual(DatabaseValues::dataStaffClassification.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrStaffClassification::set(const qint32 &value)
{
    return this->set_Actual(DatabaseValues::dataStaffClassification.Data, value);
}

// --- Set id (QVariant) --- //
bool PtrStaffClassification::set(const QVariant &value)
{
    return this->set_Actual(DatabaseValues::dataStaffClassification.Data, value.toInt());
}
