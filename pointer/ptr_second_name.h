#ifndef PTR_SECOND_NAME_H
#define PTR_SECOND_NAME_H

// Application headers
#include "pointer.h"

class PtrSecondName : public Pointer
{
public:
    // Constructor
    PtrSecondName(const qint32 &id = -1);

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

#endif // PTR_SECOND_NAME_H
