#ifndef PTR_CLUB_H
#define PTR_CLUB_H

// Application headers
#include "pointer.h"

// --- Club pointer --- //
class PtrClub : public Pointer
{
public:
    // Constructor
    PtrClub(const qint32 &id = -1);

    // Get data
    QVariant get(const qint32 &role = Qt::DisplayRole) const;
    QString getText() const;

    // Sanity check
    bool isValid();

    // Set data
    bool set(const qint32 &id);
    bool set(const QVariant &value);
};

#endif // PTR_CLUB_H
