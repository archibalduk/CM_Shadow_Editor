#include "staff_comp.h"


/* =================================== */
/*      Staff Competitions/Awards      */
/* =================================== */

// --- Default constructor -- //
StaffComp::StaffComp()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void StaffComp::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    GenderName.read(in);
    NameShort.read(in, String::SHORT_TEXT_LENGTH);
    GenderNameShort.read(in);
    Continent.read(in);
    Nation.read(in);
    ForegroundColour.read(in);
    BackgroundColour.read(in);
    Reputation.read(in);
}

// --- Write data --- //
void StaffComp::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    GenderName.write(out);
    NameShort.write(out, String::SHORT_TEXT_LENGTH);
    GenderNameShort.write(out);
    Continent.write(out);
    Nation.write(out);
    ForegroundColour.write(out);
    BackgroundColour.write(out);
    Reputation.write(out);
}


/* ================ */
/*      History     */
/* ================ */

// --- Add history --- //
void StaffComp::addHistory(const StaffCompHistory &history)
{
    History.add(history);
}

// --- Write history --- //
qint32 StaffComp::writeHistory(QDataStream &out, const bool &/*domestic*/)
{
    History.write(out);
    return History.size();
}
