#include "editor_staff.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_modules/database_values.h"
#include "../db_containers/staff_data.h"
#include "../model/staff_model.h"


/* ====================== */
/*      Staff Editor      */
/* ====================== */

// --- Default constructor --- //
EditorStaff::EditorStaff(MainUi *ui) :
    EditorUi("Players and Staff", ui, Database::staff.proxy(), nullptr, StaffModel::DisplayText)
{
    // Initialise the input widgets
    this->initInputWidgets(m_DateEdit, TOTAL_DATE_EDIT_COUNT);
    this->initInputWidgets(m_LineEdit, TOTAL_LINE_EDIT_COUNT);
    this->initInputWidgets(m_PointerComboEdit, TOTAL_POINTER_COMBO_EDIT_COUNT);
    this->initInputWidgets(m_PointerLineEdit, TOTAL_POINTER_LINE_EDIT_COUNT);
    this->initInputWidgets(m_SpinBoxEdit, TOTAL_SPIN_BOX_EDIT_COUNT);

    // Initialise the screens
    this->initScreenBasicData();
    this->initScreenTraits();
    this->initScreenStaffPreferences();
    this->initScreenNonPlayerAttributes();
    this->initScreenNonPlayerTypes();
    this->initScreenPlayerPositions();
    this->initScreenPlayerAttributes();
    this->initScreenPlayerHistory();

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
    grpPersonal->add(m_PointerComboEdit[CLASSIFICATION]);

    GroupWidget *grpNationality = new GroupWidget(tr("Nationality"), screen);
    grpNationality->add(m_PointerComboEdit, NATION, SECOND_NATION);
    grpNationality->add(m_LineEdit, INTERNATIONAL_APPEARANCES, INTERNATIONAL_GOALS);

    GroupWidget *grpClubContract = new GroupWidget(tr("Club Contract"), screen);
    grpClubContract->add(m_PointerComboEdit[CLUB_CONTRACTED]);
    grpClubContract->add(m_PointerComboEdit[JOB_FOR_CLUB]);
    grpClubContract->add(m_DateEdit, DATE_JOINED_CLUB, CONTRACT_EXPIRES_CLUB);
    grpClubContract->add(m_PointerComboEdit[PLAYING_SQUAD]);
    grpClubContract->add(m_LineEdit, ESTIMATED_WAGE, ESTIMATED_VALUE);

    GroupWidget *grpNationContract = new GroupWidget(tr("Nation Contract"), screen);
    grpNationContract->add(m_PointerComboEdit[NATION_CONTRACTED]);
    grpNationContract->add(m_PointerComboEdit[JOB_FOR_NATION]);
    grpNationContract->add(m_DateEdit, DATE_JOINED_NATION, CONTRACT_EXPIRES_NATION);

    // Mapping: Date Edits
    m_DateEdit[DATE_OF_BIRTH]->set(m_Mapper, StaffModel::DateOfBirth);
    m_DateEdit[DATE_JOINED_CLUB]->set(m_Mapper, StaffModel::DateJoinedClub);
    m_DateEdit[CONTRACT_EXPIRES_CLUB]->set(m_Mapper, StaffModel::ContractExpiresClub);
    m_DateEdit[DATE_JOINED_NATION]->set(m_Mapper, StaffModel::DateJoinedNation);
    m_DateEdit[CONTRACT_EXPIRES_NATION]->set(m_Mapper, StaffModel::ContractExpiresNation);

    // Mapping: Line Edits
    m_LineEdit[FIRST_NAME]->set(m_Mapper, StaffModel::FirstName, LineEdit::TEXT);
    m_LineEdit[SECOND_NAME]->set(m_Mapper, StaffModel::SecondName, LineEdit::TEXT);
    m_LineEdit[COMMON_NAME]->set(m_Mapper, StaffModel::CommonName, LineEdit::TEXT);
    m_LineEdit[YEAR_OF_BIRTH]->set(m_Mapper, StaffModel::YearOfBirth, LineEdit::NUMBER);
    m_LineEdit[INTERNATIONAL_APPEARANCES]->set(m_Mapper, StaffModel::InternationalApps, LineEdit::NUMBER);
    m_LineEdit[INTERNATIONAL_GOALS]->set(m_Mapper, StaffModel::InternationalGoals, LineEdit::NUMBER);
    m_LineEdit[ESTIMATED_WAGE]->set(m_Mapper, StaffModel::EstimatedWage, LineEdit::NUMBER);
    m_LineEdit[ESTIMATED_VALUE]->set(m_Mapper, StaffModel::EstimatedValue, LineEdit::NUMBER);

    // Mapping: Pointer Edits
    m_PointerComboEdit[NATION]->set(m_Mapper, StaffModel::Nation, Database::nations.proxy());
    m_PointerComboEdit[SECOND_NATION]->set(m_Mapper, StaffModel::SecondNation, Database::nations.proxy());
    m_PointerComboEdit[CLASSIFICATION]->set(m_Mapper, StaffModel::Classification, DatabaseValues::dataStaffClassification.proxy(), true);
    m_PointerComboEdit[CLUB_CONTRACTED]->set(m_Mapper, StaffModel::ClubContracted, Database::clubs.proxy());
    m_PointerComboEdit[JOB_FOR_CLUB]->set(m_Mapper, StaffModel::JobForClub, DatabaseValues::dataJobForClub.proxy(), true);
    m_PointerComboEdit[PLAYING_SQUAD]->set(m_Mapper, StaffModel::PlayingSquad, DatabaseValues::dataPlayingSquad.proxy(), true);
    m_PointerComboEdit[NATION_CONTRACTED]->set(m_Mapper, StaffModel::NationContracted, Database::clubs.proxy());
    m_PointerComboEdit[JOB_FOR_NATION]->set(m_Mapper, StaffModel::JobForNation, DatabaseValues::dataJobForClub.proxy(), true);

    // Layout
    screen->l->addWidget(grpPersonal, 0, 0);
    screen->l->addWidget(grpNationality, 0, 1);
    screen->l->addWidget(grpClubContract, 1, 0);
    screen->l->addWidget(grpNationContract, 1, 1);

    // Add the screen
    this->addScreen(screen, tr("Personal"));
}

// --- Non-player: Attributes --- //
void EditorStaff::initScreenNonPlayerAttributes()
{
    ScreenWidget *screen = new ScreenWidget(this);

    // Mapping
    SpinBox::set(m_SpinBoxEdit, CURRENTABILITY_NONPLAYER, YOUNGSTERS, m_Mapper, StaffModel::CurrentAbility_NonPlayer);

    GroupWidget *grpAbility = new GroupWidget(tr("Non-Playing Ability"), screen);
    grpAbility->add(m_SpinBoxEdit, CURRENTABILITY_NONPLAYER, WORLDREPUTATION_NONPLAYER);

    GroupWidget *grpAttributes = new GroupWidget(tr("Non-Playing Attributes"), screen, 11);
    grpAttributes->add(m_SpinBoxEdit, ATTACKING, YOUNGSTERS);

    // Layout
    screen->l->addWidget(grpAbility, 0, 0);
    screen->l->addWidget(grpAttributes, 0, 1, 1, 2);

    // Add the screen
    this->addScreen(screen, "Coach");
}

// --- Non-player: Types --- //
void EditorStaff::initScreenNonPlayerTypes()
{

}

// --- Player: Attributes --- //
void EditorStaff::initScreenPlayerAttributes()
{
    ScreenWidget *screen = new ScreenWidget(this);

    // Mapping
    SpinBox::set(m_SpinBoxEdit, ACCELERATION, MORALE, m_Mapper, StaffModel::Acceleration);

    GroupWidget *grpPlayer = new GroupWidget(tr("Player"), screen);
    grpPlayer->add(m_SpinBoxEdit, ACCELERATION, MORALE);

    // Layout
    screen->l->addWidget(grpPlayer, 0, 0);

    // Add the screen
    this->addScreen(screen, "Player");
}

// --- Player: Career history --- //
void EditorStaff::initScreenPlayerHistory()
{

}

// --- Player: Positions --- //
void EditorStaff::initScreenPlayerPositions()
{
    ScreenWidget *screen = new ScreenWidget(this);

    // Mapping
    SpinBox::set(m_SpinBoxEdit, SQUADNUMBER, CENTRAL, m_Mapper, StaffModel::SquadNumber);

    GroupWidget *grpAbility = new GroupWidget(tr("Playing Ability"), screen);
    grpAbility->add(m_SpinBoxEdit, SQUADNUMBER, WORLDREPUTATION_PLAYER);

    GroupWidget *grpSides = new GroupWidget(tr("Sides"), screen);
    grpSides->add(m_SpinBoxEdit, RIGHTSIDE, CENTRAL);

    GroupWidget *grpPositions = new GroupWidget(tr("Positions"), screen);
    grpPositions->add(m_SpinBoxEdit, GOALKEEPER_PLAYER, FREEROLE);

    // Layout
    screen->l->addWidget(grpAbility, 0, 0);
    screen->l->addWidget(grpSides, 1, 0);
    screen->l->addWidget(grpPositions, 0, 1, 2, 1);

    // Add the screen
    this->addScreen(screen, "Positions");
}

// --- Staff preferences --- //
void EditorStaff::initScreenStaffPreferences()
{
    ScreenWidget *screen = new ScreenWidget(this);

    GroupWidget *grpFavouriteClubs = new GroupWidget(tr("Favourite clubs"), screen);
    grpFavouriteClubs->add(m_PointerComboEdit, FAVOURITECLUBS1, FAVOURITECLUBS3);

    GroupWidget *grpDislikedClubs = new GroupWidget(tr("Disliked clubs"), screen);
    grpDislikedClubs->add(m_PointerComboEdit, DISLIKEDCLUBS1, DISLIKEDCLUBS3);

    GroupWidget *grpFavouriteStaff = new GroupWidget(tr("Favourite staff"), screen);
    grpFavouriteStaff->add(m_PointerLineEdit, FAVOURITESTAFF1, FAVOURITESTAFF3);

    GroupWidget *grpDislikedStaff = new GroupWidget(tr("Disliked staff"), screen);
    grpDislikedStaff->add(m_PointerLineEdit, DISLIKEDSTAFF1, DISLIKEDSTAFF3);

    // Mapping
    PointerEdit::setBatch(m_PointerComboEdit, FAVOURITECLUBS1, DISLIKEDCLUBS3,
                          m_Mapper, StaffModel::FavouriteClubs1, Database::clubs.proxy());
    PointerEdit::setBatch(m_PointerLineEdit, FAVOURITESTAFF1, DISLIKEDSTAFF3,
                          m_Mapper, StaffModel::FavouriteStaff1, Database::staff.proxy());

    // Layout
    screen->l->addWidget(grpFavouriteClubs, 0, 0);
    screen->l->addWidget(grpDislikedClubs, 0, 1);
    screen->l->addWidget(grpFavouriteStaff, 1, 0);
    screen->l->addWidget(grpDislikedStaff, 1, 1);

    // Add the screen
    this->addScreen(screen, "Preferences");

}

// --- Traits --- //
void EditorStaff::initScreenTraits()
{
    ScreenWidget *screen = new ScreenWidget(this);

    // Mapping
    SpinBox::set(m_SpinBoxEdit, ADAPTABILITY, TEMPERAMENT, m_Mapper, StaffModel::Adaptability);

    GroupWidget *grpTraits = new GroupWidget(tr("Traits"), screen);
    grpTraits->add(m_SpinBoxEdit, ADAPTABILITY, TEMPERAMENT);

    // Layout
    screen->l->addWidget(grpTraits, 0, 0);

    // Add the screen
    this->addScreen(screen, "Traits");
}
