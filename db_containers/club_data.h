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

    // Domestic/international data
    void setFirstInternationalItem();
    void setNextItemsAsDomestic();
    void setNextItemsAsInternational();

private:
    // Sort data
    void sortData();
    static bool sortMethod(const Club &a, const Club &b);
};

#endif // CLUB_DATA_H
