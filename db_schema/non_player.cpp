#include "non_player.h"


/* ======================== */
/*     Non-player Data      */
/* ======================== */

// --- Default constructor --- //
NonPlayer::NonPlayer()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void NonPlayer::read(QDataStream &in)
{
    ID.read(in);
    CurrentAbility.read(in);
    PotentialAbility.read(in);
    HomeReputation.read(in);
    CurrentReputation.read(in);
    WorldReputation.read(in);
    Attacking.read(in);
    Business.read(in);
    Coaching.read(in);
    CoachingGks.read(in);
    CoachingTechnique.read(in);
    Directness.read(in);
    Discipline.read(in);
    FreeRoles.read(in);
    Interference.read(in);
    Judgement.read(in);
    JudgingPotential.read(in);
    ManHandling.read(in);
    Marking.read(in);
    Motivating.read(in);
    Offside.read(in);
    Patience.read(in);
    Physiotherapy.read(in);
    Pressing.read(in);
    Resources.read(in);
    Tactics.read(in);
    Youngsters.read(in);
    Goalkeeper.read(in);
    Sweeper.read(in);
    Defender.read(in);
    DefensiveMidfielder.read(in);
    Midfielder.read(in);
    AttackingMidfielder.read(in);
    Attacker.read(in);
    WingBack.read(in);
    FormationPreferred.read(in);
}

// --- Write data --- //
void NonPlayer::write(QDataStream &out)
{
    ID.write(out);
    CurrentAbility.write(out);
    PotentialAbility.write(out);
    HomeReputation.write(out);
    CurrentReputation.write(out);
    WorldReputation.write(out);
    Attacking.write(out);
    Business.write(out);
    Coaching.write(out);
    CoachingGks.write(out);
    CoachingTechnique.write(out);
    Directness.write(out);
    Discipline.write(out);
    FreeRoles.write(out);
    Interference.write(out);
    Judgement.write(out);
    JudgingPotential.write(out);
    ManHandling.write(out);
    Marking.write(out);
    Motivating.write(out);
    Offside.write(out);
    Patience.write(out);
    Physiotherapy.write(out);
    Pressing.write(out);
    Resources.write(out);
    Tactics.write(out);
    Youngsters.write(out);
    Goalkeeper.write(out);
    Sweeper.write(out);
    Defender.write(out);
    DefensiveMidfielder.write(out);
    Midfielder.write(out);
    AttackingMidfielder.write(out);
    Attacker.write(out);
    WingBack.write(out);
    FormationPreferred.write(out);
}
