#include "stadium_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/stadium_data.h"

// --- Constructor --- //
StadiumModel::StadiumModel(QObject *parent) :
    Model<Stadium>(Database::stadia.Data, COLUMN_COUNT, ShadowCommon::STADIA, parent)
{

}

// --- Get data --- //
QVariant StadiumModel::data(const QModelIndex &index, qint32 role) const
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
        Stadium *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->ID.get();
        }
    }

    return QVariant();
}
