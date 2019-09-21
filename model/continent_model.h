#ifndef MODEL_CONTINENT_H
#define MODEL_CONTINENT_H

// Application headers
#include "model.h"
#include "../db_schema/continent.h"

// --- Continent Model (base class) --- //
class ContinentModel : public Model<Continent>
{
public:
    // Constructor
    ContinentModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // MODEL_CONTINENT_H
