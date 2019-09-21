#ifndef SHADOW_GROUP_H
#define SHADOW_GROUP_H

// Qt headers
#include <QString>
#include <QVector>

// Application headers
#include "shadow_edit_item.h"

// --- Group of shadow edit items relating to a single table record --- //
class ShadowGroup
{
private:
    // Group data
    QString m_Identifier;
    qint32 m_RowId;
    qint16 m_TableId;

    // Edit items
    QVector<ShadowEditItem> m_Items;

    // Flags
    enum ENUM_FLAGS {
        NO_MATCH = -999
    };

    // Friends
    friend class ShadowGroupModel;

    // Get data
    qint32 find(const QModelIndex &index);

public:
    // Constructor
    ShadowGroup();
    ShadowGroup(const QString identifier);

    // Add data
    bool addEditItem(const QModelIndex &index, const QVariant &value);

    // Get data
    QVariant getValue(const QModelIndex &index);
};

#endif // SHADOW_GROUP_H
