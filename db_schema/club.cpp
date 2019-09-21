#include "club.h"

Club::Club()
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void Club::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    GenderName.read(in);
    NameShort.read(in, String::SHORT_TEXT_LENGTH);
    GenderNameShort.read(in);
    Nation.read(in);
    Division.read(in);
    LastDivision.read(in);
    LastPosition.read(in);
    ReserveDivision.read(in);
    ProfessionalStatus.read(in);
    Cash.read(in);
    Stadium.read(in);
    OwnStadium.read(in);
    ReserveStadium.read(in);
    HomeMatchDay.read(in);
    Attendance.read(in);
    MinAttendance.read(in);
    MaxAttendance.read(in);
    Training.read(in);
    Reputation.read(in);
    PLC.read(in);
    ForegroundColour1.read(in);
    BackgroundColour1.read(in);
    ForegroundColour2.read(in);
    BackgroundColour2.read(in);
    ForegroundColour3.read(in);
    BackgroundColour3.read(in);
    FavouriteStaff1.read(in);
    FavouriteStaff2.read(in);
    FavouriteStaff3.read(in);
    DislikedStaff1.read(in);
    DislikedStaff2.read(in);
    DislikedStaff3.read(in);
    Rivals1.read(in);
    Rivals2.read(in);
    Rivals3.read(in);
    Chairman.read(in);

    for(int i = 0; i < Club::DIRECTOR_SIZE; ++i)
        DirectorList[i].read(in);

    Manager.read(in);
    AssistantManager.read(in);

    for(int i = 0; i < Club::SQUAD_SIZE; ++i)
        SquadList[i].read(in);

    for(int i = 0; i < Club::COACH_SIZE; ++i)
        CoachList[i].read(in);

    for(int i = 0; i < Club::SCOUT_SIZE; ++i)
        ScoutList[i].read(in);

    for(int i = 0; i < Club::PHYSIO_SIZE; ++i)
        PhysioList[i].read(in);

    EuroFlag.read(in);
    EuroSeeding.read(in);

    for(int i = 0; i < Club::TEAM_SZ; ++i)
        TeamSelected[i].read(in);

    for(int i = 0; i < Club::MAX_TACTIC_TRAINING; ++i)
        TacticTraining[i].read(in);

    TacticSelected.read(in);
    HasLinkedClub.read(in);
}

// --- Write data --- //
void Club::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    GenderName.write(out);
    NameShort.write(out, String::SHORT_TEXT_LENGTH);
    GenderNameShort.write(out);
    Nation.write(out);
    Division.write(out);
    LastDivision.write(out);
    LastPosition.write(out);
    ReserveDivision.write(out);
    ProfessionalStatus.write(out);
    Cash.write(out);
    Stadium.write(out);
    OwnStadium.write(out);
    ReserveStadium.write(out);
    HomeMatchDay.write(out);
    Attendance.write(out);
    MinAttendance.write(out);
    MaxAttendance.write(out);
    Training.write(out);
    Reputation.write(out);
    PLC.write(out);
    ForegroundColour1.write(out);
    BackgroundColour1.write(out);
    ForegroundColour2.write(out);
    BackgroundColour2.write(out);
    ForegroundColour3.write(out);
    BackgroundColour3.write(out);
    FavouriteStaff1.write(out);
    FavouriteStaff2.write(out);
    FavouriteStaff3.write(out);
    DislikedStaff1.write(out);
    DislikedStaff2.write(out);
    DislikedStaff3.write(out);
    Rivals1.write(out);
    Rivals2.write(out);
    Rivals3.write(out);
    Chairman.write(out);

    for(int i = 0; i < Club::DIRECTOR_SIZE; ++i)
        DirectorList[i].write(out);

    Manager.write(out);
    AssistantManager.write(out);

    for(int i = 0; i < Club::SQUAD_SIZE; ++i)
        SquadList[i].write(out);

    for(int i = 0; i < Club::COACH_SIZE; ++i)
        CoachList[i].write(out);

    for(int i = 0; i < Club::SCOUT_SIZE; ++i)
        ScoutList[i].write(out);

    for(int i = 0; i < Club::PHYSIO_SIZE; ++i)
        PhysioList[i].write(out);

    EuroFlag.write(out);
    EuroSeeding.write(out);

    for(int i = 0; i < Club::TEAM_SZ; ++i)
        TeamSelected[i].write(out);

    for(int i = 0; i < Club::MAX_TACTIC_TRAINING; ++i)
        TacticTraining[i].write(out);

    TacticSelected.write(out);
    HasLinkedClub.write(out);
}
