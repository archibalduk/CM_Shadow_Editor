#include "date_edit.h"

/* =========================== */
/*      Date/Field Editor      */
/* =========================== */

// --- Default constructor --- //
DateEdit::DateEdit(QWidget *parent) :
    InputBaseClass(parent)
{
    // Line edit/input
    m_Input = new QDateEdit(this);
    m_Input->setFixedWidth(this->widthInput());
    m_Input->setCalendarPopup(true);
    this->addWidget(m_Input);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void DateEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex)
{
    // Mapping
    mapper->addMapping(m_Input, fieldIndex);

    // Label/field title
    this->setLabel(mapper, fieldIndex);
}
