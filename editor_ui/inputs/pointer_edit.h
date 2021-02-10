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
    QCompleter *m_Completer;
    QLineEdit *m_PrimaryKey;
    QWidget *m_InputWidgetPointer;

    // Input (functions)
    void setInputWidgetPointer(QWidget *input);

    // Initialisation
    void setCompleter(QSortFilterProxyModel *proxy);

    // Mapper
    QDataWidgetMapper *m_Mapper;

    // Set data
    void setPrimaryKeyMapping(QDataWidgetMapper *mapper, const qint32 &fieldIndex);

    // Settings
    qint32 m_NoneValue;
    void setNoneValue(const qint32 &value);

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

    // Set data
    virtual void set(QDataWidgetMapper *mapper, const qint32 &fieldIndex, QSortFilterProxyModel *proxy,
                     const bool &isValuePointer = false) = 0;   // Abstract class
    // --- Set mapping en masse --- //
    template<typename T> static void setBatch(QVector<T*> &data, const qint32 &firstInput, const qint32 &lastInput,
                    QDataWidgetMapper *mapper, const qint32 &firstFieldIndex,
                    QSortFilterProxyModel *proxy, const bool &isValuePointer = false)
    {
        qint32 fieldIndex = firstFieldIndex;

        for(qint32 i = firstInput; i <= lastInput; ++i) {
            data[i]->set(mapper, fieldIndex, proxy, isValuePointer);
            ++fieldIndex;
        }
    }
};

#endif // POINTER_EDIT_H
