#ifndef INDEX_H
#define INDEX_H

// Qt headers
#include <QDataStream>
#include <QString>

// Application headers
#include "data_types/string.h"
#include "schema_base_class.h"

// --- Index.dat --- //
class Index : public SchemaBaseClass
{
private:
    // Database data
    String  Filename;
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
    void write(QDataStream &out);

    // Get data
    QString getFileName();
    qint32 getOffset();
    qint32 getRecordCount();
};

#endif // INDEX_H
