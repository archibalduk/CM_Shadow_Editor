#include "main_ui.h"

// Qt headers
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QToolButton>

/* ============================= */
/*      Main User Interface      */
/* ============================= */

// --- Default constructor --- //
MainUi::MainUi(QMainWindow *parent) :
    m_CurrentStatus(STATUS_DB_IS_CLOSED)
{
    // Toolbar
    m_Toolbar = new QToolBar(parent);
    m_Toolbar->setObjectName("MainUiToolBar");
    m_Toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    parent->addToolBar(m_Toolbar);

    // Container widget
    QWidget *containerWidget = new QWidget(parent);
    parent->setCentralWidget(containerWidget);

    // Sidebar stacked widget
    m_SideBarDisplayArea = new QStackedWidget(containerWidget);
    m_SideBarDisplayArea->setFixedWidth(250);

    // Main stacked widget
    m_MainDisplayArea = new QStackedWidget(containerWidget);

    // Layout
    QHBoxLayout *layout = new QHBoxLayout(containerWidget);
    layout->addWidget(m_SideBarDisplayArea);
    layout->addWidget(m_MainDisplayArea);
    containerWidget->setLayout(layout);
}

// --- Desctructor --- //
MainUi::~MainUi()
{
    qDeleteAll(m_Actions);
    m_Actions.clear();
}


/* =================== */
/*      Add Items      */
/* =================== */

// --- Add action --- //
void MainUi::addButton(QAction *action, const qint8 &behaviour)
{
    m_Toolbar->addAction(action);
    this->initBehaviour(action, behaviour);
}

// --- Add menu --- //
void MainUi::addMenu(QMenu *menu)
{
    QToolButton* toolButton = new QToolButton(m_Toolbar);
    toolButton->setText(menu->title());
    toolButton->setMenu(menu);
    toolButton->setPopupMode(QToolButton::InstantPopup);
    m_Toolbar->addWidget(toolButton);
}

// --- Add widget with associated action --- //
void MainUi::addWidget(QAction *action, QWidget *mainWidget, QWidget *sideBarWidget, const qint8 &behaviour)
{
    this->addButton(action, behaviour);
    const qint32 indexMainArea = (mainWidget != nullptr) ? m_MainDisplayArea->addWidget(mainWidget) : -1;
    const qint32 indexSideBar = (sideBarWidget != nullptr) ? m_SideBarDisplayArea->addWidget(sideBarWidget) : -1;

    // Wrapper
    ActionWrapper *aw = new ActionWrapper(action, indexMainArea, indexSideBar);

    if(indexMainArea >= 0)
        QObject::connect(aw, &ActionWrapper::triggeredMainArea,
                         m_MainDisplayArea, &QStackedWidget::setCurrentIndex);

    if(indexSideBar >= 0)
        QObject::connect(aw, &ActionWrapper::triggeredSideBar,
                         m_SideBarDisplayArea, &QStackedWidget::setCurrentIndex);

    m_Actions.push_back(aw);
}


/* =================== */
/*      Behaviour      */
/* =================== */

// --- Initialise the behaviour of a QAction --- //
void MainUi::initBehaviour(QAction *action, const qint8 &behaviour)
{
    switch(behaviour)
    {
    case ACTIVE_WHEN_DB_IS_CLOSED:
        action->setEnabled(m_CurrentStatus == STATUS_DB_IS_CLOSED);
        QObject::connect(this, &MainUi::setDatabaseClosedStatus,
                         action, &QAction::setEnabled);
        break;

    case ACTIVE_WHEN_DB_IS_OPEN:
        action->setEnabled(m_CurrentStatus == STATUS_DB_IS_OPEN);
        QObject::connect(this, &MainUi::setDatabaseOpenStatus,
                         action, &QAction::setEnabled);
        break;
    }
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Get parent --- //
QWidget *MainUi::getParent()
{
    return m_MainDisplayArea;
}


/* ================ */
/*      Status      */
/* ================ */

// --- Set status --- //
void MainUi::setStatus(const bool &isDatabaseOpen)
{
    if(isDatabaseOpen)
        m_CurrentStatus = STATUS_DB_IS_OPEN;
    else
        m_CurrentStatus = STATUS_DB_IS_CLOSED;

    emit setDatabaseClosedStatus(!isDatabaseOpen);
    emit setDatabaseOpenStatus(isDatabaseOpen);
}
