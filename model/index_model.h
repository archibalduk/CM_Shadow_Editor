#ifndef MODEL_INDEX_H
#define MODEL_INDEX_H

// Application headers
#include "model.h"
#include "../db_schema/index.h"

// --- Index Model --- //
class IndexModel : public Model<Index>
{
public:
    // Constructor
    IndexModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // MODEL_INDEX_H
