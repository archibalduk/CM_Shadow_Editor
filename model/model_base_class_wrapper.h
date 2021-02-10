#ifndef MODEL_BASE_CLASS_WRAPPER_H
#define MODEL_BASE_CLASS_WRAPPER_H

// Qt headers
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QString>

// Application headers
#include "../shadow/shadow_common.h"
#include "../shadow/shadow_manager.h"

// --- Table model base class --- //
class ModelBaseClassWrapper : public QAbstractTableModel
{
    Q_OBJECT

    // NOTE: Avoid adding static data members as this appears to cause memory access violation crashes when running in a debug build

protected:
    // Column count
    qint32 m_ColumnCount;

    // Shadow edits
    ShadowManager m_ShadowManager;
    bool m_ShadowCheckingIsEnabled;

    // Get data
    bool checkRow(const QModelIndex &index) const;
    QString getIdentifierString(const QModelIndex &index) const;

    // Validate data
    QVariant shadow(const QModelIndex &index) const;
    bool validate(const QModelIndex &index, const QVariant &value, const qint32 &role);

public slots:
    // Reset
    void beginReset();
    void endReset();

    // Shadow edits
    void disableShadowChecking();
    void enableShadowChecking();

public:
    // Constructor
    ModelBaseClassWrapper(const qint16 &tableId, QObject *parent);

    // Flags
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    // --- Column numbers --- //
    enum ENUM_INITIAL_COLUMNS {
        DisplayText = 0,
        Identifier,
        Id,
        FIRST_ITEM  // Used for the first item enum value in sub-classes
    };

    // --- Flags --- //
    enum ENUM_FLAGS {
        SpreadsheetRole = Qt::UserRole
    };
};

#endif // MODEL_BASE_CLASS_WRAPPER_H
