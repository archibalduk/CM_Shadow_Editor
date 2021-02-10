#include "staff_comp_data.h"


/* ================================================ */
/*      Staff Competition/Award Database Table      */
/* ================================================ */

// --- Default constructor --- //
StaffCompData::StaffCompData() :
    DatabaseContainer<StaffComp, StaffCompModel>()
{

}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void StaffCompData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool StaffCompData::sortMethod(const StaffComp &a, const StaffComp &b)
{
    if(a.Nation.get() != b.Nation.get())
        return a.Nation.get() < b.Nation.get();

    else return(a.ID.get() < b.ID.get());
}
