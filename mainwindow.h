#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt headers
#include <QAction>
#include <QMainWindow>

// Application headers
#include "db_modules/database.h"
#include "editor/editor.h"
#include "ui/main_ui.h"

// --- Main window --- //
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    // Actions
    QAction *m_ActOpenDatabase;
    QAction *m_ActSaveDatabase;
    QAction *m_ActSaveAsDatabase;

    // Database
    Database m_Database;

    // Editor
    Editor *m_ShadowEditor;

    // User interface
    MainUi *m_MainUserInterface;
    void setUserInterface();

protected:
    // Exit the application
    void closeEvent(QCloseEvent *event);

private slots:
    // File I/O
    void openDatabase();
    void saveDatabase();
    void saveAsDatabase();

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
