#ifndef SIMPLE_CONTAINER_H
#define SIMPLE_CONTAINER_H

// Qt headers
#include <QDataStream>
#include <QVector>

// Application headers
#include "../db_modules/version.h"

// --- Database container base class with no model --- //
template<typename T_Data> class SimpleContainer
{
public:
    // Database
    QVector<T_Data> Data;


    /* ========================= */
    /*      Simple Container     */
    /* ========================= */

    // --- Constructor --- //
    SimpleContainer()
    {

    }

    // --- Destructor --- //
    virtual ~SimpleContainer()
    {

    }


    /* ================= */
    /*      Add Data     */
    /* ================= */

    // --- Add data --- //
    void add(const T_Data &item)
    {
        Data.push_back(item);
    }

    /* ================= */
    /*      File I/O     */
    /* ================= */

    // --- Read all data --- //
    virtual qint32 read(QDataStream &in, Version &/*version*/, const qint32 &count)
    {
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


    /* ================= */
    /*      Get Data     */
    /* ================= */

    // --- Get size --- //
    qint32 size()
    {
        return Data.size();
    }
};

#endif // SIMPLE_CONTAINER_H
