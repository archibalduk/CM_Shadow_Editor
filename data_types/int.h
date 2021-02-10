#ifndef INT_H
#define INT_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Integer base class --- //
class Int
{
protected:
    // Underlying data
    qint32 value;

public:
    // Constructor
    Int(const qint32 &i = -1);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qint32 get() const;
    bool isPointer() const;
    const QVariant variant() const;

    // Set data
    void copy(const Int &data);
    void set(const QVariant &data);
    void set(const qint32 &i);
};

#endif // INT_H
