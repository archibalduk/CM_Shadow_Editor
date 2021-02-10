#ifndef POINTER_LINE_EDIT_H
#define POINTER_LINE_EDIT_H

// Qt headers
#include <QLineEdit>
#include <QSortFilterProxyModel>

// Application headers
#include "pointer_edit.h"

// --- Pointer line editor --- //
class PointerLineEdit : public PointerEdit
{
private:
    // Input
    QLineEdit *m_Input;

private slots:
    // Slots
    void onInputChange(const QModelIndex &index);
    void onPrimaryKeyChange(const QString &id);

public:
    // Constructor
    PointerLineEdit(QWidget *parent);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy, const bool &isValuePointer = false);
};

#endif // POINTER_LINE_EDIT_H
