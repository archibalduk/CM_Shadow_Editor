#ifndef DOUBLE_H
#define DOUBLE_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Double base class --- //
class Double
{
private:
    // Underlying data
    qreal value;

public:
    // Constructor
    Double(const qreal &i = -1);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    qreal get() const;
    const QVariant variant() const;

    // Operator overloading (Data Stream)
    friend QDataStream & operator >> (QDataStream &in, Double &data);
    friend QDataStream & operator << (QDataStream &out, const Double &data);

    // Set data
    void set(const QVariant &data);
};

#endif // DOUBLE_H
