#ifndef PTRPLAYINGSQUAD_H
#define PTRPLAYINGSQUAD_H

// Application headers
#include "value_pointer.h"

// --- Playing squad pointer --- //
class PtrPlayingSquad : public ValuePointer
{
public:
    // Constructor
    PtrPlayingSquad(const qint8 &value = -1);

    // Get data
    QString getText();

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &value);
    bool set(const QVariant &value);
};

#endif // PTRPLAYINGSQUAD_H
