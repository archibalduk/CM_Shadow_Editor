#include "index_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/index_data.h"

// --- Constructor --- //
IndexModel::IndexModel(QObject *parent) :
    Model<Index>(Database::index.Data, COLUMN_COUNT, ShadowCommon::INDEXES, parent)
{

}


// --- Get data --- //
QVariant IndexModel::data(const QModelIndex &index, qint32 role) const
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
        Index *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return "TEXT";

        }
    }

    return QVariant();
}
