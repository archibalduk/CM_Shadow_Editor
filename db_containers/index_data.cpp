#include "index_data.h"


/* ============================== */
/*      Index Database Table      */
/* ============================== */

// --- Default constructor --- //
IndexData::IndexData() :
    DatabaseContainer<Index, IndexModel>()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read all data --- //
qint32 IndexData::read(QDataStream &in, Version &version, const qint32 &/*count*/)
{
    while(!in.atEnd()) {
        Index tmp;
        tmp.read(in);
        Data.push_back(tmp);
    }

    // Set database version number
    version.set(findHighestVersion());

    //return this->resetModel();
    return Data.size();
}


/* ================ */
/*      Version     */
/* ================ */

// --- Find highest database version --- //
qint32 IndexData::findHighestVersion()
{
    qint32 version = 0;
    const qint32 size = Data.size();

    for(int i = 0; i < size; ++i) {
        if(Data[i].Version > version)
            version = Data[i].Version;
    }

    return version;
}
