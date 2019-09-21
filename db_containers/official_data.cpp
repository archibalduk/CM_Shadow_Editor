#include "official_data.h"


/* ================================= */
/*      Official Database Table      */
/* ================================= */

// --- Default constructor --- //
OfficialData::OfficialData() :
    DatabaseContainer<Official, OfficialModel>()
{

}
