#include "staff_preferences.h"


/* =============================== */
/*      Staff Preference Data      */
/* =============================== */

// --- Default constructor --- //
StaffPreferences::StaffPreferences()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void StaffPreferences::read(QDataStream &in)
{
    ID.read(in);
    FavouriteClubs1.read(in);
    FavouriteClubs2.read(in);
    FavouriteClubs3.read(in);
    DislikedClubs1.read(in);
    DislikedClubs2.read(in);
    DislikedClubs3.read(in);
    FavouriteStaff1.read(in);
    FavouriteStaff2.read(in);
    FavouriteStaff3.read(in);
    DislikedStaff1.read(in);
    DislikedStaff2.read(in);
    DislikedStaff3.read(in);
}

// --- Write data --- //
void StaffPreferences::write(QDataStream &out)
{
    ID.write(out);
    FavouriteClubs1.write(out);
    FavouriteClubs2.write(out);
    FavouriteClubs3.write(out);
    DislikedClubs1.write(out);
    DislikedClubs2.write(out);
    DislikedClubs3.write(out);
    FavouriteStaff1.write(out);
    FavouriteStaff2.write(out);
    FavouriteStaff3.write(out);
    DislikedStaff1.write(out);
    DislikedStaff2.write(out);
    DislikedStaff3.write(out);
}
