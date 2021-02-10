#ifndef STRING_H
#define STRING_H

// Qt headers
#include <QDataStream>
#include <QString>
#include <QVariant>

// --- QString <--> SI String wrapper/interface class --- //
class String
{
private:
    // Text string
    QString m_String;

public:
    // Constructor
    String();

    // File I/O
    void read(QDataStream &stream, const quint16 &textLength);
    void write(QDataStream &stream, const quint16 &textLength);

    // Get data
    QString get() const;
    QString getSimpleString();
    bool isEmpty();
    static QString toSimpleString(const QString &text);

    // Text lengths
    enum ENUM_TEXT_LENGTHS {
        MAX_INDEX_NAME = 50,
        THREE_LETTER_LENGTH = 4,
        SHORT_TEXT_LENGTH = 26,
        STANDARD_TEXT_LENGTH = 51,
        LONG_TEXT_LENGTH = 101
    };

    // Set data
    void set(const QString &string);
    void set(const QVariant &value);
    void setCapacity(const qint32 &capacity);
};

#endif // STRING_H
