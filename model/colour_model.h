#ifndef COLOUR_MODEL_H
#define COLOUR_MODEL_H

// Application headers
#include "model.h"
#include "../db_schema/colour.h"

// --- Colour Model (base class) --- //
class ColourModel : public Model<Colour>
{
public:
    // Constructor
    ColourModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant & value, qint32 role = Qt::EditRole) Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(qint32 section, Qt::Orientation orientation, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        Name = FIRST_ITEM,
        HexCode,
        RedIntensity,
        GreenIntensity,
        BlueIntensity,
        COLUMN_COUNT
    };
};

#endif // COLOUR_MODEL_H
