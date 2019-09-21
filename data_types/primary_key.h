#ifndef PRIMARY_KEY_H
#define PRIMARY_KEY_H

// Application headers
#include "int.h"

// --- Primary key --- //
class PrimaryKey : public Int
{
public:
    // Constructor
    PrimaryKey(const qint32 &i = -1);
};

#endif // PRIMARY_KEY_H
