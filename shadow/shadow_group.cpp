#include "shadow_group.h"


/* ====================== */
/*      Shadow Group      */
/* ====================== */

// --- Default constructor --- //
ShadowGroup::ShadowGroup() :
    m_RowId(-1),
    m_TableId(-1)
{

}

// --- Standard constructor --- //
ShadowGroup::ShadowGroup(const QString identifier) :
    ShadowGroup()
{
    m_Identifier = identifier;
}


/* ================== */
/*      Add Data      */
/* ================== */

// --- Add an edit item --- //
bool ShadowGroup::addEditItem(const QModelIndex &index, const QVariant &value)
{
    // Check whether there is any existing item stored
    const qint32 id = this->find(index);

    // Add a new item if it does not exist
    if(id == NO_MATCH) {
        ShadowEditItem item(m_TableId, index, value);
        m_Items.push_back(item);
        return true;    // True = new item added
    }

    // Edit the existing item
    else {
        m_Items[id].setValue(value);
        return false;       // False = exising item edited
    }
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Find edit item/column within the existing edits --- //
qint32 ShadowGroup::find(const QModelIndex &index)
{
    const qint32 column = index.column();
    const qint32 size = m_Items.size();

    for(qint32 i = 0; i < size; ++i) {
        if(column == m_Items[i].getColumn() && m_TableId == m_Items[i].getTableId()) {
            return i;
        }
    }

    return NO_MATCH;
}

// --- Find edit and get item/column within the existing edits --- //
QVariant ShadowGroup::getValue(const QModelIndex &index)
{
    const int i = this->find(index);

    // No match
    if(i == NO_MATCH)
        return QVariant();  // Null QVariant
    else
        return m_Items[i].getValue();
}
