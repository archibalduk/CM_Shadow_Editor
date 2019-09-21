#include "shadow_edit_item_model.h"

ShadowEditItemModel::ShadowEditItemModel(QObject *parent) :
    QAbstractTableModel(parent),
    m_Data(nullptr)
{

}

qint32 ShadowEditItemModel::columnCount(const QModelIndex &) const
{
    return COLUMN_COUNT;
}

qint32 ShadowEditItemModel::rowCount(const QModelIndex &) const
{
    if(m_Data != nullptr)
        return m_Data->size();
    else
        return 0;
}

QVariant ShadowEditItemModel::data(const QModelIndex &index, qint32 role) const
{
    ShadowEditItem *i = &(*m_Data)[index.row()];

    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        switch(index.column()) {

        case TableId:
            return i->m_TableId;

        case Column:
            return i->m_Column;

        case Value:
            return i->m_Value;
        }
    }

    return QVariant();
}

bool ShadowEditItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}

void ShadowEditItemModel::setSourceData(QVector<ShadowEditItem> *data)
{
    this->beginResetModel();
    m_Data = data;
    this->endResetModel();
}

Qt::ItemFlags ShadowEditItemModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

QVariant ShadowEditItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section) {

        case TableId:
            return tr("Table Id");

        case Column:
            return tr("Column");

        case Value:
            return tr("Value");
        }
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}
