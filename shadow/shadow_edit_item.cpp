#include "shadow_edit_item.h"


/* ========================== */
/*      Shadow Edit Item      */
/* ========================== */

// --- Default constructor --- //
ShadowEditItem::ShadowEditItem()
{

}

// --- Standard constructor --- //
ShadowEditItem::ShadowEditItem(const qint16 &tableId, const QModelIndex &index, const QVariant &value) :
    m_TableId(tableId),
    m_Column(index.column()),
    m_Value(value)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Column --- //
qint32 ShadowEditItem::getColumn()
{
    return m_Column;
}

// --- Table Id --- //
qint16 ShadowEditItem::getTableId()
{
    return m_TableId;
}

// --- Value/QVariant --- //
QVariant ShadowEditItem::getValue()
{
    return m_Value;
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set value --- //
void ShadowEditItem::setValue(const QVariant &value)
{
    m_Value = value;
}
