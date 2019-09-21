#ifndef CHAR_H
#define CHAR_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Char base class --- //
class Char
{
private:
    // Underlying data
    qint8 value;

public:
    // Constructor
    Char(const qint32 &i = -1);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    short get() const;
    const QVariant variant() const;

    // Set data
    void set(const QVariant &data);
};

#endif // CHAR_H
