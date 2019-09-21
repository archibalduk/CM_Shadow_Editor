#include "staff_model.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/staff_data.h"

// --- Constructor --- //
StaffModel::StaffModel(QObject *parent) :
    Model<Staff>(Database::staff.Data, COLUMN_COUNT, ShadowCommon::STAFF, parent)
{

}

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

        switch(col) {

        case DisplayText:
            return i->getDisplayText();

        case Identifier:
            return i->getIdentifier();

        case Id:
            return i->ID.get();

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
        case PlayerData: return i->PlayerData.get();
        case Preferences: return i->Preferences.get();
        case NonPlayerData: return i->NonPlayerData.get();
        case EuroSquadFlag: return i->EuroSquadFlag.get();
        }
    }

    return QVariant();
}

// --- Set data --- //
bool StaffModel::setData(const QModelIndex &index, const QVariant &value, qint32 role)
{
    // Validate the data before making any changes to the underlying data
    const bool result = this->validate(index, value, role);

    if(result == false)
        return false;

    Staff *i = &(*m_Data)[index.row()];

    switch(index.column()) {

    case DisplayText:
        i->getDisplayText();
        break;

    case Id:
        i->ID.set(value); break;

    //case DateOfBirth: i->DateOfBirth.set(value); break;
    case YearOfBirth: i->YearOfBirth.set(value); break;
    //case Nation: i->Nation.set(value); break;
    //case SecondNation: i->SecondNation.set(value); break;
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
    case PlayerData: i->PlayerData.set(value); break;
    case Preferences: i->Preferences.set(value); break;
    case NonPlayerData: i->NonPlayerData.set(value); break;
    case EuroSquadFlag: i->EuroSquadFlag.set(value); break;
    }

    emit dataChanged(index, index);
    return true;
}

// --- Get header --- //
QVariant StaffModel::headerData(qint32 section, Qt::Orientation orientation, qint32 role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section) {

        case DisplayText: return s_DisplayText;
        case Id: return s_Id;
        case FirstName: return tr("First Name");
        case SecondName: return tr("Second Name");
        case CommonName: return tr("Common Name");
        case DateOfBirth: return tr("DateOfBirth");
        case YearOfBirth: return tr("YearOfBirth");
        case Nation: return s_Nation;
        case SecondNation: return tr("SecondNation");
        case InternationalApps: return tr("InternationalApps");
        case InternationalGoals: return tr("InternationalGoals");
        case NationContracted: return tr("NationContracted");
        case JobForNation: return tr("JobForNation");
        case DateJoinedNation: return tr("DateJoinedNation");
        case ContractExpiresNation: return tr("ContractExpiresNation");
        case ClubContracted: return tr("ClubContracted");
        case JobForClub: return tr("JobForClub");
        case DateJoinedClub: return tr("DateJoinedClub");
        case ContractExpiresClub: return tr("ContractExpiresClub");
        case EstimatedWage: return tr("EstimatedWage");
        case EstimatedValue: return tr("EstimatedValue");
        case Adaptability: return tr("Adaptability");
        case Ambition: return tr("Ambition");
        case Determination: return tr("Determination");
        case Loyalty: return tr("Loyalty");
        case Pressure: return tr("Pressure");
        case Professionalism: return tr("Professionalism");
        case Sportsmanship: return tr("Sportsmanship");
        case Temperament: return tr("Temperament");
        case PlayingSquad: return tr("PlayingSquad");
        case Classification: return tr("Classification");
        case ClubValuation: return tr("ClubValuation");
        case PlayerData: return tr("PlayerData");
        case Preferences: return tr("Preferences");
        case NonPlayerData: return tr("NonPlayerData");
        case EuroSquadFlag: return tr("EuroSquadFlag");
        }
    }

    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
        return section+1;

    return QVariant();
}
