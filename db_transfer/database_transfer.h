#ifndef DATABASE_TRANSFER_H
#define DATABASE_TRANSFER_H

// Qt headers
#include <QAbstractTableModel>
#include <QList>
#include <QSortFilterProxyModel>

// Application headers
#include "../spreadsheet.h"

// --- Database import/export base class --- //
class DatabaseTransfer
{
protected:
    // Columns
    QList<qint32> m_Columns;

    // Model
    QAbstractTableModel *m_Model;

    // Spreadsheet identifier
    const QString m_Identifier;

    enum ENUM_COLUMNS {// Special column numbers
        ModeColumn = 9000,
        NewNameColumn,
        NewLongNameColumn
    };

    // Cells
    QVariant data(const qint32 &row, const qint32 &col);
    QVariant data(QSortFilterProxyModel *proxy, const qint32 &row, const qint32 &col);
    QString heading(const qint32 &col);

public:
    // Default constructor
    DatabaseTransfer(QString identifier, QAbstractTableModel *model);

    // Export
    bool exportData();
    bool exportData(QSortFilterProxyModel *proxy);

    // Import
    bool importData();
};

#endif // DATABASE_TRANSFER_H
