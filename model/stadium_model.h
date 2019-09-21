#ifndef MODEL_STADIUM_H
#define MODEL_STADIUM_H

// Application headers
#include "model.h"
#include "../db_schema/stadium.h"

// --- Stadium Model (base class) --- //
class StadiumModel : public Model<Stadium>
{
public:
    // Constructor
    StadiumModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // MODEL_STADIUM_H
