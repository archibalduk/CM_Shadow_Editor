#ifndef STAFF_COMP_HISTORY_DATA_H
#define STAFF_COMP_HISTORY_DATA_H

// Application headers
#include "../db_schema/staff_comp_history.h"
#include "simple_container.h"

// --- Staff competition/award history container --- //
class StaffCompHistoryData : public SimpleContainer<StaffCompHistory>
{
public:
    // Constructor
    StaffCompHistoryData();
};

#endif // STAFF_COMP_HISTORY_DATA_H
