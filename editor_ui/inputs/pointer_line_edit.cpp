#include "pointer_line_edit.h"

// Qt headers
#include <QModelIndex>
#include <QModelIndexList>

// Application headers
#include "../../model/model_base_class_wrapper.h"

/* ============================== */
/*      Pointer Combo Editor      */
/* ============================== */

// --- Default constructor --- //
PointerLineEdit::PointerLineEdit(QWidget *parent) :
    PointerEdit(parent)
{
    // Combo input
    m_Input = new QLineEdit(this);
    this->addWidget(m_Input);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void PointerLineEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy, const bool &isValuePointer)
{
    // If this is a value pointer rather than a database pointer, update the _None / _Invalid threshold value to zero instead of -1
    if(isValuePointer)
        this->setNoneValue(0);

    // Primary key
    this->setPrimaryKeyMapping(mapper, fieldIndex);

    // Completer
    this->setCompleter(proxy);

    // Input
    m_Input->setCompleter(m_Completer);
    this->setInputWidgetPointer(m_Input);

    // Connections
    QObject::connect(m_Completer, QOverload<const QModelIndex &>::of(&QCompleter::activated),
                     this, &PointerLineEdit::onInputChange);
    QObject::connect(m_PrimaryKey, &QLineEdit::textChanged,
                     this, &PointerLineEdit::onPrimaryKeyChange);
}


/* =============== */
/*      Slots      */
/* =============== */

// --- On input change --- //
void PointerLineEdit::onInputChange(const QModelIndex &index)
{
    // Temporarily block signals to the line edit in order to prevent a feedback loop
    m_Input->blockSignals(true);

    // Update hidden field with value
    QAbstractItemModel *pointerModel = m_Completer->completionModel();
    QModelIndex pointerIndex = pointerModel->index(index.row(), ModelBaseClassWrapper::Id);
    m_PrimaryKey->setText(pointerModel->data(pointerIndex).toString());

    // Submit the change to the underlying model
    QAbstractItemModel *dataModel = m_Mapper->model();
    QModelIndex dataIndex = dataModel->index(m_Mapper->currentIndex(), m_Mapper->mappedSection(m_PrimaryKey));
    dataModel->setData(dataIndex, m_PrimaryKey->text());

    // Re-enable signals
    m_Input->blockSignals(false);
}

// --- On primary key change --- //
void PointerLineEdit::onPrimaryKeyChange(const QString &id)
{
    // Find the row with relevant Id
    QAbstractItemModel *model = m_Completer->model();
    QModelIndexList list = model->match(model->index(0, ModelBaseClassWrapper::Id),
                                                   Qt::DisplayRole,
                                                   id,
                                                   1,
                                                   Qt::MatchExactly);

    if(list.size() < 1) {
        m_Input->clear();
        m_CheckBox->setChecked(false);
        return;
    }

    QModelIndex index = model->index(list[0].row(), ModelBaseClassWrapper::DisplayText);

    m_Input->blockSignals(true);
    m_Input->setText(model->data(index).toString());
    m_Input->blockSignals(false);

    // Update the checkbox
    emit primaryKeyChanged(m_PrimaryKey->text().toInt() > m_NoneValue);
}
