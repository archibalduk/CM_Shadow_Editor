#ifndef SHADOW_EDITOR_H
#define SHADOW_EDITOR_H

// Qt headers
#include <QSortFilterProxyModel>

// Application headers
#include "../editor_ui/editor_ui.h"
#include "../editor_ui/widgets/table_widget.h"
#include "../shadow/model/shadow_edit_item_model.h"

// --- Shadow editor/viewer --- //
class ShadowEditor : public EditorUi
{
public:
    // Constructor
    ShadowEditor(MainUi *ui);

private slots:
    // Index change
    void onIndexChange(const int &/*index*/);

private:
    // Model
    ShadowEditItemModel *m_ShadowEditItemModel;
    QSortFilterProxyModel *m_ShadowEditItemProxy;

    // Screens
    void initScreenBasicData();

    // Shadow Group Edits
    TableWidget *m_GroupEditsTable;
};

#endif // SHADOW_EDITOR_H
