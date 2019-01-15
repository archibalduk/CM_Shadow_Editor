#ifndef STAFF_H
#define STAFF_H

// Qt headers
#include <QDataStream>

// Application headers
#include "../data_types/date.h"

// --- Staff Data --- //
class Staff
{
private:
    // Database data
    qint32 ID;
    qint32 FirstNameId;
    qint32 SecondNameId;
    qint32 CommonNameId;
    Date DateOfBirth;
    qint16 YearOfBirth;
    qint32 Nation;
    qint32 SecondNation;
    quint8 InternationalApps;
    quint8 InternationalGoals;
    qint32 NationContracted;
    qint8 JobForNation;
    Date DateJoinedNation;
    Date ContractExpiresNation;
    qint32 ClubContracted;
    qint8 JobForClub;
    Date DateJoinedClub;
    Date ContractExpiresClub;
    qint32 EstimatedWage;
    qint32 EstimatedValue;
    qint8 Adaptability;
    qint8 Ambition;
    qint8 Determination;
    qint8 Loyalty;
    qint8 Pressure;
    qint8 Professionalism;
    qint8 Sportsmanship;
    qint8 Temperament;
    qint8 PlayingSquad;
    qint8 Classification;
    qint8 ClubValuation;
    qint32 PlayerData;
    qint32 Preferences; // Version 0x02 - New ptr type
    qint32 NonPlayerData;

    // Runtime data
    qint8 EuroSquadFlag;

public:
    Staff();
};

#endif // STAFF_H
