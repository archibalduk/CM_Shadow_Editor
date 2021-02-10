#ifndef DATABASE_CONTAINER_H
#define DATABASE_CONTAINER_H

// Qt headers
#include <QDataStream>
#include <QSortFilterProxyModel>
#include <QVector>

// Application headers
#include "../db_modules/version.h"
#include "../db_transfer/database_transfer.h"
#include "../model/model_base_class_wrapper.h"

// --- Database container base class --- //
template<typename T_Data, typename T_Model> class DatabaseContainer
{
private:
    // Model
    T_Model *m_Model;
    QSortFilterProxyModel *m_Proxy;

public:
    // Database
    QVector<T_Data> Data;

    // Database import/export
    DatabaseTransfer *m_DatabaseTransfer;

    // Domestic/international
    qint32 m_PosFirstDomesticItem = 0;
    qint32 m_PosFirstInternationalItem = 0;


    /* =========================== */
    /*      Database Container     */
    /* =========================== */

    // --- Constructor --- //
    DatabaseContainer()
    {
        m_Model = nullptr;
        m_Proxy = nullptr;
        m_DatabaseTransfer = nullptr;
    }

    // --- Destructor --- //
    virtual ~DatabaseContainer()
    {
        if(m_Proxy != nullptr)
            delete m_Proxy;

        if(m_Model != nullptr)
            delete m_Model;

        if(m_DatabaseTransfer != nullptr)
            delete m_DatabaseTransfer;
    }


    /* ================================ */
    /*      Database Import/Export      */
    /* ================================ */

    // --- Get database transfer class --- //
    DatabaseTransfer *databaseTransfer()
    {
        return m_DatabaseTransfer;
    }

    /* ===================================== */
    /*      Domestic/International Data      */
    /* ===================================== */

    // --- Set first international item value (sub-class this function for tables where there are international items) --- //
    virtual void setFirstInternationalItem()
    {
        m_PosFirstInternationalItem = Data.size();
    }

    // --- Flag next items to be read/written as domestic (empty wrapper function) --- //
    virtual void setNextItemsAsDomestic()
    {
        return;
    }

    // --- Flag next items to be read/written as international (empty wrapper function) --- //
    virtual void setNextItemsAsInternational()
    {
        return;
    }


    /* ================= */
    /*      File I/O     */
    /* ================= */

    // --- Read all data --- //
    virtual qint32 read(QDataStream &in, Version &/*version*/, const qint32 &count)
    {
        // Begin model reset
        this->model()->beginReset();

        // Count initial number of items in container
        const qint32 initialSize = Data.size();

        // Read entire file
        if(count < 0) {
            while(!in.atEnd()) {
                T_Data tmp;
                tmp.read(in);
                tmp.syncIdCache();
                Data.push_back(tmp);
            }
        }
        // Read x records
        else {
            for(qint32 i = 0; i < count; ++i) {
                T_Data tmp;
                tmp.read(in);
                tmp.syncIdCache();
                Data.push_back(tmp);
            }
        }

        // End model reset
        this->model()->endReset();
        return Data.size() - initialSize;   // Return number of items read
    }

    // --- Write all data --- //
    virtual qint32 write(QDataStream &out, const bool &domestic = true)
    {
        qint32 first = 0;
        qint32 last = Data.size();

        // Adjust first/last according to whether domestic or international (if applicable)
        this->setFirstInternationalItem();

        if(domestic) // Domestic -> Last should point to the element after the last domestic element. The first is the first in the QVector
            last = m_PosFirstInternationalItem;
        else // International -> First should point to the first international element. The last is the last in the QVector
            first = m_PosFirstInternationalItem;

        for(qint32 i = first; i < last; ++i) {
            Data[i].syncIdCache();
            Data[i].write(out);
        }

        return last - first;
    }


    /* ================= */
    /*      Get Data     */
    /* ================= */

    // --- Row count --- //
    qint32 size()
    {
        return Data.size();
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


    /* ================== */
    /*      Sort Data     */
    /* ================== */

    // --- Re-number the IDs --- //
    void renumber()
    {
        const qint32 size = Data.size();
        for(qint32 i = 0; i < size; ++i) {
            Data[0].syncIdCache();
            Data[0].ID.set(i);
        }
    }

    // --- Sort data --- //
    void sort()
    {
        // Begin model reset
        this->model()->beginReset();

        // Sort and renumber data
        this->sortData();
        this->renumber();

        // End model reset
        this->model()->endReset();
    }

protected:
    // --- Sort the data --- //
    virtual void sortData() = 0;
};

#endif // DATABASE_CONTAINER_H
