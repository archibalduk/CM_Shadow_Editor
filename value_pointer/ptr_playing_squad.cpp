#include "ptr_playing_squad.h"

// Application headers
#include "../db_modules/database_values.h"


/* ======================= */
/*      Playing Squad      */
/* ======================= */

// --- Default constructor --- //
PtrPlayingSquad::PtrPlayingSquad(const qint8 &value) :
    ValuePointer(value)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get text --- //
QString PtrPlayingSquad::getText()
{
    return this->getText_Actual(DatabaseValues::dataPlayingSquad.Data);
}


/* ====================== */
/*      Sanity Check      */
/* ====================== */

// --- Check whether the current value is within range --- //
bool PtrPlayingSquad::isValid()
{
    return this->isValid_Actual(DatabaseValues::dataPlayingSquad.Data);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set id --- //
bool PtrPlayingSquad::set(const qint32 &value)
{
    return this->set_Actual(DatabaseValues::dataPlayingSquad.Data, value);
}

// --- Set id (QVariant) --- //
bool PtrPlayingSquad::set(const QVariant &value)
{
    return this->set_Actual(DatabaseValues::dataPlayingSquad.Data, value.toInt());
}
