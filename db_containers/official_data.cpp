#include "official_data.h"


/* ================================= */
/*      Official Database Table      */
/* ================================= */

// --- Default constructor --- //
OfficialData::OfficialData() :
    DatabaseContainer<Official, OfficialModel>()
{

}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void OfficialData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool OfficialData::sortMethod(const Official &a, const Official &b)
{
    if(a.SecondNameId.get() != b.SecondNameId.get())
        return a.SecondNameId.get() < b.SecondNameId.get();

    else if(a.FirstNameId.get() != b.FirstNameId.get())
        return a.FirstNameId.get() < b.FirstNameId.get();

    else return(a.ID.get() < b.ID.get());
}
