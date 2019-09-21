#ifndef EDITOR_CITY_H
#define EDITOR_CITY_H

// Qt headers
#include <QVector>

// Application headers
#include "../editor_ui/editor_ui.h"
#include "../editor_ui/inputs/line_edit.h"
#include "../editor_ui/inputs/pointer_combo_edit.h"

// --- City editor --- //
class EditorCity : public EditorUi
{
public:
    // Constructor
    EditorCity(MainUi *ui);

private:
    // Inputs
    QVector<LineEdit*> m_LineEdit;
    QVector<PointerComboEdit*> m_PointerComboEdit;

    // Screens
    void initScreenBasicData();

    // LineEdit positions
    enum ENUM_LINE_EDIT_POSITIONS {
        NAME,
        LATITUDE,
        LONGITUDE,
        ATTRACTION,
        WEATHER,
        GENDER_NAME,
        TOTAL_LINE_EDIT_COUNT
    };

    // PointerComboEdit positions
    enum ENUM_POINTER_COMBO_EDIT_POSITIONS {
        NATION,
        TOTAL_POINTER_COMBO_EDIT_COUNT
    };
};

#endif // EDITOR_CITY_H
