#include "stadium_data.h"


/* ================================ */
/*      Stadium Database Table      */
/* ================================ */

// --- Default constructor --- //
StadiumData::StadiumData() :
    DatabaseContainer<Stadium, StadiumModel>()
{

}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void StadiumData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool StadiumData::sortMethod(const Stadium &a, const Stadium &b)
{
    if(a.City.get() != b.City.get())
        return a.City.get() < b.City.get();

    else return(a.ID.get() < b.ID.get());
}
