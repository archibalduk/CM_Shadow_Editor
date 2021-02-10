#include "editor_city.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/city_data.h"
#include "../model/city_model.h"


/* ===================== */
/*      City Editor      */
/* ===================== */

// --- Default constructor --- //
EditorCity::EditorCity(MainUi *ui) :
    EditorUi("Cities", ui, Database::cities.proxy(), Database::cities.databaseTransfer(), CityModel::DisplayText)
{
    // Initialise the input widgets
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
void EditorCity::initScreenBasicData()
{
    ScreenWidget *screen = new ScreenWidget(this);

    GroupWidget *grp = new GroupWidget(tr("Basic Data"), screen);
    grp->add(m_LineEdit[NAME]);
    grp->add(m_PointerComboEdit);
    grp->add(m_LineEdit, LATITUDE, GENDER_NAME);

    // Mapping: Line Edits
    m_LineEdit[NAME]->set(m_Mapper, CityModel::Name, LineEdit::TEXT);
    m_LineEdit[GENDER_NAME]->set(m_Mapper, CityModel::GenderName, LineEdit::NUMBER);
    m_LineEdit[LATITUDE]->set(m_Mapper, CityModel::Latitude, LineEdit::DECIMAL);
    m_LineEdit[LONGITUDE]->set(m_Mapper, CityModel::Longitude, LineEdit::DECIMAL);
    m_LineEdit[ATTRACTION]->set(m_Mapper, CityModel::Attraction, LineEdit::NUMBER);
    m_LineEdit[WEATHER]->set(m_Mapper, CityModel::Weather, LineEdit::NUMBER);

    // Mapping: Pointer Edits
    m_PointerComboEdit[NATION]->set(m_Mapper, CityModel::Nation, Database::nations.proxy());

    // Layout
    screen->l->addWidget(grp);

    // Add the screen
    this->addScreen(screen, s_TextBasicData);
}
