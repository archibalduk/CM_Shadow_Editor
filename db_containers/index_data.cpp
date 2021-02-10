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
    // Header
    m_Header.resize(INDEX_HEADER_SIZE);
    in.readRawData(m_Header.data(), INDEX_HEADER_SIZE);

    // Records
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

// --- Write all data --- //
qint32 IndexData::write(QDataStream &out, const bool &/*domestic*/)
{
    // Header
    out.writeRawData(m_Header, INDEX_HEADER_SIZE);

    // Records
    const qint32 size = Data.size();
    for(qint32 i = 0; i < size; ++i) {
        Data[i].write(out);
    }

    return size;
}


/* ================= */
/*      Set Data     */
/* ================= */

// --- Set count (and offset) --- //
void IndexData::setCount(const qint32 &tableId, const qint32 &count, const qint32 &offset)
{
    if(tableId < 0 || tableId >= INDEX_TABLE_COUNT)
        return;

    Data[tableId].TableSize = count;
    Data[tableId].Offset = offset;
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
