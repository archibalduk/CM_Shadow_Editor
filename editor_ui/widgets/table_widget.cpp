#include "table_widget.h"

// Qt headers
#include <QGridLayout>


/* ====================== */
/*      Table Widget      */
/* ====================== */

// --- Default constructor --- //
TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent)
{
    // Table
    m_Table = new QTableView(this);

    // Layout
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(m_Table);
    this->setLayout(layout);
}


/* =============== */
/*      Model      */
/* =============== */

// --- Set source model --- //
void TableWidget::setSourceModel(QAbstractTableModel *model)
{
    m_Table->setModel(model);
}

// --- Set source model (proxy) --- //
void TableWidget::setSourceModel(QSortFilterProxyModel *model)
{
    m_Table->setModel(model);
}
