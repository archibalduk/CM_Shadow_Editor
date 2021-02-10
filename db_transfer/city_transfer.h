#ifndef CITYTRANSFER_H
#define CITYTRANSFER_H

// Application headers
#include "database_transfer.h"

// --- City import/export --- //
class CityTransfer : public DatabaseTransfer
{
public:
    // Default constructor
    CityTransfer(QAbstractTableModel *model);
};

#endif // CITYTRANSFER_H
