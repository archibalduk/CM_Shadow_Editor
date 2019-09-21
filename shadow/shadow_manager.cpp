#include "shadow_manager.h"

// --- Static data: Flags --- //
bool ShadowManager::s_Enabled = true;

// --- Static data: Models --- //
ShadowGroupModel *ShadowManager::s_ShadowData = nullptr;
QSortFilterProxyModel *ShadowManager::s_ShadowProxy = nullptr;


/* ======================== */
/*      Shadow Manager      */
/* ======================== */

// --- Default constructor --- //
ShadowManager::ShadowManager(const qint8 &tableId) :
    m_TableId(tableId)
{

}


/* ================== */
/*      Add Data      */
/* ================== */

// --- Add edited item to the appropriate group --- //
bool ShadowManager::add(const QString &identifier, const QModelIndex &index, const QVariant &value)
{    
    // Find target group item
    qint32 target = this->findGroup(identifier);

    // Add a new group item if the target item does not exist
    if(target == NO_MATCH) {
        target = s_ShadowData->add(identifier);
        m_GroupList.insert(identifier, target);
    }

    // Add edited item to the target group
    s_ShadowData->addEditItem(target, index, value);

    return true;
}


/* =============== */
/*      Flags      */
/* =============== */

// --- Is shadow recording disabled --- //
bool ShadowManager::isDisabled()
{
    return !s_Enabled;
}

// --- Is shadow recording enabled --- //
bool ShadowManager::isEnabled()
{
    return s_Enabled;
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Find an edit item from an existing group --- //
QVariant ShadowManager::findEditItem(const QString &identifier, const QModelIndex &index) const
{
    // Find target group item
    qint32 target = this->findGroup(identifier);

    // Return a null QVariant if the target item does not exist
    if(target == NO_MATCH)
        return QVariant();

    // Find an edit
    return s_ShadowData->findEditItem(target, index);
}

// --- Find identifier within the existing groups --- //
qint32 ShadowManager::findGroup(const QString &identifier) const
{
    return m_GroupList.value(identifier, NO_MATCH);
}


/* =============== */
/*      Model      */
/* =============== */

// --- Get model --- //
ShadowGroupModel *ShadowManager::model()
{
    if(s_ShadowData == nullptr)
        s_ShadowData = new ShadowGroupModel();

    return s_ShadowData;
}

// --- Get model proxy --- //
QSortFilterProxyModel *ShadowManager::proxy()
{
    if(s_ShadowProxy == nullptr) {
        s_ShadowProxy = new QSortFilterProxyModel(model());
        s_ShadowProxy->setSourceModel(model());
    }

    return s_ShadowProxy;
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set table id --- //
void ShadowManager::setTableId(const qint16 &tableId)
{
    m_TableId = tableId;
}
