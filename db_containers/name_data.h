#ifndef FIRST_NAME_DATA_H
#define FIRST_NAME_DATA_H

// Qt headers
#include <QAbstractTableModel>

// Application headers
#include "../db_schema/name.h"
#include "../model/name_model.h"
#include "database_container.h"

// --- Name database table --- //
template<typename T> class NameData : public DatabaseContainer<Name, T>
{
public:
    // Constructor
    NameData() : DatabaseContainer<Name, T>() {}
};

#endif // FIRST_NAME_DATA_H
