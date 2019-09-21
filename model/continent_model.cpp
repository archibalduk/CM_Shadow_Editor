#include "continent_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/continent_data.h"

// --- Constructor --- //
ContinentModel::ContinentModel(QObject *parent) :
    Model<Continent>(Database::continents.Data, COLUMN_COUNT, ShadowCommon::CONTINENTS, parent)
{

}

// --- Get data --- //
QVariant ContinentModel::data(const QModelIndex &index, qint32 role) const
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
        Continent *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->ID.get();

        }
    }

    return QVariant();
}
