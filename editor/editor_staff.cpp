#include "editor_staff.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/staff_data.h"
#include "../model/staff_model.h"


/* ====================== */
/*      Staff Editor      */
/* ====================== */

// --- Default constructor --- //
EditorStaff::EditorStaff(MainUi *ui) :
    EditorUi("Players and Staff", ui, Database::staff.proxy(), StaffModel::DisplayText)
{
    // Initialise the input widgets
    this->initInputWidgets(m_DateEdit, TOTAL_DATE_EDIT_COUNT);
    this->initInputWidgets(m_LineEdit, TOTAL_LINE_EDIT_COUNT);
    this->initInputWidgets(m_PointerComboEdit, TOTAL_POINTER_COMBO_EDIT_COUNT);

    // Initialise the screens
    this->initScreenBasicData();

    // Finalise/initialise the editor
    this->init();
}


/* ======================== */
/*      Editor Screens      */
/* ======================== */

// --- Basic Data --- //
void EditorStaff::initScreenBasicData()
{
    ScreenWidget *screen = new ScreenWidget(this);

    GroupWidget *grpPersonal = new GroupWidget(tr("Personal"), screen);
    grpPersonal->add(m_LineEdit, FIRST_NAME, COMMON_NAME);
    grpPersonal->add(m_DateEdit[DATE_OF_BIRTH]);
    grpPersonal->add(m_LineEdit[YEAR_OF_BIRTH]);

    GroupWidget *grpNationality = new GroupWidget(tr("Nationality"), screen);
    grpNationality->add(m_PointerComboEdit, NATION, SECOND_NATION);
    grpNationality->add(m_LineEdit, INTERNATIONAL_APPEARANCES, INTERNATIONAL_GOALS);

    // Mapping: Date Edits
    m_DateEdit[DATE_OF_BIRTH]->set(m_Mapper, StaffModel::DateOfBirth);

    // Mapping: Line Edits
    m_LineEdit[FIRST_NAME]->set(m_Mapper, StaffModel::FirstName, LineEdit::TEXT);
    m_LineEdit[SECOND_NAME]->set(m_Mapper, StaffModel::SecondName, LineEdit::TEXT);
    m_LineEdit[COMMON_NAME]->set(m_Mapper, StaffModel::CommonName, LineEdit::TEXT);
    m_LineEdit[YEAR_OF_BIRTH]->set(m_Mapper, StaffModel::YearOfBirth, LineEdit::NUMBER);
    m_LineEdit[INTERNATIONAL_APPEARANCES]->set(m_Mapper, StaffModel::InternationalApps, LineEdit::NUMBER);
    m_LineEdit[INTERNATIONAL_GOALS]->set(m_Mapper, StaffModel::InternationalGoals, LineEdit::NUMBER);

    // Mapping: Pointer Edits
    m_PointerComboEdit[NATION]->set(m_Mapper, StaffModel::Nation, Database::nations.proxy());
    m_PointerComboEdit[SECOND_NATION]->set(m_Mapper, StaffModel::SecondNation, Database::nations.proxy());

    // Layout
    screen->l->addWidget(grpPersonal, 0, 0);
    screen->l->addWidget(grpNationality, 0, 1);

    // Add the screen
    this->addScreen(screen, s_TextBasicData);
}
