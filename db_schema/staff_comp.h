#ifndef STAFF_COMP_H
#define STAFF_COMP_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "../db_containers/staff_comp_history_data.h"
#include "staff_comp_history.h"
#include "schema_base_class.h"

// --- Staff competition/award data --- //
class StaffComp : public SchemaBaseClass
{
private:
    String Name;
    Char GenderName;
    String NameShort;
    Char GenderNameShort;
    Int Continent;
    Int Nation;
    Int ForegroundColour;
    Int BackgroundColour;
    Short Reputation; // Version 0x02 - Changed char->short

    // History
    StaffCompHistoryData History;

    // Friend classes
    friend class StaffCompData;
    friend class StaffCompModel;

public:
    // Constructor
    StaffComp();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // History
    void addHistory(const StaffCompHistory &history);
    qint32 writeHistory(QDataStream &out, const bool &/*domestic*/);
};

#endif // STAFF_COMP_H
