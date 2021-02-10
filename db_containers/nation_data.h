#ifndef NATION_DATA_H
#define NATION_DATA_H

// Application headers
#include "../db_schema/nation.h"
#include "../model/nation_model.h"
#include "database_container.h"

// --- Nation database table --- //
class NationData : public DatabaseContainer<Nation, NationModel>
{
public:
    // Constructor
    NationData();

private:
    // Sort data
    void sortData() { return; }
};

#endif // NATION_DATA_H
