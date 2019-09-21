#ifndef EDITOR_STAFF_H
#define EDITOR_STAFF_H

// Qt headers
#include <QVector>

// Application headers
#include "../editor_ui/editor_ui.h"
#include "../editor_ui/inputs/date_edit.h"
#include "../editor_ui/inputs/line_edit.h"
#include "../editor_ui/inputs/pointer_combo_edit.h"

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

    // Screens
    void initScreenBasicData();

    // DateEdit positions
    enum ENUM_DATE_EDIT_POSITIONS {
        DATE_OF_BIRTH,
        DATE_JOINED_CLUB,
        CONTRACT_EXPIRES_NATION,
        TOTAL_DATE_EDIT_COUNT
    };

    // LineEdit positions
    enum ENUM_LINE_EDIT_POSITIONS {
        FIRST_NAME,
        SECOND_NAME,
        COMMON_NAME,
        YEAR_OF_BIRTH,
        INTERNATIONAL_APPEARANCES,
        INTERNATIONAL_GOALS,
        TOTAL_LINE_EDIT_COUNT
    };

    // PointerComboEdit positions
    enum ENUM_POINTER_COMBO_EDIT_POSITIONS {
        NATION,
        SECOND_NATION,
        TOTAL_POINTER_COMBO_EDIT_COUNT
    };
};

#endif // EDITOR_STAFF_H
