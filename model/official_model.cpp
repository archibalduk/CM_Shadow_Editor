#include "official_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/official_data.h"

// --- Constructor --- //
OfficialModel::OfficialModel(QObject *parent) :
    Model<Official>(Database::officials.Data, COLUMN_COUNT, ShadowCommon::OFFICIALS, parent)
{

}

// --- Get data --- //
QVariant OfficialModel::data(const QModelIndex &index, qint32 role) const
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
        Official *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->ID.get();

        }
    }

    return QVariant();
}
