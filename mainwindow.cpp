#include "mainwindow.h"

// Qt headers
#include <QCoreApplication>


/* ===================== */
/*      Main Window      */
/* ===================== */

// --- Default constructor --- //
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Window title details
    this->setWindowTitle(QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion());
    this->setWindowIcon(QIcon("icon.ico"));
}

MainWindow::~MainWindow()
{

}
