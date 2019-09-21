#include "staff_comp_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/staff_comp_data.h"

// --- Constructor --- //
StaffCompModel::StaffCompModel(QObject *parent) :
    Model<StaffComp>(Database::staffComps.Data, COLUMN_COUNT, ShadowCommon::STAFF_COMPETITIONS, parent)
{

}

// --- Get data --- //
QVariant StaffCompModel::data(const QModelIndex &index, qint32 role) const
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
        StaffComp *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->ID.get();

        }
    }

    return QVariant();
}
