#ifndef SPIN_BOX_H
#define SPIN_BOX_H

// Qt headers
#include <QSpinBox>

// Application headers
#include "input_base_class.h"

// --- Spin box editor --- //
class SpinBox : public InputBaseClass
{
private:
    // Input
    QSpinBox *m_Input;

    // Set data
    void setType(const qint8 &type);

public:
    // Field types
    enum ENUM_TYPES {
        NARROW,
        WIDE,
    };

    // Constructor
    SpinBox(QWidget *parent);

    // Get data
    qint32 getValue();

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type = NARROW);
    static void set(QVector<SpinBox*> &data, const qint32 &firstInput, const qint32 &lastInput,
                    QDataWidgetMapper *mapper, const qint32 &firstFieldIndex, const qint8 &type = NARROW);
};

#endif // SPIN_BOX_H
