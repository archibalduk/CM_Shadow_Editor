#ifndef EDITOR_STAFF_H
#define EDITOR_STAFF_H

// Qt headers
#include <QVector>

// Application headers
#include "../editor_ui/editor_ui.h"
#include "../editor_ui/inputs/date_edit.h"
#include "../editor_ui/inputs/line_edit.h"
#include "../editor_ui/inputs/pointer_combo_edit.h"
#include "../editor_ui/inputs/pointer_line_edit.h"
#include "../editor_ui/inputs/spin_box.h"

// --- Staff editor --- //
class EditorStaff : public EditorUi
{
public:
    // Constructor
    EditorStaff(MainUi *ui);

private:
    // Inputs
    QVector<DateEdit*> m_DateEdit;
    QVector<LineEdit*> m_LineEdit;
    QVector<PointerComboEdit*> m_PointerComboEdit;
    QVector<PointerLineEdit*> m_PointerLineEdit;
    QVector<SpinBox*> m_SpinBoxEdit;

    // Screens
    void initScreenBasicData();
    void initScreenNonPlayerAttributes();
    void initScreenNonPlayerTypes();
    void initScreenPlayerAttributes();
    void initScreenPlayerHistory();
    void initScreenPlayerPositions();
    void initScreenStaffPreferences();
    void initScreenTraits();

    // DateEdit positions
    enum ENUM_DATE_EDIT_POSITIONS {
        DATE_OF_BIRTH,
        DATE_JOINED_CLUB,
        CONTRACT_EXPIRES_CLUB,
        DATE_JOINED_NATION,
        CONTRACT_EXPIRES_NATION,
        TOTAL_DATE_EDIT_COUNT
    };

    // LineEdit positions
    enum ENUM_LINE_EDIT_POSITIONS {
        // Staff
        FIRST_NAME,
        SECOND_NAME,
        COMMON_NAME,
        YEAR_OF_BIRTH,
        INTERNATIONAL_APPEARANCES,
        INTERNATIONAL_GOALS,
        ESTIMATED_WAGE,
        ESTIMATED_VALUE,
        TOTAL_LINE_EDIT_COUNT
    };

    // PointerComboEdit positions
    enum ENUM_POINTER_COMBO_EDIT_POSITIONS {
        NATION,
        SECOND_NATION,
        CLASSIFICATION,
        CLUB_CONTRACTED,
        JOB_FOR_CLUB,
        PLAYING_SQUAD,
        NATION_CONTRACTED,
        JOB_FOR_NATION,        
        FAVOURITECLUBS1,
        FAVOURITECLUBS2,
        FAVOURITECLUBS3,
        DISLIKEDCLUBS1,
        DISLIKEDCLUBS2,
        DISLIKEDCLUBS3,
        TOTAL_POINTER_COMBO_EDIT_COUNT
    };

    // PointerEdit positions
    enum ENUM_POINTER_LINE_EDIT_POSITIONS {
        // Preferences
        FAVOURITESTAFF1,
        FAVOURITESTAFF2,
        FAVOURITESTAFF3,
        DISLIKEDSTAFF1,
        DISLIKEDSTAFF2,
        DISLIKEDSTAFF3,
        TOTAL_POINTER_LINE_EDIT_COUNT
    };

    // SpinBox positions
    enum ENUM_SPIN_BOX_EDIT_POSITIONS {
        // Staff
        ADAPTABILITY,
        AMBITION,
        DETERMINATION,
        LOYALTY,
        PRESSURE,
        PROFESSIONALISM,
        SPORTSMANSHIP,
        TEMPERAMENT,
        // Non-player
        CURRENTABILITY_NONPLAYER,
        POTENTIALABILITY_NONPLAYER,
        HOMEREPUTATION_NONPLAYER,
        CURRENTREPUTATION_NONPLAYER,
        WORLDREPUTATION_NONPLAYER,
        ATTACKING,
        BUSINESS,
        COACHING,
        COACHINGGKS,
        COACHINGTECHNIQUE,
        DIRECTNESS,
        DISCIPLINE,
        FREEROLES,
        INTERFERENCE,
        JUDGEMENT,
        JUDGINGPOTENTIAL,
        MANHANDLING,
        MARKING_PLAYER,
        MOTIVATING,
        OFFSIDE,
        PATIENCE,
        PHYSIOTHERAPY,
        PRESSING,
        RESOURCES,
        TACTICS,
        YOUNGSTERS,
        // Player
        SQUADNUMBER,
        CURRENTABILITY_PLAYER,
        POTENTIALABILITY_PLAYER,
        HOMEREPUTATION_PLAYER,
        CURRENTREPUTATION_PLAYER,
        WORLDREPUTATION_PLAYER,
        GOALKEEPER_PLAYER,
        SWEEPER_PLAYER,
        DEFENDER_PLAYER,
        DEFENSIVEMIDFIELDER_PLAYER,
        MIDFIELDER_PLAYER,
        ATTACKINGMIDFIELDER_PLAYER,
        ATTACKER_PLAYER,
        WINGBACK_PLAYER,
        FREEROLE,
        RIGHTSIDE,
        LEFTSIDE,
        CENTRAL,
        ACCELERATION,
        AGGRESSION,
        AGILITY,
        ANTICIPATION,
        BALANCE,
        BRAVERY,
        CONSISTENCY,
        CORNERS,
        CROSSING,
        DECISIONS,
        DIRTINESS,
        DRIBBLING,
        FINISHING,
        FLAIR,
        FREEKICKS,
        HANDLING,
        HEADING,
        IMPORTANTMATCHES,
        INJURYPRONENESS,
        JUMPING,
        LEADERSHIP,
        LEFTFOOT,
        LONGSHOTS,
        MARKING,
        MOVEMENT,
        NATURALFITNESS,
        ONEONONES,
        PACE,
        PASSING,
        PENALTIES,
        POSITIONING,
        REFLEXES,
        RIGHTFOOT,
        STAMINA,
        STRENGTH,
        TACKLING,
        TEAMWORK,
        TECHNIQUE,
        THROWINS,
        VERSATILITY,
        VISION,
        WORKRATE,
        MORALE,
        // Total
        TOTAL_SPIN_BOX_EDIT_COUNT
    };
};

#endif // EDITOR_STAFF_H
