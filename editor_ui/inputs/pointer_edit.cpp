#include "pointer_edit.h"

// Qt headers
#include <QListView>
#include <QSettings>

/* ======================== */
/*      Pointer Editor      */
/* ======================== */

// --- Default constructor --- //
PointerEdit::PointerEdit(QWidget *parent) :
    InputBaseClass(parent),
    m_NoneValue(-1)
{
    // Primary key input (usually hidden from the user)
    m_PrimaryKey = new QLineEdit(this);
    m_PrimaryKey->setReadOnly(true);
    m_PrimaryKey->setFixedWidth(this->widthHiddenField());
    this->addWidget(m_PrimaryKey);

    // Checkbox
    m_CheckBox = new QCheckBox(this);

    // Show/hide the primary key input depending on whether debug mode is enabled
    QSettings settings;

    if(settings.value("debug_mode", false).toBool()) {
        m_PrimaryKey->setHidden(false);
        m_Label->setFixedWidth(m_Label->width() - (this->widthHiddenField() + 5));
    }
    else {
        m_PrimaryKey->setHidden(true);
    }

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
        m_PrimaryKey->setText(QString::number(m_NoneValue));

        // Submit the change to the underlying mode
        QAbstractItemModel *dataModel = m_Mapper->model();
        QModelIndex dataIndex = dataModel->index(m_Mapper->currentIndex(), m_Mapper->mappedSection(m_PrimaryKey));
        dataModel->setData(dataIndex, m_PrimaryKey->text());
    }
}


/* ======================== */
/*      Initialisation      */
/* ======================== */

// --- Set/init completer --- //
void PointerEdit::setCompleter(QSortFilterProxyModel *proxy)
{
    m_Completer = new QCompleter(proxy, this);
    m_Completer->setCaseSensitivity(Qt::CaseInsensitive);
    m_Completer->setCompletionMode(QCompleter::PopupCompletion);
    m_Completer->setFilterMode(Qt::MatchContains);
    m_Completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);

    // Optimisation
    QListView *view = static_cast<QListView*>(m_Completer->popup());
    view->setUniformItemSizes(true);
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
    const bool isValid = (m_PrimaryKey->text().toInt() > m_NoneValue);

    m_CheckBox->blockSignals(true);
    m_CheckBox->setChecked(isValid);
    m_InputWidgetPointer->setEnabled(isValid);
    m_CheckBox->blockSignals(false);
}


/* ================== */
/*      Set data      */
/* ================== */

// --- Set the value which indicates _None or _Invalid --- //
void PointerEdit::setNoneValue(const qint32 &value)
{
    // Usually this value is -1 for database pointers and 0 for value pointers
    m_NoneValue = value;
}

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
