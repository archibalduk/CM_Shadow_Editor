#ifndef SHADOW_GROUP_MODEL_H
#define SHADOW_GROUP_MODEL_H

// Qt headers
#include <QAbstractTableModel>
#include <QVector>

// Application headers
#include "../shadow_group.h"

// --- Shadow group model --- //
class ShadowGroupModel : public QAbstractTableModel
{
private:
    // Data
    QVector<ShadowGroup> m_Data;

public:
    // Constructor
    ShadowGroupModel(QObject *parent = nullptr);

    // Counts
    qint32 columnCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;
    qint32 rowCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;

    // Add data
    qint32 add(const QString &identifier);

    // Get data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVector<ShadowEditItem> *editItems(const qint32 &row);
    QVariant findEditItem(const qint32 &row, const QModelIndex &index);

    // Flags
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Set data
    bool addEditItem(const qint32 &row, const QModelIndex &index, const QVariant &value);
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

    // --- Column numbers --- //
    enum ENUM_COLUMNS {
        DisplayText = 0,
        Idenfier,
        RowId,
        TableId,
        COLUMN_COUNT  // Used for the first item enum value in sub-classes
    };
};

#endif // SHADOW_GROUP_MODEL_H
