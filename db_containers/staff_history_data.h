#ifndef STAFF_HISTORY_DATA_H
#define STAFF_HISTORY_DATA_H

// Application headers
#include "../db_schema/staff_history.h"
#include "simple_container.h"

// --- Staff history container --- //
class StaffHistoryData : public SimpleContainer<StaffHistory>
{
public:
    // Constructor
    StaffHistoryData();
};

#endif // STAFF_HISTORY_DATA_H
