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

    // Set data
    void setType(const qint8 &type);

public:
    // Field types
    enum ENUM_TYPES {
        TEXT,
        DECIMAL,
        NUMBER,
    };

    // Constructor
    LineEdit(QWidget *parent);

    // Read only
    void setReadOnly(const bool &readOnly);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type = TEXT);
    static void set(QVector<LineEdit*> &data, const qint32 &firstInput, const qint32 &lastInput,
                    QDataWidgetMapper *mapper, const qint32 &firstFieldIndex, const qint8 &type = TEXT);
    void setText(const QString &text);
};

#endif // LINE_EDIT_H
