#ifndef NON_PLAYER_H
#define NON_PLAYER_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/char.h"
#include "../data_types/attribute.h"
#include "../data_types/short.h"
#include "schema_base_class.h"

// --- Non-player attribute data --- //
class NonPlayer : public SchemaBaseClass
{
private:
    Short CurrentAbility;
    Short PotentialAbility;
    Short HomeReputation; // Version 0x02 - Changed char->short
    Short CurrentReputation; // Version 0x02 - Changed char->short
    Short WorldReputation; // Version 0x02 - Changed char->short
    Attribute Attacking;
    Attribute Business;
    Attribute Coaching;
    Attribute CoachingGks;
    Attribute CoachingTechnique;
    Attribute Directness;
    Attribute Discipline;
    Attribute FreeRoles;
    Attribute Interference;
    Attribute Judgement;
    Attribute JudgingPotential;
    Attribute ManHandling;
    Attribute Marking;
    Attribute Motivating;
    Attribute Offside;
    Attribute Patience;
    Attribute Physiotherapy;
    Attribute Pressing;
    Attribute Resources;
    Attribute Tactics;
    Attribute Youngsters;
    Int Goalkeeper;
    Int Sweeper;
    Int Defender;
    Int DefensiveMidfielder;
    Int Midfielder;
    Int AttackingMidfielder;
    Int Attacker;
    Int WingBack;
    Char FormationPreferred;

    // Friend classes
    friend class StaffModel;

public:
    // Constructor
    NonPlayer();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);
};

#endif // NON_PLAYER_H
