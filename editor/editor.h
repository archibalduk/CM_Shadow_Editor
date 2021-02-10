#ifndef EDITOR_H
#define EDITOR_H

// Qt headers
#include <QWidget>

// Application headers
#include "../ui/main_ui.h"

// Shadow editors
#include "../editor/editor_city.h"
#include "../editor/editor_colour.h"
#include "../editor/editor_staff.h"
#include "../editor/shadow_editor.h"

// --- Editor wrapper --- //
class Editor
{
private:
    // User interface
    MainUi *m_Ui;

    // Editors
    EditorCity *m_EditorCity;
    EditorColour *m_EditorColour;
    EditorStaff *m_EditorStaff;

    // Shadow editor/viewer
    ShadowEditor *m_ShadowEditor;

public:
    // Constructor
    Editor(MainUi *ui);
};

#endif // EDITOR_H
