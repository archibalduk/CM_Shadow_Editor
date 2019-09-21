#include "city_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/city_data.h"

// --- Constructor --- //
CityModel::CityModel(QObject *parent) :
    Model<City>(Database::cities.Data, COLUMN_COUNT, ShadowCommon::CITIES, parent)
{

}

// --- Get data --- //
QVariant CityModel::data(const QModelIndex &index, qint32 role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        const qint32 col = index.column();

        if(!this->checkRow(index)) {
            if(col == DisplayText)
                return tr("[None]");
            else
                return QVariant();
        }

        // Item
        City *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->getDisplayText();

        case Id:
            return i->ID.get();

        case Name:
            return i->Name.get();

        case GenderName:
            return i->GenderName.get();

        case Nation:
            return i->Nation.get();

        case Latitude:
            return i->Latitude.get();

        case Longitude:
            return i->Longitude.get();

        case Attraction:
            return i->Attraction.get();

        case Weather:
            return i->Weather.get();

        }
    }

    return QVariant();
}

// --- Set data --- //
bool CityModel::setData(const QModelIndex &index, const QVariant &value, qint32 role)
{
    // Validate the data before making any changes to the underlying data
    const bool result = this->validate(index, value, role);

    if(result == false)
        return false;

    City *i = &(*m_Data)[index.row()];

    switch(index.column()) {

    case DisplayText:
        i->getDisplayText();
        break;

    case Id:
        i->ID.set(value);
        break;

    case Name:
        //i->Name.set(value);
        break;

    case GenderName:
        i->GenderName.set(value);
        break;

    case Nation:
        //i->Nation.set(value);
        break;

    case Latitude:
        i->Latitude.set(value);
        break;

    case Longitude:
        i->Longitude.set(value);
        break;

    case Attraction:
        i->Attraction.set(value);
        break;

    case Weather:
        i->Weather.set(value);
        break;
    }

    emit dataChanged(index, index);
    return true;
}

// --- Get header --- //
QVariant CityModel::headerData(qint32 section, Qt::Orientation orientation, qint32 role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section) {

        case DisplayText: return s_DisplayText;
        case Id: return s_Id;
        case Name: return s_Name;
        case GenderName: return s_GenderName;
        case Nation: return s_Nation;
        case Latitude: return tr("Latitude");
        case Longitude: return tr("Longitude");
        case Attraction: return tr("Attraction");
        case Weather: return tr("Weather");
        }
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}
