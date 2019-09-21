#include "editor.h"


/* ================ */
/*      Editor      */
/* ================ */

// --- Default constructor --- //
Editor::Editor(MainUi *ui) :
    m_Ui(ui)
{
    // Initialise editors
    m_EditorCity = new EditorCity(ui);
    m_EditorStaff = new EditorStaff(ui);

    // Initialise shadow editor/viewer
    m_ShadowEditor = new ShadowEditor(ui);
}
