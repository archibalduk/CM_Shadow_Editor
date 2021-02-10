#ifndef CITY_DATA_H
#define CITY_DATA_H

// Application headers
#include "../db_schema/city.h"
#include "../model/city_model.h"
#include "database_container.h"

// --- City database table --- //
class CityData : public DatabaseContainer<City, CityModel>
{
public:
    // Constructor
    CityData();

private:
    // Sort data
    void sortData();
    static bool sortMethod(const City &a, const City &b);
};

#endif // CITY_DATA_H
