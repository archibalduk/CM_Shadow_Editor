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
    QVariant get(const qint32 &role = Qt::DisplayRole) const;
    QString getText() const;

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &id);
    bool set(const QVariant &value);
};

#endif // PTR_FIRST_NAME_H
