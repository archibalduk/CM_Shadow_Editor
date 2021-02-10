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
    void complete();
    void increment(const qint64 &i = 1);
    void increment(const QString &labelText);
    void set(const QString &text, const qint64 &maximum);

    // Silent
    void setSilent(const bool &silent);
};

#endif // PROGRESS_DIALOG_H
