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
#include <QDebug>
// --- Read row of data --- //
void Index::read(QDataStream &in)
{
    Filename.read(in, String::STANDARD_TEXT_LENGTH);
    in >> FileId >> TableSize >> Offset >> Version;

    qDebug() << Filename.get() << Version;
}
