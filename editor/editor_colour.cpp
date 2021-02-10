#include "editor_colour.h"

// Application headers
#include "../db_modules/database.h"
#include "../db_containers/colour_data.h"
#include "../model/colour_model.h"


/* ======================= */
/*      Colour Editor      */
/* ======================= */

// --- Default constructor --- //
EditorColour::EditorColour(MainUi *ui) :
    EditorUi("Colours", ui, Database::colours.proxy(), nullptr, ColourModel::DisplayText)
{
    // Initialise the input widgets
    this->initInputWidgets(m_LineEdit, TOTAL_LINE_EDIT_COUNT);
    this->initInputWidgets(m_SpinBoxEdit, TOTAL_SPIN_BOX_EDIT_COUNT);

    // Initialise the screens
    this->initScreenBasicData();

    // Connect to swatch and hex data
    QObject::connect(m_SpinBoxEdit[RED_INTENSITY], &SpinBox::changed,
                     this, &EditorColour::setColourData);
    QObject::connect(m_SpinBoxEdit[GREEN_INTENSITY], &SpinBox::changed,
                     this, &EditorColour::setColourData);
    QObject::connect(m_SpinBoxEdit[BLUE_INTENSITY], &SpinBox::changed,
                     this, &EditorColour::setColourData);

    // Finalise/initialise the editor
    this->init();
}


/* ======================== */
/*      Editor Screens      */
/* ======================== */

// --- Basic Data --- //
void EditorColour::initScreenBasicData()
{
    ScreenWidget *screen = new ScreenWidget(this);

    GroupWidget *grp = new GroupWidget(tr("Basic Data"), screen);
    grp->add(m_LineEdit);
    grp->add(m_SpinBoxEdit);
    m_LineEdit[HEX_CODE]->setReadOnly(true);

    // Mapping
    m_LineEdit[NAME]->set(m_Mapper, ColourModel::Name);
    SpinBox::set(m_SpinBoxEdit, RED_INTENSITY, BLUE_INTENSITY, m_Mapper, ColourModel::RedIntensity);
    m_LineEdit[HEX_CODE]->setLabel(m_Mapper, ColourModel::HexCode);

    // Colour swatch
    m_Swatch = new QWidget(this);
    m_Swatch->setFixedSize(200,200);
    m_Swatch->setObjectName("EditorColour_ColourSwatch");
    GroupWidget *grpSwatch = new GroupWidget(tr("Colour swatch"), screen);
    grpSwatch->add(m_Swatch);

    // Layout
    screen->l->addWidget(grp, 0, 0);
    screen->l->addWidget(grpSwatch, 0, 1);

    // Add the screen
    this->addScreen(screen, s_TextBasicData);
}


/* ===================== */
/*      Colour Info      */
/* ===================== */

// --- Set the colour swatch and hex line edit --- //
void EditorColour::setColourData()
{
    const QColor colour(m_SpinBoxEdit[RED_INTENSITY]->getValue(),
                        m_SpinBoxEdit[GREEN_INTENSITY]->getValue(),
                        m_SpinBoxEdit[BLUE_INTENSITY]->getValue());

    m_LineEdit[HEX_CODE]->setText(colour.name());

    const QString style = QString("#EditorColour_ColourSwatch { background-color: %1; }").arg(colour.name());
    m_Swatch->setStyleSheet(style);
}
