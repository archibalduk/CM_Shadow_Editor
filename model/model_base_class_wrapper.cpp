#include "model_base_class_wrapper.h"


/* ================================== */
/*      Model Base Class Wrapper      */
/* ================================== */

// --- Default constructor --- //
ModelBaseClassWrapper::ModelBaseClassWrapper(const qint16 &tableId, QObject *parent) :
    QAbstractTableModel(parent),
    m_ShadowCheckingIsEnabled(false)
{
    m_ShadowManager.setTableId(tableId);

    // Connect shadow checking enable/disable functions
    QObject::connect(this, &ModelBaseClassWrapper::modelAboutToBeReset,
                     this, &ModelBaseClassWrapper::disableShadowChecking);
    QObject::connect(this, &ModelBaseClassWrapper::modelReset,
                     this, &ModelBaseClassWrapper::enableShadowChecking);
}


/* =============== */
/*      Flags      */
/* =============== */

// --- Flags --- //
Qt::ItemFlags ModelBaseClassWrapper::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}


/* ================== */
/*      Get Data      */
/* ================== */

// --- Check whether the row exists --- //
bool ModelBaseClassWrapper::checkRow(const QModelIndex &index) const
{
    if(index.row() < 0)
        return false;
    else
        return true;
}

// --- Get identifier string --- //
QString ModelBaseClassWrapper::getIdentifierString(const QModelIndex &index) const
{
    QModelIndex identifierIndex = this->index(index.row(), Identifier);
    return this->data(identifierIndex).toString();
}


/* ===================== */
/*      Reset Model      */
/* ===================== */

// --- Begin model reset --- //
void ModelBaseClassWrapper::beginReset()
{
    this->beginResetModel();
}

// --- End model reset --- //
void ModelBaseClassWrapper::endReset()
{
    this->endResetModel();
}


/* ====================== */
/*      Shadow Edits      */
/* ====================== */

// --- Disable shadow checking --- //
void ModelBaseClassWrapper::disableShadowChecking()
{
    m_ShadowCheckingIsEnabled = false;
}

// --- Enable shadow checking --- //
void ModelBaseClassWrapper::enableShadowChecking()
{
    m_ShadowCheckingIsEnabled = true;
}


/* ======================= */
/*      Validate Data      */
/* ======================= */

// --- Get shadow value if available --- //
QVariant ModelBaseClassWrapper::shadow(const QModelIndex &index) const
{
    // Do not check any Display Text, Identifier or Id - OR - if the model is being reset (for performance reasons)
    if(index.column() < FIRST_ITEM || !m_ShadowCheckingIsEnabled)
        return QVariant();  // Return a null QVariant. Null = no shadow edit found.

    // Check for a shadow edit
    const QString identifierString = this->getIdentifierString(index);
    return m_ShadowManager.findEditItem(identifierString, index);
}

// --- Validate data --- //
bool ModelBaseClassWrapper::validate(const QModelIndex &index, const QVariant &value, const qint32 &role)
{
    // Return true if the underlying data may be updated
    // Return false if the underlying data may not be updated

    // Abort if the EditRole is not used
    if(role != Qt::EditRole && role != SpreadsheetRole)
        return false;

    // Check whether any change has actually been made (i.e. whether the new value is any different to the existing value --- //
    else if(this->data(index) == value)
        return false;   // Do nothing as no change has been made

    // Check if shadow edits are being recorded
    else if(m_ShadowManager.isDisabled())
        return true;    // Nothing is being recorded -> Accept edits to the underlying data

    // Record the shadow edit
    const QString identifierString = this->getIdentifierString(index);
    m_ShadowManager.add(identifierString, index, value);

    emit dataChanged(index, index);
    return false;   // Changes are being recorded -> Do not accept edits to the underlying data
}
