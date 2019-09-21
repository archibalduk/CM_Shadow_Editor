#ifndef SHADOW_EDIT_ITEM_H
#define SHADOW_EDIT_ITEM_H

// Qt headers
#include <QModelIndex>
#include <QVariant>

// --- Shadow edit item --- //
class ShadowEditItem
{
private:
    // Data
    qint16 m_TableId;
    //QString m_Identifier;
    qint32 m_Column;
    //qint32 m_Row;
    QVariant m_Value;

    // Friend classes
    friend class ShadowEditItemModel;

public:
    // Constructor
    ShadowEditItem();
    ShadowEditItem(const qint16 &tableId, const QModelIndex &index, const QVariant &value);

    // Get data
    qint32 getColumn();
    qint16 getTableId();
    QVariant getValue();

    // Set data
    void setValue(const QVariant &value);
};

#endif // SHADOW_EDIT_ITEM_H
