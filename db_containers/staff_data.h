#ifndef STAFF_DATA_H
#define STAFF_DATA_H

// Application headers
#include "../db_schema/staff.h"
#include "../model/staff_model.h"
#include "database_container.h"

// --- Staff database table --- //
class StaffData : public DatabaseContainer<Staff, StaffModel>
{
public:
    // Constructor
    StaffData();
};

#endif // STAFF_DATA_H
