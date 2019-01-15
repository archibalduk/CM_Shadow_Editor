#include "mainwindow.h"

// Qt headers
#include <QCoreApplication>

// Application headers
#include "db_modules/database.h"

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

    Database db;
    db.open(this);
}

MainWindow::~MainWindow()
{

}
