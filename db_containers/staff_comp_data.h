#ifndef STAFF_COMP_DATA_H
#define STAFF_COMP_DATA_H

// Application headers
#include "../db_schema/staff_comp.h"
#include "../model/staff_comp_model.h"
#include "database_container.h"

// --- City database table --- //
class StaffCompData : public DatabaseContainer<StaffComp, StaffCompModel>
{
public:
    // Constructor
    StaffCompData();

private:
    // Sort data
    void sortData();
    static bool sortMethod(const StaffComp &a, const StaffComp &b);
};

#endif // STAFF_COMP_DATA_H
