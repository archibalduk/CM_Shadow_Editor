#include "mainwindow.h"

// Qt headers
#include <QCoreApplication>
#include <QSettings>

/* ===================== */
/*      Main Window      */
/* ===================== */

// --- Default constructor --- //
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Window title details
    this->setWindowTitle(QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion());
    this->setWindowIcon(QIcon("application.ico"));

    // Create user interface
    this->setUserInterface();

    // Set window
    QSettings settings;
    this->restoreGeometry(settings.value("window_geometry").toByteArray());
    this->restoreState(settings.value("window_state").toByteArray());
    this->setMinimumSize(1152,648);
}

// --- Default destructor --- //
MainWindow::~MainWindow()
{

}


/* ============================== */
/*      Exit the Application      */
/* ============================== */

// --- Detect any attempt to close the application and prompt the user to save the database first --- //
void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("window_geometry", this->saveGeometry());
    settings.setValue("window_state", this->saveState());
    QMainWindow::closeEvent(event);
}


/* ================== */
/*      File I/O      */
/* ================== */

// --- Open database --- //
void MainWindow::openDatabase()
{
    // Open the database
    const bool result = m_Database.open(this);

    // Set the user interface status
    m_MainUserInterface->setStatus(result);
}

// --- Save database --- //
void MainWindow::saveDatabase()
{
    // Save the database
    const bool result = m_Database.save();
}

// --- Save as database --- //
void MainWindow::saveAsDatabase()
{
    // Save the database
    const bool result = m_Database.saveAs(this);
}


/* ======================== */
/*      User Interface      */
/* ======================== */

// --- Create user interface --- //
void MainWindow::setUserInterface()
{
    // Main Ui with toolbar and stacked widget
    m_MainUserInterface = new MainUi(this);

    // Action: Open database
    m_ActOpenDatabase = new QAction("&Open", m_MainUserInterface);
    m_MainUserInterface->addButton(m_ActOpenDatabase, MainUi::ACTIVE_WHEN_DB_IS_CLOSED);
    QObject::connect(m_ActOpenDatabase, &QAction::triggered,
                     this, &MainWindow::openDatabase);

    // Action: Save database
    m_ActSaveDatabase = new QAction("&Save", m_MainUserInterface);
    m_MainUserInterface->addButton(m_ActSaveDatabase, MainUi::ACTIVE_WHEN_DB_IS_OPEN);
    QObject::connect(m_ActSaveDatabase, &QAction::triggered,
                     this, &MainWindow::saveDatabase);

    // Action: Save as database
    m_ActSaveAsDatabase = new QAction("Save &As", m_MainUserInterface);
    m_MainUserInterface->addButton(m_ActSaveAsDatabase, MainUi::ACTIVE_WHEN_DB_IS_OPEN);
    QObject::connect(m_ActSaveAsDatabase, &QAction::triggered,
                     this, &MainWindow::saveAsDatabase);

    // Settings menu
    m_Settings = new Settings(this);
    m_MainUserInterface->addMenu(m_Settings);

    // Shadow editor
    m_ShadowEditor = new Editor(m_MainUserInterface);
}
