#ifndef SHADOW_EDIT_ITEM_MODEL_H
#define SHADOW_EDIT_ITEM_MODEL_H

// Qt headers
#include <QAbstractTableModel>
#include <QVector>

// Application headers
#include "../shadow_edit_item.h"

// --- Shadow edit item model --- //
class ShadowEditItemModel : public QAbstractTableModel
{
private:
    // Data
    QVector<ShadowEditItem> *m_Data;

public:
    // Constructor
    ShadowEditItemModel(QObject *parent = nullptr);

    // Counts
    qint32 columnCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;
    qint32 rowCount(const QModelIndex &/*parent*/ = QModelIndex()) const Q_DECL_OVERRIDE;

    // Get data
    QVariant data(const QModelIndex &index, qint32 role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Flags
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    // Header
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    // Set data
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
    void setSourceData(QVector<ShadowEditItem> *data);

    // --- Column numbers --- //
    enum ENUM_COLUMNS {
        TableId,
        Column,
        Value,
        COLUMN_COUNT  // Used for the first item enum value in sub-classes
    };
};

#endif // SHADOW_EDIT_ITEM_MODEL_H
