#ifndef MAIN_UI_H
#define MAIN_UI_H

// Qt headers
#include <QAction>
#include <QMainWindow>
#include <QObject>
#include <QStackedWidget>
#include <QToolBar>
#include <QVector>

// Application headers
#include "action_wrapper.h"

// --- Main user interface --- //
class MainUi : public QObject
{
    Q_OBJECT

private:
    // Action wrapper
    QVector<ActionWrapper*> m_Actions;

    // Behaviour
    void initBehaviour(QAction *action, const qint8 &behaviour);

    // Status flags
    qint8 m_CurrentStatus;
    enum ENUM_STATUS_FLAGS {
        STATUS_DB_IS_CLOSED,
        STATUS_DB_IS_OPEN
    };

    // Main UI elements
    QStackedWidget *m_MainDisplayArea;
    QStackedWidget *m_SideBarDisplayArea;
    QToolBar *m_Toolbar;

public slots:
    // Status
    void setStatus(const bool &isDatabaseOpen);

signals:
    // Status
    void setDatabaseClosedStatus(const bool &isClosed);
    void setDatabaseOpenStatus(const bool &isOpen);

public:
    // Constructor
    MainUi(QMainWindow *parent);
    ~MainUi();

    // Add items
    void addButton(QAction *action, const qint8 &behaviour);
    void addWidget(QAction *action, QWidget *mainWidget, QWidget *sideBarWidget, const qint8 &behaviour);

    // Behaviour flags
    enum ENUM_BEHAVIOUR_FLAGS {
        ACTIVE_WHEN_DB_IS_CLOSED,
        ACTIVE_WHEN_DB_IS_OPEN,
        ALWAYS_ACTIVE
    };

    // Get data
    QWidget *getParent();
};

#endif // MAIN_UI_H
