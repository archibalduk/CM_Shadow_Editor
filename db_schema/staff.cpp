#include "staff.h"


/* ==================== */
/*      Staff Data      */
/* ==================== */

// --- Default constructor --- //
Staff::Staff()
{

}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void Staff::read(QDataStream &in)
{
    ID.read(in);
    FirstNameId.read(in);
    SecondNameId.read(in);
    CommonNameId.read(in);
    DateOfBirth.read(in);
    YearOfBirth.read(in);
    Nation.read(in);
    SecondNation.read(in);
    InternationalApps.read(in);
    InternationalGoals.read(in);
    NationContracted.read(in);
    JobForNation.read(in);
    DateJoinedNation.read(in);
    ContractExpiresNation.read(in);
    ClubContracted.read(in);
    JobForClub.read(in);
    DateJoinedClub.read(in);
    ContractExpiresClub.read(in);
    EstimatedWage.read(in);
    EstimatedValue.read(in);
    Adaptability.read(in);
    Ambition.read(in);
    Determination.read(in);
    Loyalty.read(in);
    Pressure.read(in);
    Professionalism.read(in);
    Sportsmanship.read(in);
    Temperament.read(in);
    PlayingSquad.read(in);
    Classification.read(in);
    ClubValuation.read(in);
    PlayerData.read(in);
    Preferences.read(in); // Version 0x02 - New ptr type
    NonPlayerData.read(in);

    // Runtime data
    EuroSquadFlag.read(in);

    // Set data
    this->setDisplayText();
    this->setIdentifier();
}

// --- Write data --- //
void Staff::write(QDataStream &out)
{
    ID.write(out);
    FirstNameId.write(out);
    SecondNameId.write(out);
    CommonNameId.write(out);
    DateOfBirth.write(out);
    YearOfBirth.write(out);
    Nation.write(out);
    SecondNation.write(out);
    InternationalApps.write(out);
    InternationalGoals.write(out);
    NationContracted.write(out);
    JobForNation.write(out);
    DateJoinedNation.write(out);
    ContractExpiresNation.write(out);
    ClubContracted.write(out);
    JobForClub.write(out);
    DateJoinedClub.write(out);
    ContractExpiresClub.write(out);
    EstimatedWage.write(out);
    EstimatedValue.write(out);
    Adaptability.write(out);
    Ambition.write(out);
    Determination.write(out);
    Loyalty.write(out);
    Pressure.write(out);
    Professionalism.write(out);
    Sportsmanship.write(out);
    Temperament.write(out);
    PlayingSquad.write(out);
    Classification.write(out);
    ClubValuation.write(out);
    PlayerData.write(out);
    Preferences.write(out); // Version 0x02 - New ptr type
    NonPlayerData.write(out);

    // Runtime data
    EuroSquadFlag.write(out);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Display text --- //
QString Staff::getDisplayText()
{
    return m_DisplayText;
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Display text --- //
void Staff::setDisplayText()
{
    // For performance reasons, it is much quicker to set the Display Text rather than to generate it dynamically
    //if(CommonNameId.isNone())
        m_DisplayText = QString("%1, %2").arg(SecondNameId.getText()).arg(FirstNameId.getText());
    //else
        //m_DisplayText = CommonNameId.getText();
}

// --- Identifier --- //
void Staff::setIdentifier()
{
    // This should be set when the record is initially created and then left as is because it will then be used to track all edits
    // regardless of what changes might be made to the person's name or date of birth
    m_Identifier = QString("%1 %2").arg(FirstNameId.getText()).arg(SecondNameId.getText());
}
