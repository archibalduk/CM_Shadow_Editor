#ifndef ACTION_WRAPPER_H
#define ACTION_WRAPPER_H

// Qt headers
#include <QAction>
#include <QObject>

// --- QAction wrapper for allowing a QAction to connect to a QStackedWidget
class ActionWrapper : public QObject
{
    Q_OBJECT

private:
    QAction *m_Action;
    qint32 m_IndexMainArea;
    qint32 m_IndexSideBar;

private slots:
    // Slot
    void onTrigger();

signals:
    // Signals
    void triggeredMainArea(const qint32 &index);
    void triggeredSideBar(const qint32 &index);

public:
    // Constructor
    ActionWrapper();
    ActionWrapper(QAction *action, const qint32 &indexMainArea = -1, const qint32 &indexSideBar = -1);

    // Destructor
    ~ActionWrapper();
};

#endif // ACTION_WRAPPER_H
