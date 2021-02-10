#include "club_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/club_data.h"

// --- Constructor --- //
ClubModel::ClubModel(QObject *parent) :
    Model<Club>(Database::clubs.Data, COLUMN_COUNT, ShadowCommon::CLUBS, parent)
{

}

// --- Get data --- //
QVariant ClubModel::data(const QModelIndex &index, qint32 role) const
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
        Club *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->Name.get();

        case Identifier:
            return QVariant();

        case Id:
            return i->ID.get();

        }
    }

    return QVariant();
}
