#include "spin_box.h"

/* ========================= */
/*      Spin Box Editor      */
/* ========================= */

// --- Default constructor --- //
SpinBox::SpinBox(QWidget *parent) :
    InputBaseClass(parent)
{
    // Spin box edit/input
    m_Input = new QSpinBox(this);
    this->addWidget(m_Input);

    // Signal
    QObject::connect(m_Input, QOverload<const QString &>::of(&QSpinBox::valueChanged),
                     this, &InputBaseClass::changed);
}


/* ================== */
/*      Get data      */
/* ================== */

// --- Get value --- //
qint32 SpinBox::getValue()
{
    return m_Input->value();
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void SpinBox::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type)
{
    // Mapping
    mapper->addMapping(m_Input, fieldIndex);

    // Label/field title
    this->setLabel(mapper, fieldIndex);
    this->setType(type);
}

// --- Set mapping en masse --- //
void SpinBox::set(QVector<SpinBox*> &data, const qint32 &firstInput, const qint32 &lastInput,
                   QDataWidgetMapper *mapper, const qint32 &firstFieldIndex, const qint8 &type)
{
    qint32 fieldIndex = firstFieldIndex;

    for(qint32 i = firstInput; i <= lastInput; ++i) {
        data[i]->set(mapper, fieldIndex, type);
        ++fieldIndex;
    }
}

// --- Set spin box type --- //
void SpinBox::setType(const qint8 &type)
{
    // Wide
    if(type == WIDE) {
        m_Input->setFixedWidth(this->widthSpinBox());
        m_Input->setRange(-99999999,2147483647);
    }
    // Narrow / default
    else {
        m_Input->setFixedWidth(this->widthSpinBox());
        m_Input->setRange(-15,200);
    }
}
