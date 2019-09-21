#ifndef MODEL_CITY_H
#define MODEL_CITY_H

// Application headers
#include "model.h"
#include "../db_schema/city.h"

// --- City Model (base class) --- //
class CityModel : public Model<City>
{
public:
    // Constructor
    CityModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant & value, qint32 role = Qt::EditRole) Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(qint32 section, Qt::Orientation orientation, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        Name = FIRST_ITEM,
        GenderName,
        Nation,
        Latitude,
        Longitude,
        Attraction,
        Weather,
        COLUMN_COUNT
    };
};

#endif // MODEL_CITY_H
