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
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void LineEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, const qint8 &type)
{
    // Mapping
    mapper->addMapping(m_Input, fieldIndex);

    // Label/field title
    this->setLabel(mapper, fieldIndex);
}
