#ifndef MODEL_STAFF_H
#define MODEL_STAFF_H

// Application headers
#include "model.h"
#include "../db_schema/staff.h"

// --- Staff Model --- //
class StaffModel : public Model<Staff>
{
public:
    // Constructor
    StaffModel(QObject *parent = nullptr);

    // Get data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant data_NonPlayer(Staff *i, const qint32 &col) const;
    QVariant data_Player(Staff *i, const qint32 &col) const;
    QVariant data_Preferences(Staff *i, const qint32 &col) const;
    QVariant data_Staff(Staff *i, const qint32 &col) const;

    // Set data
    bool setData(const QModelIndex &index, const QVariant & value, qint32 role = Qt::EditRole) Q_DECL_OVERRIDE;
    bool setData_NonPlayer(Staff *i, const qint32 &col, const QVariant & value);
    bool setData_Player(Staff *i, const qint32 &col, const QVariant & value);
    bool setData_Preferences(Staff *i, const qint32 &col, const QVariant & value);
    bool setData_Staff(Staff *i, const qint32 &col, const QVariant & value);

    // Header
    QVariant headerData(qint32 section, Qt::Orientation orientation, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData_NonPlayer(const qint32 &section) const;
    QVariant headerData_Player(const qint32 &section) const;
    QVariant headerData_Preferences(const qint32 &section) const;
    QVariant headerData_Staff(const qint32 &section) const;

    // Columns
    enum ENUM_COLUMNS {
        // Staff
        FirstName = FIRST_ITEM,
        SecondName,
        CommonName,
        DateOfBirth,
        YearOfBirth,
        Nation,
        SecondNation,
        InternationalApps,
        InternationalGoals,
        NationContracted,
        JobForNation,
        DateJoinedNation,
        ContractExpiresNation,
        ClubContracted,
        JobForClub,
        DateJoinedClub,
        ContractExpiresClub,
        EstimatedWage,
        EstimatedValue,
        Adaptability,
        Ambition,
        Determination,
        Loyalty,
        Pressure,
        Professionalism,
        Sportsmanship,
        Temperament,
        PlayingSquad,
        Classification,
        ClubValuation,
        PlayerData,
        Preferences,
        NonPlayerData,
        EuroSquadFlag,
        LAST_STAFF_ITEM = EuroSquadFlag,
        // Non-player
        CurrentAbility_NonPlayer,
        PotentialAbility_NonPlayer,
        HomeReputation_NonPlayer,
        CurrentReputation_NonPlayer,
        WorldReputation_NonPlayer,
        Attacking,
        Business,
        Coaching,
        CoachingGks,
        CoachingTechnique,
        Directness,
        Discipline,
        FreeRoles,
        Interference,
        Judgement,
        JudgingPotential,
        ManHandling,
        Marking_Player,
        Motivating,
        Offside,
        Patience,
        Physiotherapy,
        Pressing,
        Resources,
        Tactics,
        Youngsters,
        Goalkeeper_NonPlayer,
        Sweeper_NonPlayer,
        Defender_NonPlayer,
        DefensiveMidfielder_NonPlayer,
        Midfielder_NonPlayer,
        AttackingMidfielder_NonPlayer,
        Attacker_NonPlayer,
        WingBack_NonPlayer,
        FormationPreferred,
        LAST_NON_PLAYER_ITEM = FormationPreferred,
        // Player
        SquadNumber,
        CurrentAbility_Player,
        PotentialAbility_Player,
        HomeReputation_Player,
        CurrentReputation_Player,
        WorldReputation_Player,
        Goalkeeper_Player,
        Sweeper_Player,
        Defender_Player,
        DefensiveMidfielder_Player,
        Midfielder_Player,
        AttackingMidfielder_Player,
        Attacker_Player,
        WingBack_Player,
        FreeRole,
        RightSide,
        LeftSide,
        Central,
        Acceleration,
        Aggression,
        Agility,
        Anticipation,
        Balance,
        Bravery,
        Consistency,
        Corners,
        Crossing,
        Decisions,
        Dirtiness,
        Dribbling,
        Finishing,
        Flair,
        FreeKicks,
        Handling,
        Heading,
        ImportantMatches,
        InjuryProneness,
        Jumping,
        Leadership,
        LeftFoot,
        LongShots,
        Marking,
        Movement,
        NaturalFitness,
        OneOnOnes,
        Pace,
        Passing,
        Penalties,
        Positioning,
        Reflexes,
        RightFoot,
        Stamina,
        Strength,
        Tackling,
        Teamwork,
        Technique,
        ThrowIns,
        Versatility,
        Vision,
        WorkRate,
        Morale,
        LAST_PLAYER_ITEM = Morale,
        // Preferences
        FavouriteClubs1,
        FavouriteClubs2,
        FavouriteClubs3,
        DislikedClubs1,
        DislikedClubs2,
        DislikedClubs3,
        FavouriteStaff1,
        FavouriteStaff2,
        FavouriteStaff3,
        DislikedStaff1,
        DislikedStaff2,
        DislikedStaff3,
        LAST_PREFERENCES_ITEM = DislikedStaff3,
        COLUMN_COUNT
    };
};

#endif // MODEL_STAFF_H
