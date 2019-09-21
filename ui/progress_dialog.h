#ifndef PROGRESS_DIALOG_H
#define PROGRESS_DIALOG_H

// Qt headers
#include <QProgressDialog>

// --- Progress dialog wrapper --- //
class ProgressDialog : public QProgressDialog
{
public:
    // Constructor
    ProgressDialog(const QString &windowTitleText, const qint32 &minimum, const qint32 &maximum, QWidget *parent = nullptr);

    // Set data
    void increment(const QString &labelText);
};

#endif // PROGRESS_DIALOG_H
