#include "name_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/name_data.h"

// --- Constructor --- //
NameModel::NameModel(QVector<Name> &data, const qint8 &tableId, QObject *parent) :
    Model<Name>(data, COLUMN_COUNT, tableId, parent)
{

}


// --- Get data --- //
QVariant NameModel::data(const QModelIndex &index, qint32 role) const
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
        Name *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return "TEXT";

        }
    }

    return QVariant();
}
