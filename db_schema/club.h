#ifndef CLUB_H
#define CLUB_H

// Application headers
#include "../data_types/char.h"
#include "../data_types/int.h"
#include "../data_types/short.h"
#include "../data_types/string.h"
#include "schema_base_class.h"

// --- Club data --- //
class Club : public SchemaBaseClass
{
private:
    // Club sizes
    enum ENUM_CLUB_SIZES {
        DIRECTOR_SIZE = 3,
        SQUAD_SIZE = 50,
        SCOUT_SIZE = 7,
        COACH_SIZE = 5,
        PHYSIO_SIZE = 3
    };

    // Maximum sizes in CM 01/02
    enum ENUM_MAX_SIZES {
        MAX_FRIENDLY_COMPETITIONS = 127,    // Max number of friendly competitions
        MAX_HUMAN_PLAYERS = 16,             // Max number of human players
        MAX_TACTIC_TRAINING = 4,            // Maximum number of tactics in training at once
        TEAM_SZ = 20                        // Maximum size of a squad for a match
    };

    // Data
    String Name;
    Char GenderName;
    String NameShort;
    Char GenderNameShort;
    Int Nation;
    Int Division;
    Int LastDivision;
    Char LastPosition;
    Int ReserveDivision;
    Char ProfessionalStatus;
    Int Cash;
    Int Stadium;
    Char OwnStadium;
    Int ReserveStadium;
    Char HomeMatchDay;
    Int Attendance;
    Int MinAttendance;
    Int MaxAttendance;
    Char Training;
    Short Reputation; // Version 0x02 - Changed char->short
    Char PLC;
    Int ForegroundColour1;
    Int BackgroundColour1;
    Int ForegroundColour2;
    Int BackgroundColour2;
    Int ForegroundColour3;
    Int BackgroundColour3;
    Int FavouriteStaff1;
    Int FavouriteStaff2;
    Int FavouriteStaff3;
    Int DislikedStaff1;
    Int DislikedStaff2;
    Int DislikedStaff3;
    Int Rivals1;
    Int Rivals2;
    Int Rivals3;
    Int Chairman;
    Int DirectorList[ DIRECTOR_SIZE ];
    Int Manager;
    Int AssistantManager;
    Int SquadList[ SQUAD_SIZE ];
    Int CoachList[ COACH_SIZE ];
    Int ScoutList[ SCOUT_SIZE ];
    Int PhysioList[ PHYSIO_SIZE ];

    // Runtime data
    Int EuroFlag;
    Char EuroSeeding;
    Int TeamSelected[ TEAM_SZ ];
    Int TacticTraining[ MAX_TACTIC_TRAINING ];
    Int TacticSelected;
    Char HasLinkedClub;

    // Flags
    bool m_IsDomestic;
    static bool s_NextItemIsDomestic;

    // Friend classes
    friend class ClubData;
    friend class ClubModel;

public:
    // Constructor
    Club();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // CLUB_H
