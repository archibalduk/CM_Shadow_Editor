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
    QVariant get(const qint32 &role = Qt::DisplayRole) const;
    QString getText() const;

    // Sanity check
    bool isNone() const;
    bool isValid();

    // Set data
    bool set(const qint32 &id);
    bool set(const QVariant &value);
};

#endif // PTR_COMMON_NAME_H
