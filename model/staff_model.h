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

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant & value, qint32 role = Qt::EditRole) Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(qint32 section, Qt::Orientation orientation, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
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
        COLUMN_COUNT
    };
};

#endif // MODEL_STAFF_H
