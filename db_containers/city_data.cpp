#include "city_data.h"


/* ============================= */
/*      City Database Table      */
/* ============================= */

// --- Default constructor --- //
CityData::CityData() :
    DatabaseContainer<City, CityModel>()
{

}
