#include "pointer_edit.h"

/* ======================== */
/*      Pointer Editor      */
/* ======================== */

// --- Default constructor --- //
PointerEdit::PointerEdit(QWidget *parent) :
    InputBaseClass(parent)
{
    // Primary key input (usually hidden from the user)
    m_PrimaryKey = new QLineEdit(this);
    m_PrimaryKey->setReadOnly(true);
    m_PrimaryKey->setFixedWidth(this->widthHiddenField());
    this->addWidget(m_PrimaryKey);

    // Checkbox
    m_CheckBox = new QCheckBox(this);

    QObject::connect(this, &PointerEdit::primaryKeyChanged,
                     m_CheckBox, &QCheckBox::setChecked);
    QObject::connect(m_CheckBox, &QCheckBox::stateChanged,
                     this, &PointerEdit::onCheckBoxStateChange);
}


/* =================== */
/*      Check Box      */
/* =================== */

// --- On checkbox state change --- //
void PointerEdit::onCheckBoxStateChange(const qint32 &state)
{
    const bool isChecked = (state == Qt::Checked);
    m_InputWidgetPointer->setEnabled(isChecked);

    if(!isChecked) {
        m_PrimaryKey->setText(QString::number(-1));

        // Submit the change to the underlying mode
        QAbstractItemModel *dataModel = m_Mapper->model();
        QModelIndex dataIndex = dataModel->index(m_Mapper->currentIndex(), m_Mapper->mappedSection(m_PrimaryKey));
        dataModel->setData(dataIndex, m_PrimaryKey->text());
    }
}


/* ======================== */
/*      Initialisation      */
/* ======================== */

// --- Get/init completer --- //
QCompleter *PointerEdit::getCompleter(QSortFilterProxyModel *proxy)
{
    QCompleter *completer = new QCompleter(proxy, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setCompletionMode(QCompleter::InlineCompletion);
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    return completer;
}

// --- Set pointer to input widget --- //
void PointerEdit::setInputWidgetPointer(QWidget *input)
{
    m_InputWidgetPointer = input;

    // Width
    if(m_PrimaryKey->isVisible())
        m_InputWidgetPointer->setFixedWidth(this->widthInput() - this->widthHiddenField() - 10);
    else
        m_InputWidgetPointer->setFixedWidth(this->widthInput());
}


/* ================ */
/*      Mapper      */
/* ================ */

// --- On mapper current index change --- //
void PointerEdit::onCurrentIndexChange(const qint32 &)
{
    const bool isValid = (m_PrimaryKey->text().toInt() >= 0);

    m_CheckBox->blockSignals(true);
    m_CheckBox->setChecked(isValid);
    m_InputWidgetPointer->setEnabled(isValid);
    m_CheckBox->blockSignals(false);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set primary key mapping --- //
void PointerEdit::setPrimaryKeyMapping(QDataWidgetMapper *mapper, const qint32 &fieldIndex)
{
    // Mapping
    m_Mapper = mapper;
    m_Mapper->addMapping(m_PrimaryKey, fieldIndex);

    QObject::connect(m_Mapper, &QDataWidgetMapper::currentIndexChanged,
                     this, &PointerEdit::onCurrentIndexChange);

    // Label/field title
    this->setLabel(mapper, fieldIndex);

    // Append the checkbox now that the layout has been set by the base class
    this->addWidget(m_CheckBox);
}
