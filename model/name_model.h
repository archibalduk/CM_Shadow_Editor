#ifndef MODEL_NAME_H
#define MODEL_NAME_H

// Application headers
#include "model.h"
#include "../db_schema/name.h"

// --- Name Model (base class) --- //
class NameModel : public Model<Name>
{
public:
    // Constructor
    NameModel(QVector<Name> &data, const qint8 &tableId, QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        InsertRowsHere = FIRST_ITEM,
        COLUMN_COUNT
    };
};

#endif // MODEL_NAME_H
