#ifndef VALUE_POINTER_H
#define VALUE_POINTER_H

// Qt headers
#include <QDataStream>
#include <QStringList>
#include <QVariant>

// Application headers
#include "../data_types/char.h"

// --- Value pointer base class --- //
class ValuePointer : public Char
{
protected:
    // Underlying data
    Char m_Value;

    // Static text strings
    const static QString s_ErrorMessageInvalidId;
    const static QString s_None;

    // Get data
    QString getText_Actual(QStringList &data);

    // Sanity check
    bool isValid_Actual(const QStringList &data);
    bool isValid_Actual(const QStringList &data, const qint32 &value);

    // Set data
    bool set_Actual(const QStringList &data, const qint32 &value);

public:
    // Default constructor
    ValuePointer(const qint8 &value = -1);
    virtual ~ValuePointer() {}

    // Get data
    virtual QString getText() = 0; // Abstract function
    virtual bool isNone();
    virtual bool isPointer();

    // Sanity check
    virtual bool isValid() = 0; // Abstract function

    // Set data
    virtual bool set(const qint32 &value) = 0; // Abstract function
    virtual bool set(const QVariant &value) = 0; // Abstract function

};

#endif // VALUE_POINTER_H
