#ifndef CLUB_COMP_MODEL_H
#define CLUB_COMP_MODEL_H

// Application headers
#include "model.h"
#include "../db_schema/club_comp.h"

// --- Club Competition Model (base class) --- //
class ClubCompModel : public Model<ClubComp>
{
public:
    // Constructor
    ClubCompModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // CLUB_COMP_MODEL_H
