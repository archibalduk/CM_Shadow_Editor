#ifndef PLAYER_H
#define PLAYER_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/attribute.h"
#include "../data_types/short.h"
#include "schema_base_class.h"

// --- Player attribute data --- //
class Player : public SchemaBaseClass
{
private:
    Char SquadNumber;
    Short CurrentAbility;
    Short PotentialAbility;
    Short HomeReputation; // Version 0x02 - Changed char->short
    Short CurrentReputation; // Version 0x02 - Changed char->short
    Short WorldReputation; // Version 0x02 - Changed char->short
    Attribute Goalkeeper;
    Attribute Sweeper;
    Attribute Defender;
    Attribute DefensiveMidfielder;
    Attribute Midfielder;
    Attribute AttackingMidfielder;
    Attribute Attacker;
    Attribute WingBack;
    Attribute RightSide;
    Attribute LeftSide;
    Attribute Central;
    Attribute FreeRole;
    Attribute Acceleration;
    Attribute Aggression;
    Attribute Agility;
    Attribute Anticipation;
    Attribute Balance;
    Attribute Bravery; // Value
    Attribute Consistency;
    Attribute Corners;
    Attribute Crossing;
    Attribute Decisions;
    Attribute Dirtiness;
    Attribute Dribbling;
    Attribute Finishing;
    Attribute Flair;
    Attribute FreeKicks;
    Attribute Handling;
    Attribute Heading;
    Attribute ImportantMatches;
    Attribute InjuryProneness;
    Attribute Jumping;
    Attribute Leadership;
    Attribute LeftFoot;
    Attribute LongShots;
    Attribute Marking;
    Attribute Movement;
    Attribute NaturalFitness;
    Attribute OneOnOnes;
    Attribute Pace;
    Attribute Passing;
    Attribute Penalties;
    Attribute Positioning;
    Attribute Reflexes;
    Attribute RightFoot;
    Attribute Stamina;
    Attribute Strength;
    Attribute Tackling;
    Attribute Teamwork;
    Attribute Technique;
    Attribute ThrowIns;
    Attribute Versatility;
    Attribute Vision;
    Attribute WorkRate;

    // runtime data
    Attribute Morale;

    // Friend classes
    friend class StaffModel;

public:
    // Constructor
    Player();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // PLAYER_H
