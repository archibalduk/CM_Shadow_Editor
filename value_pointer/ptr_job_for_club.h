#ifndef PTR_JOB_FOR_CLUB_H
#define PTR_JOB_FOR_CLUB_H

// Application headers
#include "value_pointer.h"

// --- Job for club pointer --- //
class PtrJobForClub : public ValuePointer
{
public:
    // Constructor
    PtrJobForClub(const qint8 &value = -1);

    // Get data
    QString getText();

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &value);
    bool set(const QVariant &value);
};

#endif // PTR_JOB_FOR_CLUB_H
