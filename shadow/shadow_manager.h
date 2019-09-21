#ifndef SHADOW_MANAGER_H
#define SHADOW_MANAGER_H

// Qt headers
#include <QHash>
#include <QSortFilterProxyModel>
#include <QVector>

// Application headers
#include "model/shadow_group_model.h"

// --- Shadow edit manager --- //
class ShadowManager
{
private:
    // Shadow edits data
    static ShadowGroupModel *s_ShadowData;
    static QSortFilterProxyModel *s_ShadowProxy;
    QHash<QString, qint32> m_GroupList;

    // Manager data
    qint16 m_TableId;   // Table id of the manager instance

    // Flags
    static bool s_Enabled;

    enum ENUM_FLAGS {
        NO_MATCH = -999
    };

public:
    // Destructor
    ShadowManager(const qint8 &tableId = -1);

    // Add data
    bool add(const QString &identifier, const QModelIndex &index, const QVariant &value);

    // Flags
    static bool isDisabled();
    static bool isEnabled();

    // Get data
    QVariant findEditItem(const QString &identifier, const QModelIndex &index) const;
    qint32 findGroup(const QString &identifier) const;

    // Model
    static ShadowGroupModel *model();
    static QSortFilterProxyModel *proxy();

    // Set data
    void setTableId(const qint16 &tableId);
};

#endif // SHADOW_MANAGER_H
