#include "shadow_editor.h"

// Application headers
#include "../shadow/shadow_manager.h"
#include "../shadow/model/shadow_group_model.h"


/* ============================== */
/*      Shadow Editor/Viewer      */
/* ============================== */

// --- Default constructor --- //
ShadowEditor::ShadowEditor(MainUi *ui) :
    EditorUi("Shadow Viewer", ui, ShadowManager::proxy(), ShadowGroupModel::DisplayText)
{
    // Initialise the screens
    this->initScreenBasicData();

    // Finalise/initialise the editor
    this->init();
}


/* ======================== */
/*      Editor Screens      */
/* ======================== */

// --- Basic Data --- //
void ShadowEditor::initScreenBasicData()
{
    ScreenWidget *screen = new ScreenWidget(this);

    // Model
    m_ShadowEditItemModel = new ShadowEditItemModel(this);

    // Proxy
    m_ShadowEditItemProxy = new QSortFilterProxyModel(m_ShadowEditItemModel);
    m_ShadowEditItemProxy->setSourceModel(m_ShadowEditItemModel);
    m_ShadowEditItemProxy->setFilterKeyColumn(ShadowEditItemModel::TableId);
    m_ShadowEditItemProxy->setSortRole(Qt::AscendingOrder);

    // Shadow Group Edits table
    m_GroupEditsTable = new TableWidget(this);
    m_GroupEditsTable->setSourceModel(m_ShadowEditItemProxy);

    // Connect the mapper to the model
    QObject::connect(m_Mapper, &QDataWidgetMapper::currentIndexChanged,
                     this, &ShadowEditor::onIndexChange);

    // Layout
    screen->l->addWidget(m_GroupEditsTable, 0, 0);

    // Add the screen
    this->addScreen(screen, s_TextBasicData);
}


/* =============== */
/*      Slots      */
/* =============== */

// --- Index change --- //
void ShadowEditor::onIndexChange(const int &/*index*/)
{
    const qint32 row = m_Proxy->mapToSource(m_NavigationList->currentIndex()).row();
    m_ShadowEditItemModel->setSourceData(ShadowManager::model()->editItems(row));
}
