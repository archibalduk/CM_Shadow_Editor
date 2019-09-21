#ifndef PTR_FIRST_NAME_H
#define PTR_FIRST_NAME_H

// Application headers
#include "pointer.h"

class PtrFirstName : public Pointer
{
public:
    // Constructor
    PtrFirstName(const qint32 &id = -1);

    // Get data
    QString getText();

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &id);

private:
    // Sanity check
    bool isValid(const qint32 &id);
};

#endif // PTR_FIRST_NAME_H
