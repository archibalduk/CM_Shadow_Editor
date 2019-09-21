#ifndef MODEL_H
#define MODEL_H

// Qt headers
#include <QVector>

// Application headers
#include "model_base_class_wrapper.h"

// --- Table model base class --- //
template<typename T> class Model : public ModelBaseClassWrapper
{
protected:
    // Underlying data
    QVector<T> *m_Data;

public:
    // --- Default constructor --- //
    Model(QVector<T> &vect, const qint16 &columnCount, const qint8 &tableId, QObject *parent) :
        ModelBaseClassWrapper(tableId, parent)
    {
        m_Data = &vect;             // Pointer to underlying data
        m_ColumnCount = columnCount;// Column count
    }
    // --- Column count --- //
    qint32 columnCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE
    {
        return m_ColumnCount;
    }

    /*
    // --- Insert rows --- //
    virtual bool insertRows(qint32 row, qint32 count, const QModelIndex &parent = QModelIndex())
    {
        this->beginInsertRows(parent, row, row + count);
        this->endInsertRows();
        return true;
    }
    */

    // --- Row/QVector count --- //
    qint32 rowCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE
    {
        return m_Data->size();
    }
};

#endif // MODEL_H
