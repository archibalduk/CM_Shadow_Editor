#include "city_data.h"

// Application headers
#include "../db_transfer/city_transfer.h"

/* ============================= */
/*      City Database Table      */
/* ============================= */

// --- Default constructor --- //
CityData::CityData() :
    DatabaseContainer<City, CityModel>()
{
    m_DatabaseTransfer = new CityTransfer(this->model());
}


/* =================== */
/*      Sort Data      */
/* =================== */

// --- Sort --- //
void CityData::sortData()
{
    // Sort data
    std::sort(Data.begin(), Data.end(), sortMethod);
}

// --- Sort method --- //
bool CityData::sortMethod(const City &a, const City &b)
{
    if(a.Nation.get() != b.Nation.get())
        return a.Nation.get() < b.Nation.get();

    else return(a.Name.get().compare(b.Name.get(), Qt::CaseInsensitive));
}
