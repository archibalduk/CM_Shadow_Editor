#ifndef DATABASE_VALUES_H
#define DATABASE_VALUES_H

// Qt headers
#include "../value_containers/job_for_club_data.h"
#include "../value_containers/playing_squad_data.h"
#include "../value_containers/staff_classification_data.h"

// --- Database values --- //
class DatabaseValues
{
public:
    // Default constructor
    DatabaseValues() {}

    // Values: Staff
    static JobForClubData dataJobForClub;
    static PlayingSquadData dataPlayingSquad;
    static StaffClassificationData dataStaffClassification;
};

#endif // DATABASE_VALUES_H
