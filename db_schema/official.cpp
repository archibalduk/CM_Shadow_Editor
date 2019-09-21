#include "official.h"


/* ======================= */
/*      Official Data      */
/* ======================= */

// --- Default constructor --- //
Official::Official()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void Official::read(QDataStream &in)
{
    ID.read(in);
    FirstName.read(in);
    SecondName.read(in);
    DateOfBirth.read(in);
    YearOfBirth.read(in);
    Nation.read(in);
    City.read(in);
    CurrentAbility.read(in);
    PotentialAbility.read(in);
    Reputation.read(in);
    AllowingFlow.read(in);
    Discipline.read(in);
    ImportantMatches.read(in);
    Pressure.read(in);
    Refereeing.read(in);
    RunningLine.read(in);
    Timekeeping.read(in);
}

// --- Write data --- //
void Official::write(QDataStream &out)
{
    ID.write(out);
    FirstName.write(out);
    SecondName.write(out);
    DateOfBirth.write(out);
    YearOfBirth.write(out);
    Nation.write(out);
    City.write(out);
    CurrentAbility.write(out);
    PotentialAbility.write(out);
    Reputation.write(out);
    AllowingFlow.write(out);
    Discipline.write(out);
    ImportantMatches.write(out);
    Pressure.write(out);
    Refereeing.write(out);
    RunningLine.write(out);
    Timekeeping.write(out);
}
