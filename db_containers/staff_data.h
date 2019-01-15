#ifndef STAFF_DATA_H
#define STAFF_DATA_H

// Qt headers
#include <QVector>

// Application headers
#include "../db_schema/staff.h"

// --- Staff database table --- //
class StaffData
{
public:
    // Constructor
    StaffData();

    // Database
    static QVector<Staff> Data;
};

#endif // STAFF_DATA_H
