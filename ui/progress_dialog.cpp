#include "progress_dialog.h"

// Qt headers
#include <QCoreApplication>


/* ========================= */
/*      Progress Dialog      */
/* ========================= */

// --- Default constructor --- //
ProgressDialog::ProgressDialog(const QString &windowTitleText, const qint32 &minimum, const qint32 &maximum, QWidget *parent) :
    QProgressDialog(windowTitleText, "Cancel", minimum, maximum, parent)
{
    this->setWindowTitle(windowTitleText);
    this->setWindowModality(Qt::WindowModal);
    this->setAutoClose(true);
    this->show();
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Increment --- //
void ProgressDialog::increment(const QString &labelText)
{
    this->setLabelText(labelText);
    this->setValue(this->value() + 1);
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
}
