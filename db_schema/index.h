#ifndef INDEX_H
#define INDEX_H

// Qt headers
#include <QDataStream>

// Application headers
#include "data_types/string.h"

// --- Index.dat --- //
class Index
{
private:
    // Database data
    String  Filename;
    qint32  FileId;
    qint32  TableSize;
    qint32  Offset;
    qint32  Version;

    // Friend classes
    friend class IndexData;

public:
    // Constructor
    Index();

    // File I/O
    void read(QDataStream &in);
};

#endif // INDEX_H
