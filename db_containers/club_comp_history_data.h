#ifndef CLUB_COMP_HISTORY_DATA_H
#define CLUB_COMP_HISTORY_DATA_H

// Application headers
#include "../db_schema/club_comp_history.h"
#include "simple_container.h"

// --- Staff competition/award history container --- //
class ClubCompHistoryData: public SimpleContainer<ClubCompHistory>
{
public:
    // Constructor
    ClubCompHistoryData();
};

#endif // CLUB_COMP_HISTORY_DATA_H
