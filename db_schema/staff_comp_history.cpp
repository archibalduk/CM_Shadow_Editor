#include "staff_comp_history.h"


/* ============================================== */
/*      Staff Competition/Award History Data      */
/* ============================================== */

// --- Default constructor --- //
StaffCompHistory::StaffCompHistory()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void StaffCompHistory::read(QDataStream &in)
{
    ID.read(in);
    StaffComp.read(in);
    Year.read(in);
    FirstPlacedFirstName.read(in);
    FirstPlacedSecondName.read(in);
    FirstPlacedIndex.read(in);
    FirstPlacedInfo.read(in);
    SecondPlacedFirstName.read(in);
    SecondPlacedSecondName.read(in);
    SecondPlacedIndex.read(in);
    SecondPlacedInfo.read(in);
    ThirdPlacedFirstName.read(in);
    ThirdPlacedSecondName.read(in);
    ThirdPlacedIndex.read(in);
    ThirdPlacedInfo.read(in);
}

// --- Write data --- //
void StaffCompHistory::write(QDataStream &out)
{
    ID.write(out);
    StaffComp.write(out);
    Year.write(out);
    FirstPlacedFirstName.write(out);
    FirstPlacedSecondName.write(out);
    FirstPlacedIndex.write(out);
    FirstPlacedInfo.write(out);
    SecondPlacedFirstName.write(out);
    SecondPlacedSecondName.write(out);
    SecondPlacedIndex.write(out);
    SecondPlacedInfo.write(out);
    ThirdPlacedFirstName.write(out);
    ThirdPlacedSecondName.write(out);
    ThirdPlacedIndex.write(out);
    ThirdPlacedInfo.write(out);
}


/* ================= */
/*      Get Data     */
/* ================= */

// --- Parent/owner id --- //
qint32 StaffCompHistory::getParentId()
{
    return StaffComp.get();
}
