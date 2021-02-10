#ifndef STAFF_PREFERENCES_H
#define STAFF_PREFERENCES_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/int.h"
#include "../pointer/ptr_club.h"
#include "../pointer/ptr_staff.h"
#include "schema_base_class.h"

// --- Staff Preference Data --- //
class StaffPreferences : public SchemaBaseClass
{
private:
    PtrClub FavouriteClubs1;
    PtrClub FavouriteClubs2;
    PtrClub FavouriteClubs3;
    PtrClub DislikedClubs1;
    PtrClub DislikedClubs2;
    PtrClub DislikedClubs3;
    PtrStaff FavouriteStaff1;
    PtrStaff FavouriteStaff2;
    PtrStaff FavouriteStaff3;
    PtrStaff DislikedStaff1;
    PtrStaff DislikedStaff2;
    PtrStaff DislikedStaff3;

    // Friend classes
    friend class StaffModel;

public:
    // Constructor
    StaffPreferences();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // STAFF_PREFERENCES_H
