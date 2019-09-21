#ifndef POINTER_COMBO_EDIT_H
#define POINTER_COMBO_EDIT_H

// Qt headers
#include <QComboBox>
#include <QSortFilterProxyModel>

// Application headers
#include "pointer_edit.h"

// --- Pointer combo editor --- //
class PointerComboEdit : public PointerEdit
{
private:
    // Input
    QComboBox *m_Input;

private slots:
    // Slots
    void onInputChange(const qint32 &row);
    void onPrimaryKeyChange(const QString &id);

public:
    // Constructor
    PointerComboEdit(QWidget *parent);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy);
};

#endif // POINTER_COMBO_EDIT_H
