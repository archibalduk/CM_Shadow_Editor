#include "shadow_group_model.h"

ShadowGroupModel::ShadowGroupModel(QObject *parent) :
    QAbstractTableModel(parent)
{

}

qint32 ShadowGroupModel::columnCount(const QModelIndex &) const
{
    return COLUMN_COUNT;
}

qint32 ShadowGroupModel::rowCount(const QModelIndex &) const
{
    return m_Data.size();
}

qint32 ShadowGroupModel::add(const QString &identifier)
{
    const qint32 row = this->rowCount();
    this->beginInsertRows(QModelIndex(), row, row);

    ShadowGroup sg(identifier);
    m_Data.push_back(sg);

    this->endInsertRows();
    return row;
}

QVariant ShadowGroupModel::data(const QModelIndex &index, qint32 role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        switch(index.column()) {

        case DisplayText:
            return m_Data[index.row()].m_Identifier;

        case Idenfier:
            return m_Data[index.row()].m_Identifier;

        case RowId:
            return m_Data[index.row()].m_RowId;

        case TableId:
            return m_Data[index.row()].m_TableId;
        }
    }

    return QVariant();
}

QVector<ShadowEditItem> *ShadowGroupModel::editItems(const qint32 &row)
{
    return &m_Data[row].m_Items;
}

QVariant ShadowGroupModel::findEditItem(const qint32 &row, const QModelIndex &index)
{
    // Sanity check
    if(row < 0 || row >= this->rowCount())
        return false;

    return m_Data[row].getValue(index);
}

bool ShadowGroupModel::addEditItem(const qint32 &row, const QModelIndex &index, const QVariant &value)
{
    // Sanity check
    if(row < 0 || row >= this->rowCount())
        return false;

    return m_Data[row].addEditItem(index, value);
}

bool ShadowGroupModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}

Qt::ItemFlags ShadowGroupModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

QVariant ShadowGroupModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
