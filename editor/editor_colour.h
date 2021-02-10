#ifndef EDITOR_COLOUR_H
#define EDITOR_COLOUR_H

// Qt headers
#include <QVector>

// Application headers
#include "../editor_ui/editor_ui.h"
#include "../editor_ui/inputs/line_edit.h"
#include "../editor_ui/inputs/spin_box.h"

// --- Colour editor --- //
class EditorColour : public EditorUi
{
public:
    // Constructor
    EditorColour(MainUi *ui);

private slots:
    // Colour info
    void setColourData();

private:
    // Colour swatch
    QWidget *m_Swatch;

    // Inputs
    QVector<LineEdit*> m_LineEdit;
    QVector<SpinBox*> m_SpinBoxEdit;

    // Screens
    void initScreenBasicData();

    // LineEdit positions
    enum ENUM_LINE_EDIT_POSITIONS {
        NAME,
        HEX_CODE,
        TOTAL_LINE_EDIT_COUNT
    };

    // SpinBox positions
    enum ENUM_SPIN_BOX_EDIT_POSITIONS {
        RED_INTENSITY,
        GREEN_INTENSITY,
        BLUE_INTENSITY,
        TOTAL_SPIN_BOX_EDIT_COUNT
    };
};

#endif // EDITOR_COLOUR_H
