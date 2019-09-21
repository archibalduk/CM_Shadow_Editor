#include "staff_history.h"

/* ============================== */
/*      Staff Career History      */
/* ============================== */

// --- Default constructor -- //
StaffHistory::StaffHistory()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void StaffHistory::read(QDataStream &in)
{
    ID.read(in);
    Staff.read(in);
    Year.read(in);
    Club.read(in);
    OnLoan.read(in);
    Apps.read(in);
    Goals.read(in);
}

// --- Write data --- //
void StaffHistory::write(QDataStream &out)
{
    ID.write(out);
    Staff.write(out);
    Year.write(out);
    Club.write(out);
    OnLoan.write(out);
    Apps.write(out);
    Goals.write(out);
}
