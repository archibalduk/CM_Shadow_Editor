#ifndef STADIUM_DATA_H
#define STADIUM_DATA_H

// Application headers
#include "../db_schema/stadium.h"
#include "../model/stadium_model.h"
#include "database_container.h"

// --- Stadium database table --- //
class StadiumData : public DatabaseContainer<Stadium, StadiumModel>
{
public:
    // Constructor
    StadiumData();

private:
    // Sort data
    void sortData();
    static bool sortMethod(const Stadium &a, const Stadium &b);
};

#endif // STADIUM_DATA_H
