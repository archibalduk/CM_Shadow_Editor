#ifndef CONTINENT_DATA_H
#define CONTINENT_DATA_H

// Application headers
#include "../db_schema/continent.h"
#include "../model/continent_model.h"
#include "database_container.h"

// --- Continent database table --- //
class ContinentData : public DatabaseContainer<Continent, ContinentModel>
{
public:
    // Constructor
    ContinentData();

private:
    // Sort data
    void sortData() { return; }
};

#endif // CONTINENT_DATA_H
