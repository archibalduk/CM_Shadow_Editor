#include "official.h"


/* ======================= */
/*      Official Data      */
/* ======================= */

// --- Default constructor --- //
Official::Official()
{
    FirstNameText.setCapacity(String::STANDARD_TEXT_LENGTH);
    SecondNameText.setCapacity(String::STANDARD_TEXT_LENGTH);
}


/* ================= */
/*      File I/O     */
/* ================= */

// --- Read data --- //
void Official::read(QDataStream &in)
{
    ID.read(in);
    FirstNameId.read(in);
    SecondNameId.read(in);
    DateOfBirth.read(in);
    YearOfBirth.read(in);
    Nation.read(in);
    City.read(in);
    CurrentAbility.read(in);
    PotentialAbility.read(in);
    Reputation.read(in);
    AllowingFlow.read(in);
    Discipline.read(in);
    ImportantMatches.read(in);
    Pressure.read(in);
    Refereeing.read(in);
    RunningLine.read(in);
    Timekeeping.read(in);

    // Set data
    this->setDisplayText();
    this->setNameCache();
    this->setIdentifier();
}

// --- Write data --- //
void Official::write(QDataStream &out)
{
    ID.write(out);
    FirstNameId.write(out);
    SecondNameId.write(out);
    DateOfBirth.write(out);
    YearOfBirth.write(out);
    Nation.write(out);
    City.write(out);
    CurrentAbility.write(out);
    PotentialAbility.write(out);
    Reputation.write(out);
    AllowingFlow.write(out);
    Discipline.write(out);
    ImportantMatches.write(out);
    Pressure.write(out);
    Refereeing.write(out);
    RunningLine.write(out);
    Timekeeping.write(out);
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Display text --- //
void Official::setDisplayText()
{
    // For performance reasons, it is much quicker to set the Display Text rather than to generate it dynamically
    m_DisplayText = QString("%1, %2").arg(SecondNameText.get()).arg(FirstNameText.get());
}

// --- Identifier --- //
void Official::setIdentifier()
{
    // This should be set when the record is initially created and then left as is because it will then be used to track all edits
    // regardless of what changes might be made to the person's name or date of birth
    m_Identifier = QString("%1 %2").arg(FirstNameText.get()).arg(SecondNameText.get());
}

// --- Cache names --- //
void Official::setNameCache()
{
    FirstNameText.set(FirstNameId.getText());
    SecondNameText.set(SecondNameId.getText());
}
