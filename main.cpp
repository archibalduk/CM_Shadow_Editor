#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // HIDPI support
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    // Application details
    QCoreApplication::setApplicationName("CM Shadow Editor");
    QCoreApplication::setApplicationVersion(APP_VERSION);
    QCoreApplication::setOrganizationName("EHM The Blue Line");
    QCoreApplication::setOrganizationDomain("ehmtheblueline.com");

    // Commence application loop
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
