#ifndef STAFF_COMP_MODEL_H
#define STAFF_COMP_MODEL_H

// Application headers
#include "model.h"
#include "../db_schema/staff_comp.h"

// --- Staff Competition/Award Model (base class) --- //
class StaffCompModel : public Model<StaffComp>
{
public:
    // Constructor
    StaffCompModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // STAFF_COMP_MODEL_H
