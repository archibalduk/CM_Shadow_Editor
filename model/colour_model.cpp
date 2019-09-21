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

        switch(col) {

        case DisplayText:
            return i->ID.get();

        }
    }

    return QVariant();
}
