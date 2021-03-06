#include "input_base_class.h"

// Qt headers
#include <QAbstractItemModel>
#include <QHBoxLayout>

// --- Static data: Widths --- //
qint32 InputBaseClass::s_WidthHiddenField = 50;
qint32 InputBaseClass::s_WidthInput = 150;
qint32 InputBaseClass::s_WidthLabel = 150;
qint32 InputBaseClass::s_WidthSpinBox = 50;


/* ========================== */
/*      Input Base Class      */
/* ========================== */

// --- Standard constructor --- //
InputBaseClass::InputBaseClass(QWidget *parent) :
    QWidget(parent)
{
    // Label
    m_Label = new QLabel(this);
    m_Label->setFixedWidth(this->widthLabel());

    // Layout
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(m_Label);
    this->setLayout(layout);
}


/* ==================== */
/*      Dimensions      */
/* ==================== */

// --- Get width: Hidden field --- //
qint32 InputBaseClass::widthHiddenField()
{
    return s_WidthHiddenField;
}

// --- Get width: Input field --- //
qint32 InputBaseClass::widthInput()
{
    return s_WidthInput;
}

// --- Get width: Label --- //
qint32 InputBaseClass::widthLabel()
{
    return s_WidthLabel;
}

// --- Get width: Spinbox field --- //
qint32 InputBaseClass::widthSpinBox()
{
    return s_WidthSpinBox;
}


/* ================== */
/*      Set Data      */
/* ================== */

// --- Set label from the field title/heading --- //
void InputBaseClass::setLabel(QDataWidgetMapper *mapper, const qint32 &fieldIndex)
{
    m_Label->setText(QString("%1:")
                     .arg(mapper->model()->headerData(fieldIndex, Qt::Horizontal).toString())
                     );
}


/* ================= */
/*      Signals      */
/* ================= */

// --- On input change --- //
void InputBaseClass::onChange(const QString &text)
{
    emit changed(text);
}


/* ======================== */
/*      User Interface      */
/* ======================== */

// --- Add a widget to the layout --- //
void InputBaseClass::addWidget(QWidget *widget)
{
    this->layout()->addWidget(widget);
}
