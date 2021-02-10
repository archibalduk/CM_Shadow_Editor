#include "staff_classification_data.h"


/* ==================================== */
/*      Staff Classification Table      */
/* ==================================== */

// --- Default constructor --- //
StaffClassificationData::StaffClassificationData()
{
    Data << QObject::tr("_Invalid_")
         << QObject::tr("Non-Player")
         << QObject::tr("Player")
         << QObject::tr("Player/Non-Player")
         << QObject::tr("Player (Youth)")
         << QObject::tr("Human Manager")
         << QObject::tr("Spare Non-Player");
}
