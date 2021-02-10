#include "player.h"


/* ===================== */
/*      Player Data      */
/* ===================== */

// --- Default constructor --- //
Player::Player()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void Player::read(QDataStream &in)
{
    ID.read(in);
    SquadNumber.read(in);
    CurrentAbility.read(in);
    PotentialAbility.read(in);
    HomeReputation.read(in);
    CurrentReputation.read(in);
    WorldReputation.read(in);
    Goalkeeper.read(in);
    Sweeper.read(in);
    Defender.read(in);
    DefensiveMidfielder.read(in);
    Midfielder.read(in);
    AttackingMidfielder.read(in);
    Attacker.read(in);
    WingBack.read(in);
    RightSide.read(in);
    LeftSide.read(in);
    Central.read(in);
    FreeRole.read(in);
    Acceleration.read(in);
    Aggression.read(in);
    Agility.read(in);
    Anticipation.read(in);
    Balance.read(in);
    Bravery.read(in); // Value
    Consistency.read(in);
    Corners.read(in);
    Crossing.read(in);
    Decisions.read(in);
    Dirtiness.read(in);
    Dribbling.read(in);
    Finishing.read(in);
    Flair.read(in);
    FreeKicks.read(in);
    Handling.read(in);
    Heading.read(in);
    ImportantMatches.read(in);
    InjuryProneness.read(in);
    Jumping.read(in);
    Leadership.read(in);
    LeftFoot.read(in);
    LongShots.read(in);
    Marking.read(in);
    Movement.read(in);
    NaturalFitness.read(in);
    OneOnOnes.read(in);
    Pace.read(in);
    Passing.read(in);
    Penalties.read(in);
    Positioning.read(in);
    Reflexes.read(in);
    RightFoot.read(in);
    Stamina.read(in);
    Strength.read(in);
    Tackling.read(in);
    Teamwork.read(in);
    Technique.read(in);
    ThrowIns.read(in);
    Versatility.read(in);
    Vision.read(in);
    WorkRate.read(in);

    // runtime data
    Morale.read(in);
}

// --- Write data --- //
void Player::write(QDataStream &out)
{
    ID.write(out);
    SquadNumber.write(out);
    CurrentAbility.write(out);
    PotentialAbility.write(out);
    HomeReputation.write(out);
    CurrentReputation.write(out);
    WorldReputation.write(out);
    Goalkeeper.write(out);
    Sweeper.write(out);
    Defender.write(out);
    DefensiveMidfielder.write(out);
    Midfielder.write(out);
    AttackingMidfielder.write(out);
    Attacker.write(out);
    WingBack.write(out);
    RightSide.write(out);
    LeftSide.write(out);
    Central.write(out);
    FreeRole.write(out);
    Acceleration.write(out);
    Aggression.write(out);
    Agility.write(out);
    Anticipation.write(out);
    Balance.write(out);
    Bravery.write(out); // Value
    Consistency.write(out);
    Corners.write(out);
    Crossing.write(out);
    Decisions.write(out);
    Dirtiness.write(out);
    Dribbling.write(out);
    Finishing.write(out);
    Flair.write(out);
    FreeKicks.write(out);
    Handling.write(out);
    Heading.write(out);
    ImportantMatches.write(out);
    InjuryProneness.write(out);
    Jumping.write(out);
    Leadership.write(out);
    LeftFoot.write(out);
    LongShots.write(out);
    Marking.write(out);
    Movement.write(out);
    NaturalFitness.write(out);
    OneOnOnes.write(out);
    Pace.write(out);
    Passing.write(out);
    Penalties.write(out);
    Positioning.write(out);
    Reflexes.write(out);
    RightFoot.write(out);
    Stamina.write(out);
    Strength.write(out);
    Tackling.write(out);
    Teamwork.write(out);
    Technique.write(out);
    ThrowIns.write(out);
    Versatility.write(out);
    Vision.write(out);
    WorkRate.write(out);

    // runtime data
    Morale.write(out);
}
