#ifndef LINE_EDIT_H
#define LINE_EDIT_H

// Qt headers
#include <QLineEdit>

// Application headers
#include "input_base_class.h"

// --- Standard line/field editor --- //
class LineEdit : public InputBaseClass
{
private:
    // Input
    QLineEdit *m_Input;

public:
    // Field types
    enum ENUM_TYPES {
        TEXT,
        DECIMAL,
        NUMBER,
    };

    // Constructor
    LineEdit(QWidget *parent);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type = TEXT);
};

#endif // LINE_EDIT_H
