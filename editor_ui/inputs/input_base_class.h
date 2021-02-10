#ifndef INPUT_BASE_CLASS_H
#define INPUT_BASE_CLASS_H

// Qt headers
#include <QDataWidgetMapper>
#include <QLabel>
#include <QWidget>

// --- Field input base class --- //
class InputBaseClass : public QWidget
{
    Q_OBJECT

protected:
    // Label
    QLabel *m_Label;

    // Dimensions (members)
    static qint32 s_WidthHiddenField;
    static qint32 s_WidthInput;
    static qint32 s_WidthLabel;
    static qint32 s_WidthSpinBox;

    // Dimensions (functions)
    qint32 widthHiddenField();
    qint32 widthInput();
    qint32 widthLabel();
    qint32 widthSpinBox();

    // User interface
    void addWidget(QWidget *widget);

signals:
    void changed(const QString &text);

public:
    // Constructor
    InputBaseClass(QWidget *parent);

    // Set data
    void setLabel(QDataWidgetMapper *mapper, const qint32 &fieldIndex);

    // Signals
    void onChange(const QString &text);
};

#endif // INPUT_BASE_CLASS_H
