#include "nation_data.h"


/* =============================== */
/*      Nation Database Table      */
/* =============================== */

// --- Default constructor --- //
NationData::NationData() :
    DatabaseContainer<Nation, NationModel>()
{

}
