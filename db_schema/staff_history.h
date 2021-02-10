#ifndef STAFF_HISTORY_H
#define STAFF_HISTORY_H

// Application headers
#include "../data_types/bool.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/u_char.h"
#include "schema_base_class.h"

// --- Staff history data --- //
class StaffHistory : public SchemaBaseClass
{
private:
    // Data
    Int     Staff;
    Short   Year;
    Int     Club;
    Bool    OnLoan;
    UChar   Apps;
    UChar   Goals;

public:
    // Constructor
    StaffHistory();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qint32 getParentId();
};

#endif // STAFF_HISTORY_H
