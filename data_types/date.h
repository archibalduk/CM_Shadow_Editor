#ifndef DATE_H
#define DATE_H

// Qt headers
#include <QDataStream>
#include <QDate>
#include <QString>
#include <QVariant>

// --- CM_DATE --- //
class Date
{
private:
    QDate m_Date;

public:
    // Constructor
    Date();

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    QDate get();
    void toSIDate(qint16 &day, qint16 &year, qint32 &isLeapYear) const;
    qint16 year();

    // Set data
    void reset();
    void set(qint16 &day, qint16 &year);
    void set(const QDate &value);
};

#endif // DATE_H
