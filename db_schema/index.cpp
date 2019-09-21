#include "index.h"

/* ==================== */
/*      Index Data      */
/* ==================== */

// --- Default constructor --- //
Index::Index() :
    FileId(0),
    TableSize(0),
    Offset(0),
    Version(0)
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read row of data --- //
void Index::read(QDataStream &in)
{
    Filename.read(in, String::STANDARD_TEXT_LENGTH);
    in >> FileId >> TableSize >> Offset >> Version;
}

// --- Write data --- //
void Index::write(QDataStream &out)
{
    Filename.write(out, String::STANDARD_TEXT_LENGTH);
    out << FileId << TableSize << Offset << Version;
}


/* ================= */
/*      Get Data     */
/* ================= */

// --- File Name --- //
QString Index::getFileName()
{
    return Filename.get();
}

// --- Offset --- //
qint32 Index::getOffset()
{
    return Offset;
}

// --- Record count --- //
qint32 Index::getRecordCount()
{
    return TableSize;
}
