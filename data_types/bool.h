#ifndef BOOL_H
#define BOOL_H

// Qt headers
#include <QDataStream>
#include <QVariant>

// --- Bool base class --- //
class Bool
{
private:
    // Underlying data
    bool value;

public:
    // Constructor
    Bool(const bool &b = false);

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    bool get() const;
    const QVariant variant() const;

    // Set data
    void set(const QVariant &data);
};

#endif // BOOL_H
