#include "playing_squad_data.h"


/* ============================= */
/*      Playing Squad Table      */
/* ============================= */

// --- Default constructor --- //
PlayingSquadData::PlayingSquadData()
{
    Data << QObject::tr("_Invalid_")
         << QObject::tr("Club Senior Squad")
         << QObject::tr("Club Reserve Squad")
         << QObject::tr("National A Squad")
         << QObject::tr("National B Squad");
}
