#include "action_wrapper.h"

// Qt headers
#include <QIcon>
#include <QSettings>

/* ======================== */
/*      Action Wrapper      */
/* ======================== */

// --- Default constructor --- //
ActionWrapper::ActionWrapper()
{

}

// --- Actual constructor --- //
ActionWrapper::ActionWrapper(QAction *action, const qint32 &indexMainArea, const qint32 &indexSideBar) :
    m_Action(action),
    m_IndexMainArea(indexMainArea),
    m_IndexSideBar(indexSideBar)
{
    QObject::connect(m_Action, &QAction::triggered,
                     this, &ActionWrapper::onTrigger);

    // Icon
    QSettings settings;
    if(settings.value("show_icons", false).toBool()) {
        const QIcon icon(QString(":/icons/%1.png").arg(action->text().toLower().replace(" ", "_", Qt::CaseInsensitive)));
        action->setIcon(icon);
    }
}

// --- Destructor --- //
ActionWrapper::~ActionWrapper()
{

}


/* ============== */
/*      Slot      */
/* ============== */

// --- Slot --- //
void ActionWrapper::onTrigger()
{
    if(m_IndexMainArea >= 0)
        emit triggeredMainArea(m_IndexMainArea);

    if(m_IndexSideBar >= 0)
        emit triggeredSideBar(m_IndexSideBar);
}
