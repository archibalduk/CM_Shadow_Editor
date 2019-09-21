#ifndef POINTER_H
#define POINTER_H

// Qt headers
#include <QDataStream>
#include <QVector>
#include <QString>

// --- Pointer base class --- //
class Pointer
{
protected:
    qint32 m_Id;

    // Sanity check
    template<typename T_Data> bool valid(QVector<T_Data> &data);
    virtual bool isValid(const qint32 &id) = 0; // Abstract function

    // Static text strings
    const static QString s_ErrorMessageInvalidId;

public:
    // Default constructor
    Pointer(const qint32 id = -1);
    virtual ~Pointer() {}

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qint32 get();
    virtual QString getText();
    virtual bool isNone();
    virtual bool isPointer();

    // Sanity check
    virtual bool isValid() = 0; // Abstract function

    // Set data
    virtual bool set(const qint32 &id) = 0; // Abstract function
};

#endif // POINTER_H
