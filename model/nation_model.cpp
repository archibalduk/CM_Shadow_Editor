#include "nation_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/nation_data.h"

// --- Constructor --- //
NationModel::NationModel(QObject *parent) :
    Model<Nation>(Database::nations.Data, COLUMN_COUNT, ShadowCommon::NATIONS, parent)
{

}

// --- Get data --- //
QVariant NationModel::data(const QModelIndex &index, qint32 role) const
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
        Nation *i = &(*m_Data)[index.row()];

        switch(col) {

        case DisplayText:
            return i->Name.get();

        case Identifier:
            return QVariant();

        case Id:
            return i->ID.get();

        case Name: return i->Name.get();
        case GenderName: return i->GenderName.get();
        case NameShort: return i->NameShort.get();
        case GenderNameShort: return i->GenderNameShort.get();
        case NameThreeLetter: return i->NameThreeLetter.get();
        case NameNationality: return i->NameNationality.get();
        case Continent: return i->Continent.get();
        case Region: return i->Region.get();
        case ActualRegion: return i->ActualRegion.get();
        case FirstLanguage: return i->FirstLanguage.get();
        case SecondLanguage: return i->SecondLanguage.get();
        case ThirdLanguage: return i->ThirdLanguage.get();
        case CapitalCity: return i->CapitalCity.get();
        case StateOfDevelopment: return i->StateOfDevelopment.get();
        case GroupMembership: return i->GroupMembership.get();
        case NationalStadium: return i->NationalStadium.get();
        case GameImportance: return i->GameImportance.get();
        case LeagueStandard: return i->LeagueStandard.get();
        case NumberClubs: return i->NumberClubs.get();
        case NumberStaff: return i->NumberStaff.get();
        case SeasonUpdateDay: return i->SeasonUpdateDay.get();
        case Reputation: return i->Reputation.get();
        case ForegroundColour1: return i->ForegroundColour1.get();
        case BackgroundColour1: return i->BackgroundColour1.get();
        case ForegroundColour2: return i->ForegroundColour2.get();
        case BackgroundColour2: return i->BackgroundColour2.get();
        case ForegroundColour3: return i->ForegroundColour3.get();
        case BackgroundColour3: return i->BackgroundColour3.get();
        case FIFACoefficient: return i->FIFACoefficient.get();
        case FIFACoefficient91: return i->FIFACoefficient91.get();
        case FIFACoefficient92: return i->FIFACoefficient92.get();
        case FIFACoefficient93: return i->FIFACoefficient93.get();
        case FIFACoefficient94: return i->FIFACoefficient94.get();
        case FIFACoefficient95: return i->FIFACoefficient95.get();
        case FIFACoefficient96: return i->FIFACoefficient96.get();
        case UEFACoefficient91: return i->UEFACoefficient91.get();
        case UEFACoefficient92: return i->UEFACoefficient92.get();
        case UEFACoefficient93: return i->UEFACoefficient93.get();
        case UEFACoefficient94: return i->UEFACoefficient94.get();
        case UEFACoefficient95: return i->UEFACoefficient95.get();
        case UEFACoefficient96: return i->UEFACoefficient96.get();
        case Rivals1: return i->Rivals1.get();
        case Rivals2: return i->Rivals2.get();
        case Rivals3: return i->Rivals3.get();
        case LeagueSelected: return i->LeagueSelected.get();
        case ShortlistOffset: return i->ShortlistOffset.get();
        case GamesPlayed: return i->GamesPlayed.get();

        }
    }

    return QVariant();
}
