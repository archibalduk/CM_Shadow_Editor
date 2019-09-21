#ifndef CLUB_DATA_H
#define CLUB_DATA_H

// Application headers
#include "../db_schema/club.h"
#include "../model/club_model.h"
#include "database_container.h"

// --- Club database table --- //
class ClubData : public DatabaseContainer<Club, ClubModel>
{
public:
    // Constructor
    ClubData();
};

#endif // CLUB_DATA_H
