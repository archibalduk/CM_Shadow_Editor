#ifndef DATE_EDIT_H
#define DATE_EDIT_H

// Qt headers
#include <QDateEdit>

// Application headers
#include "input_base_class.h"

// --- Standard line/field editor --- //
class DateEdit : public InputBaseClass
{
private:
    // Input
    QDateEdit *m_Input;

public:
    // Constructor
    DateEdit(QWidget *parent);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex);
};

#endif // DATE_EDIT_H
