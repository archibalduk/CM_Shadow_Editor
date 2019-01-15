#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Qt headers
#include <QMainWindow>

// --- Main window --- //
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
