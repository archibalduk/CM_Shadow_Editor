#ifndef TABLE_WIDGET_H
#define TABLE_WIDGET_H

// Qt headers
#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QWidget>

// --- QTableView wrapper --- //
class TableWidget : public QWidget
{
private:
    // Table
    QTableView *m_Table;

public:
    // Constructor
    TableWidget(QWidget *parent);

    // Model
    void setSourceModel(QAbstractTableModel *model);
    void setSourceModel(QSortFilterProxyModel *model);
};

#endif // TABLE_WIDGET_H
