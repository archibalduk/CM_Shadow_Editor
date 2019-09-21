#ifndef STAFF_PREFERENCES_H
#define STAFF_PREFERENCES_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/int.h"
#include "schema_base_class.h"

// --- Staff Preference Data --- //
class StaffPreferences : public SchemaBaseClass
{
private:
    Int FavouriteClubs1;
    Int FavouriteClubs2;
    Int FavouriteClubs3;
    Int DislikedClubs1;
    Int DislikedClubs2;
    Int DislikedClubs3;
    Int FavouriteStaff1;
    Int FavouriteStaff2;
    Int FavouriteStaff3;
    Int DislikedStaff1;
    Int DislikedStaff2;
    Int DislikedStaff3;

public:
    // Constructor
    StaffPreferences();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // STAFF_PREFERENCES_H
