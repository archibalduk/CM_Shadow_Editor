#ifndef PTR_STAFF_CLASSIFICATION_H
#define PTR_STAFF_CLASSIFICATION_H

// Application headers
#include "value_pointer.h"

// --- Staff classification pointer --- //
class PtrStaffClassification : public ValuePointer
{
public:
    // Constructor
    PtrStaffClassification(const qint8 &value = -1);

    // Get data
    QString getText();

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &value);
    bool set(const QVariant &value);
};

#endif // PTR_STAFF_CLASSIFICATION_H
