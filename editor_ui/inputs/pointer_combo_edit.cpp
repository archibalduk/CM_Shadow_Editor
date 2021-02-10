#include "pointer_combo_edit.h"

// Qt headers
#include <QListView>
#include <QModelIndex>
#include <QModelIndexList>

// Application headers
#include "../../model/model_base_class_wrapper.h"

/* ============================== */
/*      Pointer Combo Editor      */
/* ============================== */

// --- Default constructor --- //
PointerComboEdit::PointerComboEdit(QWidget *parent) :
    PointerEdit(parent)
{
    // Combo input
    m_Input = new QComboBox(this);
    this->addWidget(m_Input);

    // Optimisation
    QListView *view = static_cast<QListView*>(m_Input->view());
    view->setUniformItemSizes(true);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void PointerComboEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy, const bool &isValuePointer)
{
    // If this is a value pointer rather than a database pointer, update the _None / _Invalid threshold value to zero instead of -1
    if(isValuePointer)
        this->setNoneValue(0);

    // Primary key
    this->setPrimaryKeyMapping(mapper, fieldIndex);

    // Completer
    this->setCompleter(proxy);

    // Input
    m_Input->setEditable(true);
    m_Input->setModel(proxy);
    m_Input->setCompleter(m_Completer);
    this->setInputWidgetPointer(m_Input);

    // Connections
    QObject::connect(m_Input, QOverload<qint32>::of(&QComboBox::currentIndexChanged),
                     this, &PointerComboEdit::onInputChange);
    QObject::connect(m_PrimaryKey, &QLineEdit::textChanged,
                     this, &PointerComboEdit::onPrimaryKeyChange);
}


/* =============== */
/*      Slots      */
/* =============== */

// --- On input change --- //
void PointerComboEdit::onInputChange(const qint32 &row)
{
    // Temporarily block signals to the combo in order to prevent a feedback loop
    m_Input->blockSignals(true);

    // Update hidden field with value
    QAbstractItemModel *pointerModel = m_Input->model();
    QModelIndex pointerIndex = pointerModel->index(row, ModelBaseClassWrapper::Id);
    m_PrimaryKey->setText(pointerModel->data(pointerIndex).toString());

    // Submit the change to the underlying model
    QAbstractItemModel *dataModel = m_Mapper->model();
    QModelIndex dataIndex = dataModel->index(m_Mapper->currentIndex(), m_Mapper->mappedSection(m_PrimaryKey));
    dataModel->setData(dataIndex, m_PrimaryKey->text());

    // Re-enable signals
    m_Input->blockSignals(false);
}

// --- On primary key change --- //
void PointerComboEdit::onPrimaryKeyChange(const QString &id)
{
    // Find the row with relevant Id
    QAbstractItemModel *model = m_Input->model();
    QModelIndexList list = model->match(model->index(0, ModelBaseClassWrapper::Id),
                                                   Qt::DisplayRole,
                                                   id,
                                                   1,
                                                   Qt::MatchExactly);

    if(list.size() < 1) {
        m_Input->clearEditText();
        m_CheckBox->setChecked(false);
        return;
    }

    m_Input->blockSignals(true);
    m_Input->setCurrentIndex(list[0].row());
    m_Input->blockSignals(false);

    // Update the checkbox
    emit primaryKeyChanged(m_PrimaryKey->text().toInt() > m_NoneValue);
}
