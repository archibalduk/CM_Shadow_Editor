#ifndef INDEX_DATA_H
#define INDEX_DATA_H

// Qt headers
#include <QVector>

// Application headers
#include "../db_modules/version.h"
#include "../db_schema/index.h"

// --- Index database table --- //
class IndexData
{

public:
    // Constructor
    IndexData();

    // Database
    static QVector<Index> Data;

    // File I/O
    static qint32 read(QDataStream &in, Version &version);

    // Index header
    enum ENUM_HEADER_SIZE { INDEX_HEADER_SIZE = 8 };

private:
    // Index header
    static qint8 s_Header[INDEX_HEADER_SIZE];

    // Version
    static qint32 findHighestVersion();
};

#endif // INDEX_DATA_H
