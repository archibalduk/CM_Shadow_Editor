#ifndef MODEL_NATION_H
#define MODEL_NATION_H

// Application headers
#include "model.h"
#include "../db_schema/nation.h"

// --- Nation Model (base class) --- //
class NationModel : public Model<Nation>
{
public:
    // Constructor
    NationModel(QObject *parent = nullptr);

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        Name = FIRST_ITEM,
        GenderName,
        NameShort,
        GenderNameShort,
        NameThreeLetter,
        NameNationality,
        Continent,
        Region,
        ActualRegion,
        FirstLanguage,
        SecondLanguage,
        ThirdLanguage,
        CapitalCity,
        StateOfDevelopment,
        GroupMembership,
        NationalStadium,
        GameImportance,
        LeagueStandard,
        NumberClubs,
        NumberStaff,
        SeasonUpdateDay,
        Reputation,
        ForegroundColour1,
        BackgroundColour1,
        ForegroundColour2,
        BackgroundColour2,
        ForegroundColour3,
        BackgroundColour3,
        FIFACoefficient,
        FIFACoefficient91,
        FIFACoefficient92,
        FIFACoefficient93,
        FIFACoefficient94,
        FIFACoefficient95,
        FIFACoefficient96,
        UEFACoefficient91,
        UEFACoefficient92,
        UEFACoefficient93,
        UEFACoefficient94,
        UEFACoefficient95,
        UEFACoefficient96,
        Rivals1,
        Rivals2,
        Rivals3,
        LeagueSelected,
        ShortlistOffset,
        GamesPlayed,
        COLUMN_COUNT
    };
};

#endif // MODEL_NATION_H
