#ifndef PTR_COMMON_NAME_H
#define PTR_COMMON_NAME_H

// Application headers
#include "pointer.h"

class PtrCommonName : public Pointer
{
public:
    // Constructor
    PtrCommonName(const qint32 &id = -1);

    // Get data
    QString getText();
    bool isNone();

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &id);

private:
    // Sanity check
    bool isValid(const qint32 &id);
};

#endif // PTR_COMMON_NAME_H
