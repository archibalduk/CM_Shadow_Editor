#ifndef STAFF_PREFERENCES_DATA_H
#define STAFF_PREFERENCES_DATA_H

// Application headers
#include "../db_schema/staff_preferences.h"
#include "simple_container.h"

// --- Staff preferences database table --- //
class StaffPreferencesData : public SimpleContainer<StaffPreferences>
{
public:
    // Constructor
    StaffPreferencesData();
};

#endif // STAFF_PREFERENCES_DATA_H
