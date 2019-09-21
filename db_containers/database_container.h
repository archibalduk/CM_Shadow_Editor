#ifndef DATABASE_CONTAINER_H
#define DATABASE_CONTAINER_H

// Qt headers
#include <QDataStream>
#include <QSortFilterProxyModel>

// Application headers
#include "../db_modules/version.h"
#include "../model/model_base_class_wrapper.h"

// --- Database container base class --- //
template<typename T_Data, typename T_Model> class DatabaseContainer
{
public:    
    // Database
    QVector<T_Data> Data;

    // Model
    T_Model *m_Model;
    QSortFilterProxyModel *m_Proxy;


    /* =========================== */
    /*      Database Container     */
    /* =========================== */

    // Constructor
    DatabaseContainer()
    {
        m_Model = nullptr;
        m_Proxy = nullptr;
    }

    // Destructor
    virtual ~DatabaseContainer()
    {
        if(m_Proxy != nullptr)
            delete m_Proxy;

        if(m_Model != nullptr)
            delete m_Model;
    }


    /* ================= */
    /*      File I/O     */
    /* ================= */

    // --- Read all data --- //
    virtual qint32 read(QDataStream &in, Version &/*version*/, const qint32 &count)
    {
        // Begin model reset
        this->model()->beginReset();

        // Read entire file
        if(count < 0) {
            while(!in.atEnd()) {
                T_Data tmp;
                tmp.read(in);
                Data.push_back(tmp);
            }
        }
        // Read x records
        else {
            for(qint32 i = 0; i < count; ++i) {
                T_Data tmp;
                tmp.read(in);                
                Data.push_back(tmp);
            }
        }

        // End model reset
        this->model()->endReset();
        return Data.size();
    }

    // --- Write all data --- //
    virtual qint32 write(QDataStream &out)
    {
        const qint32 size = Data.size();

        for(qint32 i = 0; i < size; ++i) {
            Data[i].write(out);
        }

        return size;
    }

    /* =============== */
    /*      Model      */
    /* =============== */

    // --- Get pointer to model --- //
    T_Model *model()
    {
        if(m_Model == nullptr) {
            m_Model = new T_Model();
        }

        return m_Model;
    }

    // --- Get pointer to proxy --- //
    QSortFilterProxyModel *proxy()
    {
        if(m_Proxy == nullptr) {
            m_Proxy = new QSortFilterProxyModel(model());
            m_Proxy->setSortCaseSensitivity(Qt::CaseInsensitive);
            m_Proxy->sort(ModelBaseClassWrapper::DisplayText, Qt::AscendingOrder);
            m_Proxy->setSourceModel(model());
        }

        return m_Proxy;
    }

    // --- Reset the model --- //
    qint32 resetModel()
    {
        const qint32 size = Data.size();
        this->model()->insertRows(0, size);
        return size;
    }
};

#endif // DATABASE_CONTAINER_H
