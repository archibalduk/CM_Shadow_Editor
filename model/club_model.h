#ifndef CLUB_MODEL_H
#define CLUB_MODEL_H

// Application headers
#include "model.h"
#include "../db_schema/club.h"

// --- Club Model (base class) --- //
class ClubModel : public Model<Club>
{
public:
    // Constructor
    ClubModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // CLUB_MODEL_H
