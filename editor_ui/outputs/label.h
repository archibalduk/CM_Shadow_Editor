#ifndef LABEL_H
#define LABEL_H

// Qt headers
#include <QDataWidgetMapper>
#include <QLineEdit>

// --- Read only label capable of being mapped to a model --- //
class Label : public QLineEdit
{
public:
    // Constructor
    Label(QWidget *parent, const qint8 &type = STANDARD);

    // Set data
    void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex);

    // Label types
    enum ENUM_TYPES {
        STANDARD,
        TITLE
    };
};

#endif // LABEL_H
