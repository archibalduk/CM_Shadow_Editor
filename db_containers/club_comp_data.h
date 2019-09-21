#ifndef CLUB_COMP_DATA_H
#define CLUB_COMP_DATA_H

// Application headers
#include "../db_schema/club_comp.h"
#include "../model/club_comp_model.h"
#include "database_container.h"

// --- Club competition database table --- //
class ClubCompData : public DatabaseContainer<ClubComp, ClubCompModel>
{
public:
    // Constructor
    ClubCompData();
};

#endif // CLUB_COMP_DATA_H
