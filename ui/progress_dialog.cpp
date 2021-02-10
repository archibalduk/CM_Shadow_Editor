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

// --- Complete (increment to the final value) --- //
void ProgressDialog::complete()
{
    this->setValue(this->maximum());
}

// --- Increment --- //
void ProgressDialog::increment(const qint64 &i)
{
    this->setValue(static_cast<qint32>(this->value()+i));
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
}

// --- Increment --- //
void ProgressDialog::increment(const QString &labelText)
{
    this->setLabelText(labelText);
    this->setValue(this->value() + 1);
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
}

// --- Reset count to zero and set new title, label and range --- //
void ProgressDialog::set(const QString &text, const qint64 &maximum)
{
    // Text
    this->setWindowTitle(text);
    this->setLabelText(text);

    // Range
    this->setValue(0);
    this->setRange(0, static_cast<qint32>(maximum+1));
}

// --- Set silent/hidden mode --- //
void ProgressDialog::setSilent(const bool &silent)
{
    // Display the window (if not silent mode)
    if(!silent)
    {
        this->show();
        this->raise();
    }
    else
        this->hide();
}
