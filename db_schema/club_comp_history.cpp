#include "club_comp_history.h"

/* ================================== */
/*      Club Competition History      */
/* ================================== */

// --- Default constructor -- //
ClubCompHistory::ClubCompHistory()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void ClubCompHistory::read(QDataStream &in)
{
    ID.read(in);
    Comp.read(in);
    Year.read(in);
    Winners.read(in);
    RunnersUp.read(in);
    ThirdPlaced.read(in);
    Hosts.read(in);
}

// --- Write data --- //
void ClubCompHistory::write(QDataStream &out)
{
    ID.write(out);
    Comp.write(out);
    Year.write(out);
    Winners.write(out);
    RunnersUp.write(out);
    ThirdPlaced.write(out);
    Hosts.write(out);
}
