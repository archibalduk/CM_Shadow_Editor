#include "value_model.h"


/* ===================== */
/*      Value Model      */
/* ===================== */

// --- Default constructor --- //
ValueModel::ValueModel(QStringList &data, QObject *parent) :
    QAbstractTableModel(parent),
    m_Data(&data)
{

}

// --- Column count --- //
qint32 ValueModel::columnCount(const QModelIndex &) const
{
    return COLUMN_COUNT;
}

// --- Row count --- //
qint32 ValueModel::rowCount(const QModelIndex &) const
{
    return m_Data->size();
}

// --- Get data --- //
QVariant ValueModel::data(const QModelIndex &index, qint32 role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        const qint32 col = index.column();
        const qint32 row = index.row();

        switch(col) {

        case Id:
            return row;

        case Text:
            if(row > -1)
                return m_Data->at(row);
            else
                return tr("None");
        }
    }

    return QVariant();
}

// --- Header --- //
QVariant ValueModel::headerData(qint32 section, Qt::Orientation orientation, qint32 role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section) {

        case Id: return tr("ID");
        case Text: return tr("Description");
        }
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}
