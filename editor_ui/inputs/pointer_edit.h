#ifndef POINTER_EDIT_H
#define POINTER_EDIT_H

// Qt headers
#include <QCheckBox>
#include <QCompleter>
#include <QDataWidgetMapper>
#include <QLineEdit>
#include <QSortFilterProxyModel>

// Application headers
#include "input_base_class.h"

// --- Pointer editor base class --- //
class PointerEdit : public InputBaseClass
{
    Q_OBJECT

protected:
    // Input (members)
    QCheckBox *m_CheckBox;
    QLineEdit *m_PrimaryKey;
    QWidget *m_InputWidgetPointer;

    // Input (functions)
    void setInputWidgetPointer(QWidget *input);

    // Initialisation
    QCompleter *getCompleter(QSortFilterProxyModel *proxy);

    // Mapper
    QDataWidgetMapper *m_Mapper;

    // Set data
    void setPrimaryKeyMapping(QDataWidgetMapper *mapper, const qint32 &fieldIndex);  

protected slots:
    // Checkbox
    void onCheckBoxStateChange(const qint32 &state);

    // Mapper
    void onCurrentIndexChange(const qint32 &);

signals:
    // Checkbox
    void primaryKeyChanged(const bool &isValid);

public:
    // Constructor
    PointerEdit(QWidget *parent);
};

#endif // POINTER_EDIT_H
