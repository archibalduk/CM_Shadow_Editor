#include "editor_ui.h"

// Qt headers
#include <QAction>
#include <QLabel>
#include <QGridLayout>

// Application headers
#include "../model/model_base_class_wrapper.h"
#include "common_ui.h"

// --- Static common text labels --- //
const QString EditorUi::s_TextBasicData = tr("Basic Data");

/* ========================================== */
/*      Editor User Interface Base Class      */
/* ========================================== */

// --- Default constructor --- //
EditorUi::EditorUi(const QString &title, MainUi *ui,
                   QSortFilterProxyModel *proxy, DatabaseTransfer *databaseTransfer,
                   const qint32 &displayColumn) :
    QWidget(ui->getParent()),
    m_DatabaseTransfer(databaseTransfer)
{    
    // User interface
    this->setUserInterface();

    // Button for navigation menu
    QAction *action = new QAction(title, this);
    ui->addWidget(action, this, m_NavigationList, MainUi::ACTIVE_WHEN_DB_IS_OPEN);

    // Model/Proxy
    this->setModel(proxy, displayColumn);
}


/* ======================= */
/*      Data Transfer      */
/* ======================= */

// --- Export all data --- //
bool EditorUi::onExportAllData()
{
    if(m_DatabaseTransfer == nullptr)
        return false;
    else
        return m_DatabaseTransfer->exportData();
}

// --- Export filtered data --- //
bool EditorUi::onExportFilteredData()
{
    if(m_DatabaseTransfer == nullptr)
        return false;
    else
        return m_DatabaseTransfer->exportData(m_Proxy);
}

// --- Import data --- //
bool EditorUi::onImportData()
{
    if(m_DatabaseTransfer == nullptr)
        return false;

    return false;
}


/* =============== */
/*      Model      */
/* =============== */

// --- Set data model --- //
void EditorUi::setModel(QSortFilterProxyModel *proxy, const qint32 &displayColumn)
{
    // Proxy model
    m_Proxy = proxy;
    m_Proxy->setFilterKeyColumn(displayColumn);
    m_Proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(m_Proxy, &QSortFilterProxyModel::modelAboutToBeReset,
                     this, &EditorUi::modelResetCommenced);
    QObject::connect(m_Proxy, &QSortFilterProxyModel::modelReset,
                     this, &EditorUi::modelResetComplete);
    QObject::connect(m_Proxy, &QSortFilterProxyModel::rowsInserted,
                     this, &EditorUi::onRowCountChange);
    QObject::connect(m_Proxy, &QSortFilterProxyModel::rowsRemoved,
                     this, &EditorUi::onRowCountChange);

    // Connect proxy model to list view
    m_NavigationList->setModel(m_Proxy);
    m_NavigationList->setModelColumn(displayColumn);

    // Connect search box to proxy
    QObject::connect(m_NavigationSearch, &QLineEdit::textChanged,
                     m_Proxy, &QSortFilterProxyModel::setFilterFixedString);

    // Mapper
    m_Mapper = new QDataWidgetMapper(this);
    m_Mapper->setModel(m_Proxy);
    m_Mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    QObject::connect(m_NavigationList, &QListView::clicked,
                     this, &EditorUi::onProxyChanged);

    // Add mapping to heading area
    m_LabelDisplayText->set(m_Mapper, displayColumn);
    m_LabelRecordId->set(m_Mapper, ModelBaseClassWrapper::Id);
}


/* ==================== */
/*      Navigation      */
/* ==================== */

// --- To First --- //
void EditorUi::toFirst()
{
    m_NavigationList->setCurrentIndex(m_Proxy->index(0, m_Proxy->filterKeyColumn()));
    this->onProxyChanged(m_NavigationList->currentIndex());
}

// --- To Last --- //
void EditorUi::toLast()
{
    m_NavigationList->setCurrentIndex(m_Proxy->index(m_Proxy->rowCount()-1, m_Proxy->filterKeyColumn()));
    this->onProxyChanged(m_NavigationList->currentIndex());
}

// --- To Newest Item (when adding a new item to the end of the model) --- //
void EditorUi::toNewest()
{
    const QModelIndex index = m_Proxy->mapFromSource(m_Mapper->model()->index(m_Mapper->model()->rowCount()-1, 0));
    m_NavigationList->setCurrentIndex(index);
    this->onProxyChanged(index);
}

// --- To Next --- //
void EditorUi::toNext()
{
    m_NavigationList->setCurrentIndex(m_Proxy->index(m_NavigationList->currentIndex().row()+1, m_Proxy->filterKeyColumn()));
    this->onProxyChanged(m_NavigationList->currentIndex());
}

// --- To Previous --- //
void EditorUi::toPrevious()
{
    m_NavigationList->setCurrentIndex(m_Proxy->index(m_NavigationList->currentIndex().row()-1, m_Proxy->filterKeyColumn()));
    this->onProxyChanged(m_NavigationList->currentIndex());
}


/* =========================== */
/*      Proxy <--> Mapper      */
/* =========================== */

// --- Proxy --> mapper slot --- //
void EditorUi::onProxyChanged(const QModelIndex &index)
{
    m_Mapper->setCurrentModelIndex(index);
    m_NavigationList->setFocus(Qt::MouseFocusReason);
}
#include <QDebug>
#include <QTime>
void EditorUi::modelResetComplete()
{
    qDebug() << "Reset Complete" << QTime::currentTime();
}

void EditorUi::modelResetCommenced()
{
    qDebug() << "Reset Begin" << QTime::currentTime();
}

void EditorUi::onRowCountChange(const QModelIndex &parent, int first, int last)
{
    //qDebug() << "New row count (model):" << m_Proxy->sourceModel()->rowCount();
}


/* ======================== */
/*      User Interface      */
/* ======================== */

// --- Add a screen to the user interface --- //
void EditorUi::addScreen(QWidget *screen, const QString &title)
{
    m_EditorDisplay->addTab(screen, title);
}

// --- Finalise / initialise the editor UI --- //
void EditorUi::init()
{
    this->toFirst();
}

// --- Set heading/title area --- //
void EditorUi::setHeadingArea()
{
    m_HeadingArea = new QWidget(this);

    // Display text/title
    m_LabelDisplayText = new Label(m_HeadingArea, Label::TITLE);
    m_LabelDisplayText->setObjectName("Heading_Text");

    // Record id
    QLabel *labelRecordId = new QLabel("Id:", m_HeadingArea);
    labelRecordId->setObjectName("SubHeading_Text");
    m_LabelRecordId = new Label(m_HeadingArea, Label::STANDARD);
    m_LabelRecordId->setObjectName("SubHeading_Text");

    // Layout
    QGridLayout *layout = new QGridLayout(m_HeadingArea);
    layout->addWidget(m_LabelDisplayText, 0, 0);
    layout->addWidget(labelRecordId, 0, 1);
    layout->addWidget(m_LabelRecordId, 0, 2);
    m_HeadingArea->setLayout(layout);
}

// --- Set tools area --- //
void EditorUi::setToolsArea()
{
    m_ToolsArea = new QWidget(this);
    m_ToolBar = new QToolBar(m_ToolsArea);

    m_ActionExportAllData = new QAction("Export All Data", m_ToolBar);
    QObject::connect(m_ActionExportAllData, &QAction::triggered,
                     this, &EditorUi::onExportAllData);
    m_ToolBar->addAction(m_ActionExportAllData);

    m_ActionExportFilteredData = new QAction("Export Current Filter", m_ToolBar);
    QObject::connect(m_ActionExportFilteredData, &QAction::triggered,
                     this, &EditorUi::onExportFilteredData);
    m_ToolBar->addAction(m_ActionExportFilteredData);

    m_ActionImportData = new QAction("Import Data", m_ToolBar);
    QObject::connect(m_ActionImportData, &QAction::triggered,
                     this, &EditorUi::onImportData);
    m_ToolBar->addAction(m_ActionImportData);

    // Layout
    QGridLayout *layout = new QGridLayout(m_ToolsArea);
    layout->addWidget(m_ToolBar);
}

// --- Set user interface --- //
void EditorUi::setUserInterface()
{
    // Heading area
    this->setHeadingArea();

    // Tools area
    this->setToolsArea();

    // Navigation list
    m_NavigationList = new QListView(this);
    m_NavigationList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_NavigationList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_NavigationList->setMinimumWidth(CommonUi::WidthListBox);

    // As only uniform sizes are used, the QListView can be optimised using setUniformItemSizes()
    m_NavigationList->setUniformItemSizes(true);

    // Navigation search
    m_NavigationSearch = new QLineEdit(this);

    // Main editor display area/tab widget
    m_EditorDisplay = new  QTabWidget(this);

    /* Layout
     * xx | 00      | 01        | 02
     * 00 | NavList | Heading   |
     * 01 | NavList | EditorDisp|
     * 02 | NavSrch | ToolsArea |
     */

    // Layout
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(m_NavigationList, 0, 0, 2, 1);
    layout->addWidget(m_HeadingArea, 0, 1);
    layout->addWidget(m_EditorDisplay, 1, 1);
    //layout->addWidget(m_NavigationSearch, 2, 0);
    layout->addWidget(m_ToolsArea, 2, 1);
}
