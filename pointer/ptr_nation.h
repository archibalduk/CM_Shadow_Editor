#ifndef PTR_NATION_H
#define PTR_NATION_H

// Application headers
#include "pointer.h"

class PtrNation : public Pointer
{
public:
    // Constructor
    PtrNation(const qint32 &id = -1);

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

#endif // PTR_NATION_H
