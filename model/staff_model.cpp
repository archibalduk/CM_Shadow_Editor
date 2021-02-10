#include "staff_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/staff_data.h"

// --- Constructor --- //
StaffModel::StaffModel(QObject *parent) :
    Model<Staff>(Database::staff.Data, COLUMN_COUNT, ShadowCommon::STAFF, parent)
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get data --- //
QVariant StaffModel::data(const QModelIndex &index, qint32 role) const
{
    if(role == Qt::DisplayRole || role == Qt::EditRole) {

        const qint32 col = index.column();

        if(!this->checkRow(index)) {
            if(col == DisplayText)
                return tr("[None]");
            else
                return QVariant();
        }

        // Item
        Staff *i = &(*m_Data)[index.row()];

        // Check for a shadow edit
        QVariant value = this->shadow(index);
        if(value.isValid())
            return value;

        if(col <= LAST_STAFF_ITEM)
            return this->data_Staff(i, col);
        else if(col <= LAST_NON_PLAYER_ITEM)
            return this->data_NonPlayer(i, col);
        else if(col <= LAST_PLAYER_ITEM)
            return this->data_Player(i, col);
        else if(col <= LAST_PREFERENCES_ITEM)
            return this->data_Preferences(i, col);
    }

    return QVariant();
}

// --- Get non-player data --- //
QVariant StaffModel::data_NonPlayer(Staff *i, const qint32 &col) const
{
    switch (col) {

    case CurrentAbility_NonPlayer: return i->nonplayer.CurrentAbility.get();
    case PotentialAbility_NonPlayer: return i->nonplayer.PotentialAbility.get();
    case HomeReputation_NonPlayer: return i->nonplayer.HomeReputation.get();
    case CurrentReputation_NonPlayer: return i->nonplayer.CurrentReputation.get();
    case WorldReputation_NonPlayer: return i->nonplayer.WorldReputation.get();
    case Attacking: return i->nonplayer.Attacking.get();
    case Business: return i->nonplayer.Business.get();
    case Coaching: return i->nonplayer.Coaching.get();
    case CoachingGks: return i->nonplayer.CoachingGks.get();
    case CoachingTechnique: return i->nonplayer.CoachingTechnique.get();
    case Directness: return i->nonplayer.Directness.get();
    case Discipline: return i->nonplayer.Discipline.get();
    case FreeRoles: return i->nonplayer.FreeRoles.get();
    case Interference: return i->nonplayer.Interference.get();
    case Judgement: return i->nonplayer.Judgement.get();
    case JudgingPotential: return i->nonplayer.JudgingPotential.get();
    case ManHandling: return i->nonplayer.ManHandling.get();
    case Marking: return i->nonplayer.Marking.get();
    case Motivating: return i->nonplayer.Motivating.get();
    case Offside: return i->nonplayer.Offside.get();
    case Patience: return i->nonplayer.Patience.get();
    case Physiotherapy: return i->nonplayer.Physiotherapy.get();
    case Pressing: return i->nonplayer.Pressing.get();
    case Resources: return i->nonplayer.Resources.get();
    case Tactics: return i->nonplayer.Tactics.get();
    case Youngsters: return i->nonplayer.Youngsters.get();
    case Goalkeeper_NonPlayer: return i->nonplayer.Goalkeeper.get();
    case Sweeper_NonPlayer: return i->nonplayer.Sweeper.get();
    case Defender_NonPlayer: return i->nonplayer.Defender.get();
    case DefensiveMidfielder_NonPlayer: return i->nonplayer.DefensiveMidfielder.get();
    case Midfielder_NonPlayer: return i->nonplayer.Midfielder.get();
    case AttackingMidfielder_NonPlayer: return i->nonplayer.AttackingMidfielder.get();
    case Attacker_NonPlayer: return i->nonplayer.Attacker.get();
    case WingBack_NonPlayer: return i->nonplayer.WingBack.get();
    case FormationPreferred: return i->nonplayer.FormationPreferred.get();

    }

    return QVariant();
}

// --- Get player data --- //
QVariant StaffModel::data_Player(Staff *i, const qint32 &col) const
{
    switch(col) {

    case SquadNumber: return i->player.SquadNumber.get();
    case CurrentAbility_Player: return i->player.CurrentAbility.get();
    case PotentialAbility_Player: return i->player.PotentialAbility.get();
    case HomeReputation_Player: return i->player.HomeReputation.get();
    case CurrentReputation_Player: return i->player.CurrentReputation.get();
    case WorldReputation_Player: return i->player.WorldReputation.get();
    case Goalkeeper_Player: return i->player.Goalkeeper.get();
    case Sweeper_Player: return i->player.Sweeper.get();
    case Defender_Player: return i->player.Defender.get();
    case DefensiveMidfielder_Player: return i->player.DefensiveMidfielder.get();
    case Midfielder_Player: return i->player.Midfielder.get();
    case AttackingMidfielder_Player: return i->player.AttackingMidfielder.get();
    case Attacker_Player: return i->player.Attacker.get();
    case WingBack_Player: return i->player.WingBack.get();
    case RightSide: return i->player.RightSide.get();
    case LeftSide: return i->player.LeftSide.get();
    case Central: return i->player.Central.get();
    case FreeRole: return i->player.FreeRole.get();
    case Acceleration: return i->player.Acceleration.get();
    case Aggression: return i->player.Aggression.get();
    case Agility: return i->player.Agility.get();
    case Anticipation: return i->player.Anticipation.get();
    case Balance: return i->player.Balance.get();
    case Bravery: return i->player.Bravery.get();
    case Consistency: return i->player.Consistency.get();
    case Corners: return i->player.Corners.get();
    case Crossing: return i->player.Crossing.get();
    case Decisions: return i->player.Decisions.get();
    case Dirtiness: return i->player.Dirtiness.get();
    case Dribbling: return i->player.Dribbling.get();
    case Finishing: return i->player.Finishing.get();
    case Flair: return i->player.Flair.get();
    case FreeKicks: return i->player.FreeKicks.get();
    case Handling: return i->player.Handling.get();
    case Heading: return i->player.Heading.get();
    case ImportantMatches: return i->player.ImportantMatches.get();
    case InjuryProneness: return i->player.InjuryProneness.get();
    case Jumping: return i->player.Jumping.get();
    case Leadership: return i->player.Leadership.get();
    case LeftFoot: return i->player.LeftFoot.get();
    case LongShots: return i->player.LongShots.get();
    case Marking: return i->player.Marking.get();
    case Movement: return i->player.Movement.get();
    case NaturalFitness: return i->player.NaturalFitness.get();
    case OneOnOnes: return i->player.OneOnOnes.get();
    case Pace: return i->player.Pace.get();
    case Passing: return i->player.Passing.get();
    case Penalties: return i->player.Penalties.get();
    case Positioning: return i->player.Positioning.get();
    case Reflexes: return i->player.Reflexes.get();
    case RightFoot: return i->player.RightFoot.get();
    case Stamina: return i->player.Stamina.get();
    case Strength: return i->player.Strength.get();
    case Tackling: return i->player.Tackling.get();
    case Teamwork: return i->player.Teamwork.get();
    case Technique: return i->player.Technique.get();
    case ThrowIns: return i->player.ThrowIns.get();
    case Versatility: return i->player.Versatility.get();
    case Vision: return i->player.Vision.get();
    case WorkRate: return i->player.WorkRate.get();

    case Morale: return i->player.Morale.get();

    }

    return QVariant();
}

// --- Get prefernces data --- //
QVariant StaffModel::data_Preferences(Staff *i, const qint32 &col) const
{
    switch (col) {

    case FavouriteClubs1: return i->preferences.FavouriteClubs1.get();
    case FavouriteClubs2: return i->preferences.FavouriteClubs2.get();
    case FavouriteClubs3: return i->preferences.FavouriteClubs3.get();
    case DislikedClubs1: return i->preferences.DislikedClubs1.get();
    case DislikedClubs2: return i->preferences.DislikedClubs2.get();
    case DislikedClubs3: return i->preferences.DislikedClubs3.get();
    case FavouriteStaff1: return i->preferences.FavouriteStaff1.get();
    case FavouriteStaff2: return i->preferences.FavouriteStaff2.get();
    case FavouriteStaff3: return i->preferences.FavouriteStaff3.get();
    case DislikedStaff1: return i->preferences.DislikedStaff1.get();
    case DislikedStaff2: return i->preferences.DislikedStaff2.get();
    case DislikedStaff3: return i->preferences.DislikedStaff3.get();
    }

    return QVariant();
}

// --- Get staff data --- //
QVariant StaffModel::data_Staff(Staff *i, const qint32 &col) const
{
    switch(col) {

    case DisplayText:
        return i->getDisplayText();

    case Identifier:
        return i->getIdentifier();

    case Id:
        return i->ID.get();

    case FirstName: return i->FirstNameText.get();
    case SecondName: return i->SecondNameText.get();
    case CommonName: return i->CommonNameText.get();
    case DateOfBirth: return i->DateOfBirth.get();
    case YearOfBirth: return i->YearOfBirth.get();
    case Nation: return i->Nation.get();
    case SecondNation: return i->SecondNation.get();
    case InternationalApps: return i->InternationalApps.get();
    case InternationalGoals: return i->InternationalGoals.get();
    case NationContracted: return i->NationContracted.get();
    case JobForNation: return i->JobForNation.get();
    case DateJoinedNation: return i->DateJoinedNation.get();
    case ContractExpiresNation: return i->ContractExpiresNation.get();
    case ClubContracted: return i->ClubContracted.get();
    case JobForClub: return i->JobForClub.get();
    case DateJoinedClub: return i->DateJoinedClub.get();
    case ContractExpiresClub: return i->ContractExpiresClub.get();
    case EstimatedWage: return i->EstimatedWage.get();
    case EstimatedValue: return i->EstimatedValue.get();
    case Adaptability: return i->Adaptability.get();
    case Ambition: return i->Ambition.get();
    case Determination: return i->Determination.get();
    case Loyalty: return i->Loyalty.get();
    case Pressure: return i->Pressure.get();
    case Professionalism: return i->Professionalism.get();
    case Sportsmanship: return i->Sportsmanship.get();
    case Temperament: return i->Temperament.get();
    case PlayingSquad: return i->PlayingSquad.get();
    case Classification: return i->Classification.get();
    case ClubValuation: return i->ClubValuation.get();
    case PlayerData: return i->PlayerData_Id.get();
    case Preferences: return i->Preferences_Id.get();
    case NonPlayerData: return i->NonPlayerData_Id.get();
    case EuroSquadFlag: return i->EuroSquadFlag.get();
    }

    return QVariant();
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set data --- //
bool StaffModel::setData(const QModelIndex &index, const QVariant &value, qint32 role)
{
    // Validate the data before making any changes to the underlying data
    bool result = this->validate(index, value, role);

    if(result == false)
        return false;

    Staff *i = &(*m_Data)[index.row()];

    const qint32 col = index.column();

    if(col <= LAST_STAFF_ITEM)
        result = this->setData_Staff(i, col, value);
    else if(col <= LAST_NON_PLAYER_ITEM)
        result = this->setData_NonPlayer(i, col, value);
    else if(col <= LAST_PLAYER_ITEM)
        result = this->setData_Player(i, col, value);
    else if(col <= LAST_PREFERENCES_ITEM)
        result = this->setData_Preferences(i, col, value);
    else
        return false;

    // Update the display text if a name has been edited
    if(col >= FirstName && col <= CommonName) {
        emit dataChanged(this->index(index.row(), DisplayText),
                         this->index(index.row(), DisplayText));
    }

    emit dataChanged(index, index);
    return result;
}

// --- Set non-player data --- //
bool StaffModel::setData_NonPlayer(Staff *i, const qint32 &col, const QVariant &value)
{
    switch(col) {

    case CurrentAbility_NonPlayer: i->nonplayer.CurrentAbility.set(value); break;
    case PotentialAbility_NonPlayer: i->nonplayer.PotentialAbility.set(value); break;
    case HomeReputation_NonPlayer: i->nonplayer.HomeReputation.set(value); break;
    case CurrentReputation_NonPlayer: i->nonplayer.CurrentReputation.set(value); break;
    case WorldReputation_NonPlayer: i->nonplayer.WorldReputation.set(value); break;
    case Attacking: i->nonplayer.Attacking.set(value); break;
    case Business: i->nonplayer.Business.set(value); break;
    case Coaching: i->nonplayer.Coaching.set(value); break;
    case CoachingGks: i->nonplayer.CoachingGks.set(value); break;
    case CoachingTechnique: i->nonplayer.CoachingTechnique.set(value); break;
    case Directness: i->nonplayer.Directness.set(value); break;
    case Discipline: i->nonplayer.Discipline.set(value); break;
    case FreeRoles: i->nonplayer.FreeRoles.set(value); break;
    case Interference: i->nonplayer.Interference.set(value); break;
    case Judgement: i->nonplayer.Judgement.set(value); break;
    case JudgingPotential: i->nonplayer.JudgingPotential.set(value); break;
    case ManHandling: i->nonplayer.ManHandling.set(value); break;
    case Marking: i->nonplayer.Marking.set(value); break;
    case Motivating: i->nonplayer.Motivating.set(value); break;
    case Offside: i->nonplayer.Offside.set(value); break;
    case Patience: i->nonplayer.Patience.set(value); break;
    case Physiotherapy: i->nonplayer.Physiotherapy.set(value); break;
    case Pressing: i->nonplayer.Pressing.set(value); break;
    case Resources: i->nonplayer.Resources.set(value); break;
    case Tactics: i->nonplayer.Tactics.set(value); break;
    case Youngsters: i->nonplayer.Youngsters.set(value); break;
    case Goalkeeper_NonPlayer: i->nonplayer.Goalkeeper.set(value); break;
    case Sweeper_NonPlayer: i->nonplayer.Sweeper.set(value); break;
    case Defender_NonPlayer: i->nonplayer.Defender.set(value); break;
    case DefensiveMidfielder_NonPlayer: i->nonplayer.DefensiveMidfielder.set(value); break;
    case Midfielder_NonPlayer: i->nonplayer.Midfielder.set(value); break;
    case AttackingMidfielder_NonPlayer: i->nonplayer.AttackingMidfielder.set(value); break;
    case Attacker_NonPlayer: i->nonplayer.Attacker.set(value); break;
    case WingBack_NonPlayer: i->nonplayer.WingBack.set(value); break;
    case FormationPreferred: i->nonplayer.FormationPreferred.set(value); break;

    }

    return true;
}

// --- Set Player data --- //
bool StaffModel::setData_Player(Staff *i, const qint32 &col, const QVariant &value)
{
    switch(col) {

    case SquadNumber: i->player.SquadNumber.set(value); break;
    case CurrentAbility_Player: i->player.CurrentAbility.set(value); break;
    case PotentialAbility_Player: i->player.PotentialAbility.set(value); break;
    case HomeReputation_Player: i->player.HomeReputation.set(value); break;
    case CurrentReputation_Player: i->player.CurrentReputation.set(value); break;
    case WorldReputation_Player: i->player.WorldReputation.set(value); break;
    case Goalkeeper_Player: i->player.Goalkeeper.set(value); break;
    case Sweeper_Player: i->player.Sweeper.set(value); break;
    case Defender_Player: i->player.Defender.set(value); break;
    case DefensiveMidfielder_Player: i->player.DefensiveMidfielder.set(value); break;
    case Midfielder_Player: i->player.Midfielder.set(value); break;
    case AttackingMidfielder_Player: i->player.AttackingMidfielder.set(value); break;
    case Attacker_Player: i->player.Attacker.set(value); break;
    case WingBack_Player: i->player.WingBack.set(value); break;
    case RightSide: i->player.RightSide.set(value); break;
    case LeftSide: i->player.LeftSide.set(value); break;
    case Central: i->player.Central.set(value); break;
    case FreeRole: i->player.FreeRole.set(value); break;
    case Acceleration: i->player.Acceleration.set(value); break;
    case Aggression: i->player.Aggression.set(value); break;
    case Agility: i->player.Agility.set(value); break;
    case Anticipation: i->player.Anticipation.set(value); break;
    case Balance: i->player.Balance.set(value); break;
    case Bravery: i->player.Bravery.set(value); break;
    case Consistency: i->player.Consistency.set(value); break;
    case Corners: i->player.Corners.set(value); break;
    case Crossing: i->player.Crossing.set(value); break;
    case Decisions: i->player.Decisions.set(value); break;
    case Dirtiness: i->player.Dirtiness.set(value); break;
    case Dribbling: i->player.Dribbling.set(value); break;
    case Finishing: i->player.Finishing.set(value); break;
    case Flair: i->player.Flair.set(value); break;
    case FreeKicks: i->player.FreeKicks.set(value); break;
    case Handling: i->player.Handling.set(value); break;
    case Heading: i->player.Heading.set(value); break;
    case ImportantMatches: i->player.ImportantMatches.set(value); break;
    case InjuryProneness: i->player.InjuryProneness.set(value); break;
    case Jumping: i->player.Jumping.set(value); break;
    case Leadership: i->player.Leadership.set(value); break;
    case LeftFoot: i->player.LeftFoot.set(value); break;
    case LongShots: i->player.LongShots.set(value); break;
    case Marking: i->player.Marking.set(value); break;
    case Movement: i->player.Movement.set(value); break;
    case NaturalFitness: i->player.NaturalFitness.set(value); break;
    case OneOnOnes: i->player.OneOnOnes.set(value); break;
    case Pace: i->player.Pace.set(value); break;
    case Passing: i->player.Passing.set(value); break;
    case Penalties: i->player.Penalties.set(value); break;
    case Positioning: i->player.Positioning.set(value); break;
    case Reflexes: i->player.Reflexes.set(value); break;
    case RightFoot: i->player.RightFoot.set(value); break;
    case Stamina: i->player.Stamina.set(value); break;
    case Strength: i->player.Strength.set(value); break;
    case Tackling: i->player.Tackling.set(value); break;
    case Teamwork: i->player.Teamwork.set(value); break;
    case Technique: i->player.Technique.set(value); break;
    case ThrowIns: i->player.ThrowIns.set(value); break;
    case Versatility: i->player.Versatility.set(value); break;
    case Vision: i->player.Vision.set(value); break;
    case WorkRate: i->player.WorkRate.set(value); break;

    case Morale: i->player.Morale.set(value); break;

    }

    return true;
}

// --- Set preferences data --- //
bool StaffModel::setData_Preferences(Staff *i, const qint32 &col, const QVariant &value)
{
    switch(col) {

    case FavouriteClubs1: i->preferences.FavouriteClubs1.set(value); break;
    case FavouriteClubs2: i->preferences.FavouriteClubs2.set(value); break;
    case FavouriteClubs3: i->preferences.FavouriteClubs3.set(value); break;
    case DislikedClubs1: i->preferences.DislikedClubs1.set(value); break;
    case DislikedClubs2: i->preferences.DislikedClubs2.set(value); break;
    case DislikedClubs3: i->preferences.DislikedClubs3.set(value); break;
    case FavouriteStaff1: i->preferences.FavouriteStaff1.set(value); break;
    case FavouriteStaff2: i->preferences.FavouriteStaff2.set(value); break;
    case FavouriteStaff3: i->preferences.FavouriteStaff3.set(value); break;
    case DislikedStaff1: i->preferences.DislikedStaff1.set(value); break;
    case DislikedStaff2: i->preferences.DislikedStaff2.set(value); break;
    case DislikedStaff3: i->preferences.DislikedStaff3.set(value); break;
    }

    return true;
}
#include <QDebug>
// --- Set staff data --- //
bool StaffModel::setData_Staff(Staff *i, const qint32 &col, const QVariant &value)
{
    switch(col) {

    case DisplayText:
        i->getDisplayText();
        break;

    case Id:
        i->ID.set(value); break;

    case FirstName:
        i->FirstNameText.set(value);
        i->setDisplayText();
        break;

    case SecondName:
        i->SecondNameText.set(value);
        i->setDisplayText();
        break;

    case CommonName:
        i->CommonNameText.set(value);
        i->setDisplayText();
        break;

    //case DateOfBirth: i->DateOfBirth.set(value); break;
    case YearOfBirth: i->YearOfBirth.set(value); break;
    case Nation: i->Nation.set(value); break;
    case SecondNation: i->SecondNation.set(value); break;
    case InternationalApps: i->InternationalApps.set(value); break;
    case InternationalGoals: i->InternationalGoals.set(value); break;
    case NationContracted: i->NationContracted.set(value); break;
    case JobForNation: i->JobForNation.set(value); break;
    //case DateJoinedNation: i->DateJoinedNation.set(value); break;
    //case ContractExpiresNation: i->ContractExpiresNation.set(value); break;
    case ClubContracted: i->ClubContracted.set(value); break;
    case JobForClub: i->JobForClub.set(value); break;
    //case DateJoinedClub: i->DateJoinedClub.set(value); break;
    //case ContractExpiresClub: i->ContractExpiresClub.set(value); break;
    case EstimatedWage: i->EstimatedWage.set(value); break;
    case EstimatedValue: i->EstimatedValue.set(value); break;
    case Adaptability: i->Adaptability.set(value); break;
    case Ambition: i->Ambition.set(value); break;
    case Determination: i->Determination.set(value); break;
    case Loyalty: i->Loyalty.set(value); break;
    case Pressure: i->Pressure.set(value); break;
    case Professionalism: i->Professionalism.set(value); break;
    case Sportsmanship: i->Sportsmanship.set(value); break;
    case Temperament: i->Temperament.set(value); break;
    case PlayingSquad: i->PlayingSquad.set(value); break;
    case Classification: i->Classification.set(value); break;
    case ClubValuation: i->ClubValuation.set(value); break;
    case PlayerData: i->PlayerData_Id.set(value); break;
    case Preferences: i->Preferences_Id.set(value); break;
    case NonPlayerData: i->NonPlayerData_Id.set(value); break;
    case EuroSquadFlag: i->EuroSquadFlag.set(value); break;
    }

    return true;
}


/* ===================== */
/*      Header Data      */
/* ===================== */

// --- Get header --- //
QVariant StaffModel::headerData(qint32 section, Qt::Orientation orientation, qint32 role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if(section <= LAST_STAFF_ITEM)
            return this->headerData_Staff(section);
        else if(section <= LAST_NON_PLAYER_ITEM)
            return this->headerData_NonPlayer(section);
        else if(section <= LAST_PLAYER_ITEM)
            return this->headerData_Player(section);
        else if(section <= LAST_PREFERENCES_ITEM)
            return this->headerData_Preferences(section);
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}

// --- Non-player header --- //
QVariant StaffModel::headerData_NonPlayer(const qint32 &section) const
{
    switch(section) {

    case CurrentAbility_NonPlayer: return tr("Current ability (non-player)");
    case PotentialAbility_NonPlayer: return tr("Potential ability (non-player)");
    case HomeReputation_NonPlayer: return tr("Home reputation (non-player)");
    case CurrentReputation_NonPlayer: return tr("Current reputation (non-player)");
    case WorldReputation_NonPlayer: return tr("World reputation (non-player)");
    case Attacking: return tr("Attacking");
    case Business: return tr("Business");
    case Coaching: return tr("Coaching");
    case CoachingGks: return tr("Coaching goalies");
    case CoachingTechnique: return tr("Coaching technique");
    case Directness: return tr("Directness");
    case Discipline: return tr("Discipline");
    case FreeRoles: return tr("Free roles");
    case Interference: return tr("Interference");
    case Judgement: return tr("Judgement");
    case JudgingPotential: return tr("Judging potential");
    case ManHandling: return tr("Man handling");
    case Marking_Player: return tr("Marking (non-player)");
    case Motivating: return tr("Motivating");
    case Offside: return tr("Offside");
    case Patience: return tr("Patience");
    case Physiotherapy: return tr("Physiotherapy");
    case Pressing: return tr("Pressing");
    case Resources: return tr("Resources");
    case Tactics: return tr("Tactics");
    case Youngsters: return tr("Youngsters");
    case Goalkeeper_NonPlayer: return tr("Goalkeeper model");
    case Sweeper_NonPlayer: return tr("Sweeper model");
    case Defender_NonPlayer: return tr("Defender model");
    case DefensiveMidfielder_NonPlayer: return tr("Defensive midfielder model");
    case Midfielder_NonPlayer: return tr("Midfielder model");
    case AttackingMidfielder_NonPlayer: return tr("Attacking midfielder model");
    case Attacker_NonPlayer: return tr("Attacker model");
    case WingBack_NonPlayer: return tr("Wing back model");
    case FormationPreferred: return tr("Preferred formation");
    }

    return QVariant();
}

// --- Player header --- //
QVariant StaffModel::headerData_Player(const qint32 &section) const
{
    switch(section) {

    case SquadNumber: return tr("Squad number");
    case CurrentAbility_Player: return tr("Current ability (player)");
    case PotentialAbility_Player: return tr("Potential ability (player)");
    case HomeReputation_Player: return tr("Home heputation (player)");
    case CurrentReputation_Player: return tr("Current reputation (player)");
    case WorldReputation_Player: return tr("World reputation (player)");
    case Goalkeeper_Player: return tr("Goalkeeper");
    case Sweeper_Player: return tr("Sweeper");
    case Defender_Player: return tr("Defender");
    case DefensiveMidfielder_Player: return tr("Defensive midfielder");
    case Midfielder_Player: return tr("Midfielder");
    case AttackingMidfielder_Player: return tr("Attacking midfielder");
    case Attacker_Player: return tr("Attacker");
    case WingBack_Player: return tr("Wing back");
    case FreeRole: return tr("Free role");
    case RightSide: return tr("Right side");
    case LeftSide: return tr("Left side");
    case Central: return tr("Central");
    case Acceleration: return tr("Acceleration");
    case Aggression: return tr("Aggression");
    case Agility: return tr("Agility");
    case Anticipation: return tr("Anticipation");
    case Balance: return tr("Balance");
    case Bravery: return tr("Bravery");
    case Consistency: return tr("Consistency");
    case Corners: return tr("Corners");
    case Crossing: return tr("Crossing");
    case Decisions: return tr("Decisions");
    case Dirtiness: return tr("Dirtiness");
    case Dribbling: return tr("Dribbling");
    case Finishing: return tr("Finishing");
    case Flair: return tr("Flair");
    case FreeKicks: return tr("Free kicks");
    case Handling: return tr("Handling");
    case Heading: return tr("Heading");
    case ImportantMatches: return tr("Important matches");
    case InjuryProneness: return tr("Injury proneness");
    case Jumping: return tr("Jumping");
    case Leadership: return tr("Leadership");
    case LeftFoot: return tr("Left foot");
    case LongShots: return tr("Long shots");
    case Marking: return tr("Marking");
    case Movement: return tr("Movement");
    case NaturalFitness: return tr("Natural fitness");
    case OneOnOnes: return tr("One on ones");
    case Pace: return tr("Pace");
    case Passing: return tr("Passing");
    case Penalties: return tr("Penalties");
    case Positioning: return tr("Positioning");
    case Reflexes: return tr("Reflexes");
    case RightFoot: return tr("Right foot");
    case Stamina: return tr("Stamina");
    case Strength: return tr("Strength");
    case Tackling: return tr("Tackling");
    case Teamwork: return tr("Teamwork");
    case Technique: return tr("Technique");
    case ThrowIns: return tr("Throw ins");
    case Versatility: return tr("Versatility");
    case Vision: return tr("Vision");
    case WorkRate: return tr("Work rate");
    case Morale: return tr("Morale");
    }

    return QVariant();
}

// --- Preferences header --- //
QVariant StaffModel::headerData_Preferences(const qint32 &section) const
{
    switch(section) {

    case FavouriteClubs1: return tr("Favourite club 1");
    case FavouriteClubs2: return tr("Favourite club 2");
    case FavouriteClubs3: return tr("Favourite club 3");
    case DislikedClubs1: return tr("Disliked club 1");
    case DislikedClubs2: return tr("Disliked club 2");
    case DislikedClubs3: return tr("Disliked club 3");
    case FavouriteStaff1: return tr("Favourite staff 1");
    case FavouriteStaff2: return tr("Favourite staff 2");
    case FavouriteStaff3: return tr("Favourite staff 3");
    case DislikedStaff1: return tr("Disliked staff 1");
    case DislikedStaff2: return tr("Disliked staff 2");
    case DislikedStaff3: return tr("Disliked staff 3");
    }

    return QVariant();
}

// --- Staff header --- //
QVariant StaffModel::headerData_Staff(const qint32 &section) const
{
    switch(section) {

    case DisplayText: return tr("Display Text");
    case Id: return tr("ID");
    case FirstName: return tr("First name");
    case SecondName: return tr("Second name");
    case CommonName: return tr("Common name");
    case DateOfBirth: return tr("Date of birth");
    case YearOfBirth: return tr("Year of birth");
    case Nation: return tr("Nation");
    case SecondNation: return tr("Second nation");
    case InternationalApps: return tr("International apps");
    case InternationalGoals: return tr("International goals");
    case NationContracted: return tr("Nation contracted");
    case JobForNation: return tr("Job for nation");
    case DateJoinedNation: return tr("Date joined nation");
    case ContractExpiresNation: return tr("Contract expires nation");
    case ClubContracted: return tr("Club contracted");
    case JobForClub: return tr("Job for club");
    case DateJoinedClub: return tr("Date joined club");
    case ContractExpiresClub: return tr("Contract expires club");
    case EstimatedWage: return tr("Estimated wage (£)");
    case EstimatedValue: return tr("Estimated value (£)");
    case Adaptability: return tr("Adaptability");
    case Ambition: return tr("Ambition");
    case Determination: return tr("Determination");
    case Loyalty: return tr("Loyalty");
    case Pressure: return tr("Pressure");
    case Professionalism: return tr("Professionalism");
    case Sportsmanship: return tr("Sportsmanship");
    case Temperament: return tr("Temperament");
    case PlayingSquad: return tr("Playing squad");
    case Classification: return tr("Classification");
    case ClubValuation: return tr("Club valuation");
    case PlayerData: return tr("Player data");
    case Preferences: return tr("Preferences");
    case NonPlayerData: return tr("Non player data");
    case EuroSquadFlag: return tr("Euro squad flag");
    }

    return QVariant();
}
