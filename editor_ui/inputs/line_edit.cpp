#include "line_edit.h"

/* =========================== */
/*      Line/Field Editor      */
/* =========================== */

// --- Default constructor --- //
LineEdit::LineEdit(QWidget *parent) :
    InputBaseClass(parent)
{
    // Line edit/input
    m_Input = new QLineEdit(this);
    m_Input->setFixedWidth(this->widthInput());
    this->addWidget(m_Input);

    // Signal
    QObject::connect(m_Input, &QLineEdit::textChanged,
                     this, &InputBaseClass::changed);
}


/* =================== */
/*      Read only      */
/* =================== */

// --- Read only --- //
void LineEdit::setReadOnly(const bool &readOnly)
{
    m_Input->setReadOnly(readOnly);
    m_Input->setFrame(!readOnly);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void LineEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type)
{
    // Mapping
    mapper->addMapping(m_Input, fieldIndex);

    // Label/field title and type
    this->setLabel(mapper, fieldIndex);
    this->setType(type);
}

// --- Set mapping en masse --- //
void LineEdit::set(QVector<LineEdit*> &data, const qint32 &firstInput, const qint32 &lastInput,
                   QDataWidgetMapper *mapper, const qint32 &firstFieldIndex, const qint8 &type)
{
    qint32 fieldIndex = firstFieldIndex;

    for(qint32 i = firstInput; i <= lastInput; ++i) {
        data[i]->set(mapper, fieldIndex, type);
        ++fieldIndex;
    }
}

// --- Set text --- //
void LineEdit::setText(const QString &text)
{
    m_Input->setText(text);
}

// --- Set field type --- //
void LineEdit::setType(const qint8 &type)
{
    if(type == DECIMAL) {

    }
    else if(type == NUMBER) {

    }
    // Text / default
    else {

    }
}
