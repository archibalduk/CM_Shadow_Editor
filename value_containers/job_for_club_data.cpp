#include "job_for_club_data.h"


/* ============================ */
/*      Job For Club Table      */
/* ============================ */

// --- Default constructor --- //
JobForClubData::JobForClubData()
{
    Data << QObject::tr("_Invalid_")
         << QObject::tr("Chairman")
         << QObject::tr("Managing Dir.")
         << QObject::tr("General Manager")
         << QObject::tr("Dir. of Football")
         << QObject::tr("Manager")
         << QObject::tr("Assistant Manager")
         << QObject::tr("Reserve Manager")
         << QObject::tr("Coach")
         << QObject::tr("Scout")
         << QObject::tr("Physio")
         << QObject::tr("Player")
         << QObject::tr("Player/Manager")
         << QObject::tr("Player/Asst. Manager")
         << QObject::tr("Player/Reserve Manager")
         << QObject::tr("Player/Coach")
         << QObject::tr("Retired")
         << QObject::tr("Pundit");
}
