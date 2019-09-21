#include "club_comp_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/club_comp_data.h"

// --- Constructor --- //
ClubCompModel::ClubCompModel(QObject *parent) :
    Model<ClubComp>(Database::clubComps.Data, COLUMN_COUNT, ShadowCommon::CLUB_COMPETITIONS, parent)
{

}

// --- Get data --- //
QVariant ClubCompModel::data(const QModelIndex &index, qint32 role) const
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
        ClubComp *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->ID.get();

        }
    }

    return QVariant();
}
