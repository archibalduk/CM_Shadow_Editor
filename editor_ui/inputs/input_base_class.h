#ifndef INPUT_BASE_CLASS_H
#define INPUT_BASE_CLASS_H

// Qt headers
#include <QDataWidgetMapper>
#include <QLabel>
#include <QWidget>

// --- Field input base class --- //
class InputBaseClass : public QWidget
{
protected:
    // Label
    QLabel *m_Label;

    // Dimensions (members)
    static qint32 s_WidthHiddenField;
    static qint32 s_WidthInput;
    static qint32 s_WidthLabel;

    // Dimensions (functions)
    qint32 widthHiddenField();
    qint32 widthInput();
    qint32 widthLabel();

    // Set data
    void setLabel(QDataWidgetMapper *mapper, const qint32 &fieldIndex);

    // User interface
    void addWidget(QWidget *widget);

public:
    // Constructor
    InputBaseClass(QWidget *parent);
};

#endif // INPUT_BASE_CLASS_H
