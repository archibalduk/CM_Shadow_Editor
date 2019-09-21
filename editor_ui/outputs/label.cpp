#include "label.h"

/* ========================= */
/*      Read-only Label      */
/* ========================= */

// --- Default constructor --- //
Label::Label(QWidget *parent, const qint8 &type) :
    QLineEdit(parent)
{
    this->setReadOnly(true);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void Label::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex)
{
    mapper->addMapping(this, fieldIndex);
}
