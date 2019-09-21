#include "staff_data.h"


/* ============================== */
/*      Staff Database Table      */
/* ============================== */

// --- Default constructor --- //
StaffData::StaffData() :
    DatabaseContainer<Staff, StaffModel>()
{

}
