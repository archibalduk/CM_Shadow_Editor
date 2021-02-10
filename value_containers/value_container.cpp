#include "value_container.h"

/* ======================== */
/*      Value Container     */
/* ======================== */

// --- Constructor --- //
ValueContainer::ValueContainer(const bool &sortAlphabetically) :
    m_SortAlphabetically(sortAlphabetically)
{
    m_Model = nullptr;
    m_Proxy = nullptr;
}


/* =============== */
/*      Model      */
/* =============== */

// --- Get pointer to model --- //
ValueModel *ValueContainer::model()
{
    if(m_Model == nullptr) {
        m_Model = new ValueModel(Data);
    }

    return m_Model;
}

// --- Get pointer to proxy --- //
QSortFilterProxyModel *ValueContainer::proxy()
{
    if(m_Proxy == nullptr) {
        m_Proxy = new QSortFilterProxyModel(model());
        m_Proxy->setSortCaseSensitivity(Qt::CaseInsensitive);

        if(m_SortAlphabetically)
            m_Proxy->sort(ValueModel::Text, Qt::AscendingOrder);
        else
            m_Proxy->sort(ValueModel::Id, Qt::AscendingOrder);

        m_Proxy->setSourceModel(model());
    }

    return m_Proxy;
}
