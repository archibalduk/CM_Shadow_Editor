#include "club_comp.h"

// --- Static data --- //
bool ClubComp::s_NextItemIsDomestic = true; // Flags whether the next item to be read/written is domestic or international

/* =========================== */
/*      Club Competitions      */
/* =========================== */

// --- Default constructor -- //
ClubComp::ClubComp() :
    m_IsDomestic(s_NextItemIsDomestic)
{

}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Read data --- //
void ClubComp::read(QDataStream &in)
{
    ID.read(in);
    Name.read(in, String::STANDARD_TEXT_LENGTH);
    GenderName.read(in);
    NameShort.read(in, String::SHORT_TEXT_LENGTH);
    GenderNameShort.read(in);
    NameThreeLetter.read(in, String::THREE_LETTER_LENGTH);
    Scope.read(in);
    Selected.read(in);
    Continent.read(in);
    Nation.read(in);
    ForegroundColour.read(in);
    BackgroundColour.read(in);
    Reputation.read(in);
}

// --- Write data --- //
void ClubComp::write(QDataStream &out)
{
    ID.write(out);
    Name.write(out, String::STANDARD_TEXT_LENGTH);
    GenderName.write(out);
    NameShort.write(out, String::SHORT_TEXT_LENGTH);
    GenderNameShort.write(out);
    NameThreeLetter.write(out, String::THREE_LETTER_LENGTH);
    Scope.write(out);
    Selected.write(out);
    Continent.write(out);
    Nation.write(out);
    ForegroundColour.write(out);
    BackgroundColour.write(out);
    Reputation.write(out);
}


/* ================ */
/*      History     */
/* ================ */

// --- Add history --- //
void ClubComp::addHistory(const ClubCompHistory &history)
{
    History.add(history);
}

// --- Write history --- //
qint32 ClubComp::writeHistory(QDataStream &out, const bool &domestic)
{
    if(m_IsDomestic == domestic) {
        History.write(out);
        return History.size();
    }

    return 0;
}
