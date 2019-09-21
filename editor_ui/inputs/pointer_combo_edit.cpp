#include "pointer_combo_edit.h"

// Qt headers
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
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set mapping --- //
void PointerComboEdit::set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy)
{
    // Primary key
    this->setPrimaryKeyMapping(mapper, fieldIndex);

    // Completer
    QCompleter *completer = this->getCompleter(proxy);

    // Input
    m_Input->setEditable(true);
    m_Input->setModel(proxy);
    m_Input->setCompleter(completer);
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

    // Submit the change to the underlying mode
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

    if(list.size() < 1)
        return;

    m_Input->blockSignals(true);
    m_Input->setCurrentIndex(list[0].row());
    m_Input->blockSignals(false);

    // Update the checkbox
    emit primaryKeyChanged(m_PrimaryKey->text().toInt() >= 0);
}
