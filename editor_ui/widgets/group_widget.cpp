#include "group_widget.h"


/* ====================== */
/*      Group Widget      */
/* ====================== */

// --- Default constructor --- //
GroupWidget::GroupWidget(const QString &title, QWidget *parent, const qint32 &limit) :
    QGroupBox(title, parent),
    m_Col(0),
    m_Row(0),
    m_Limit(limit)
{
    // Layout
    m_Layout = new QGridLayout(this);
    m_Layout->setRowStretch(limit, 10);
    m_Layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_Layout);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Add a widget to the layout --- //
void GroupWidget::add(QWidget *widget)
{
    // Increment the column position if beyond the row limit
    if(m_Row >= m_Limit) {
        m_Row = 0;
        ++m_Col;
    }

    this->m_Layout->addWidget(widget, m_Row, m_Col);

    ++m_Row;
}
