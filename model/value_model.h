#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H

// Qt headers
#include <QAbstractTableModel>
#include <QStringList>

// --- Value model --- //
class ValueModel : public QAbstractTableModel
{
private:
    // Underlying data
    QStringList *m_Data;

public:
    // Constructor
    ValueModel(QStringList &data, QObject *parent = nullptr);

    // Counts
    qint32 columnCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;
    qint32 rowCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;

    // Data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(qint32 section, Qt::Orientation orientation, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Columns
    enum ENUM_COLUMNS {
        Text,
        Identifier,
        Id,
        COLUMN_COUNT
    };
};

#endif // VALUE_MODEL_H
