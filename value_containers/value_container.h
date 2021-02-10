#ifndef VALUE_CONTAINER_H
#define VALUE_CONTAINER_H

// Qt headers
#include <QObject>
#include <QSortFilterProxyModel>
#include <QString>
#include <QStringList>

// Application headers
#include "../model/value_model.h"

// --- Value container base class --- //
class ValueContainer
{
protected:
    // Model
    ValueModel *m_Model;
    QSortFilterProxyModel *m_Proxy;

    // Settings
    bool m_SortAlphabetically;

public:
    // Constructor
    ValueContainer(const bool &sortAlphabetically = true);

    // Data
    QStringList Data;

    // Model
    ValueModel *model();
    QSortFilterProxyModel *proxy();
};

#endif // VALUE_CONTAINER_H
