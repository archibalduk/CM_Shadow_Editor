#ifndef U_CHAR_H
#define U_CHAR_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Unsigned Char base class --- //
class UChar
{
private:
    // Underlying data
    quint8 value;

public:
    // Constructor
    UChar(const qint32 &i = -1);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qint16 get() const;
    const QVariant variant() const;

    // Set data
    void set(const QVariant &data);
};


#endif // U_CHAR_H
