#ifndef OFFICIAL_DATA_H
#define OFFICIAL_DATA_H

// Application headers
#include "../db_schema/official.h"
#include "../model/official_model.h"
#include "database_container.h"

// --- Official database table --- //
class OfficialData : public DatabaseContainer<Official, OfficialModel>
{
public:
    // Constructor
    OfficialData();
};

#endif // OFFICIAL_DATA_H
