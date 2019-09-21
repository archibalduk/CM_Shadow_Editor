#ifndef SHORT_H
#define SHORT_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Shorteger base class --- //
class Short
{
private:
    // Underlying data
    qint16 value;

public:
    // Constructor
    Short(const qint16 &i = -1);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qint16 get() const;
    const QVariant variant() const;

    // Set data
    void set(const QVariant &data);
};

#endif // SHORT_H
