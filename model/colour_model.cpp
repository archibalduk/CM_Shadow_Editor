#include "colour_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/colour_data.h"

// --- Constructor --- //
ColourModel::ColourModel(QObject *parent) :
    Model<Colour>(Database::colours.Data, COLUMN_COUNT, ShadowCommon::COLOURS, parent)
{

}

// --- Get data --- //
QVariant ColourModel::data(const QModelIndex &index, qint32 role) const
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
        Colour *i = &(*m_Data)[index.row()];

        // Check for a shadow edit
        QVariant value = this->shadow(index);
        if(value.isValid())
            return value;

        switch(col) {

        case DisplayText:
        case Name:
            return i->Name.get();

        case Identifier:
            return i->getIdentifier();

        case RedIntensity:
            return i->RedIntensity.get();

        case GreenIntensity:
            return i->GreenIntensity.get();

        case BlueIntensity:
            return i->BlueIntensity.get();

        case HexCode:
            return i->getColour().name();

        }
    }

    else if(role == Qt::DecorationRole) {

        if(index.column() == DisplayText) {
            QModelIndex red = this->index(index.row(), RedIntensity);
            QModelIndex green = this->index(index.row(), GreenIntensity);
            QModelIndex blue = this->index(index.row(), BlueIntensity);

            return QColor(this->data(red).toInt(), this->data(green).toInt(), this->data(blue).toInt());
        }
    }

    return QVariant();
}

// --- Set data --- //
bool ColourModel::setData(const QModelIndex &index, const QVariant &value, qint32 role)
{
    // Validate the data before making any changes to the underlying data
    const bool result = this->validate(index, value, role);

    if(result == false)
        return false;

    Colour *i = &(*m_Data)[index.row()];

    switch(index.column()) {

    case Id:
        i->ID.set(value);
        break;

    case Name:
        i->Name.set(value);
        emit dataChanged(this->index(index.row(), DisplayText),
                         this->index(index.row(), DisplayText));

        break;

    case RedIntensity:
        i->RedIntensity.set(value);
        emit dataChanged(this->index(index.row(), HexCode),
                         this->index(index.row(), HexCode));
        emit dataChanged(this->index(index.row(), DisplayText),
                         this->index(index.row(), DisplayText));
        break;

    case GreenIntensity:
        i->GreenIntensity.set(value);
        emit dataChanged(this->index(index.row(), HexCode),
                         this->index(index.row(), HexCode));
        emit dataChanged(this->index(index.row(), DisplayText),
                         this->index(index.row(), DisplayText));
        break;

    case BlueIntensity:
        i->BlueIntensity.set(value);
        emit dataChanged(this->index(index.row(), HexCode),
                         this->index(index.row(), HexCode));
        emit dataChanged(this->index(index.row(), DisplayText),
                         this->index(index.row(), DisplayText));
        break;

    default:
        return false;
    }

    emit dataChanged(index, index);
    return true;
}

// --- Get header --- //
QVariant ColourModel::headerData(qint32 section, Qt::Orientation orientation, qint32 role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section) {

        case DisplayText: return tr("Display Text");
        case Id: return tr("ID");
        case Name: return tr("Name");
        case RedIntensity:return tr("Red (0-255)");
        case GreenIntensity:return tr("Green (0-255)");
        case BlueIntensity:return tr("Blue (0-255)");
        case HexCode:return tr("HTML Colour Code");
        }
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}
