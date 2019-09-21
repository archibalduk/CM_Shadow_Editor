#ifndef OFFICIAL_MODEL_H
#define OFFICIAL_MODEL_H

// Application headers
#include "model.h"
#include "../db_schema/official.h"

// --- Official Model (base class) --- //
class OfficialModel: public Model<Official>
{
public:
    // Constructor
    OfficialModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // OFFICIAL_MODEL_H
