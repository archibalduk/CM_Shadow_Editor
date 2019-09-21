#include "action_wrapper.h"


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
