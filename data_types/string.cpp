#include "string.h"

// Qt headers
#include <QByteArray>
#include <QRegExp>


/* =============== */
/*      String     */
/* =============== */

// --- Default constructor --- //
String::String() :
    m_String()
{
}

/* ================= */
/*      File I/O     */
/* ================= */

// --- Read raw char to String --- //
void String::read(QDataStream &stream, const quint16 &textLength)
{
    // Resere the maximum text length for memory efficiency given that it can never exceed this
    m_String.reserve(textLength);

    // Read the raw data into the buffer
    QByteArray ba(textLength, 0);
    stream.readRawData(ba.data(), textLength);

    // Fix any raw data strings which contain a null terminator mid-string
    for(qint32 i = 0; i < textLength-2; ++i) {
        if(ba[i] == '\x00' && ba[i+1] != '\x00')
            ba[i] = '\x20';
    }

    // Convert the buffered raw data to a QString
    m_String = QString::fromLatin1(ba);
    m_String.replace(0x0099, 0x2122); // Convert from EHM 200x/1 TM (trademark) to UTF symbol
}

// --- Write String to raw char --- //
void String::write(QDataStream &stream, const quint16 &textLength)
{
    QByteArray ba(textLength, '\x00');
    ba.replace(0, m_String.size(), m_String.toLatin1());

    // Write raw data
    stream.writeRawData(ba, textLength);
}


/* ================= */
/*      Get Data     */
/* ================= */

// --- Get as QString --- //
QString String::get() const
{
    return m_String;
}

// --- Get as a simple/match string --- //
QString String::getSimpleString()
{
    return this->toSimpleString(m_String);
}

// --- Is empty? --- //
bool String::isEmpty()
{
    return m_String.trimmed().isEmpty();
}

// --- Convert a text string to a simple/match string --- //
QString String::toSimpleString(const QString &text)
{
    QString t = text.trimmed().toLower();

    // Importer-specific
    t.replace(",", "_");
    t.replace(";", "_");
    t.replace("-", " "); // Hyphen -> Space

    // Remove characters to be ignored
    t.remove(".");
    t.remove("'");
    t.remove(0x2122);    // Trademark

    // Replace characters not corrected by normalising
    t.replace("ø", "o");

    // Remove accents and convert for Latin-1
    t = text.normalized(QString::NormalizationForm_KD).remove(QRegExp("^a-zA-Z\\s\\d_:")).toLatin1();

    // Remove any question marks left over from conversion to Latin-1
    return t.remove("?");
}


/* ================= */
/*      Set Data     */
/* ================= */

// --- Set string --- //
void String::set(const QString &string)
{
    const qint32 capacity = m_String.capacity();

    // If within the underlying string's capacity
    if(string.size() <= capacity)
        m_String = string;
    // If the new string exceeds the underlying string's capacity
    else
        m_String = string.left(capacity);
}

// --- Set string (QVariant wrapper) --- //
void String::set(const QVariant &value)
{
    this->set(value.toString());
}

// --- Set string capacity --- //
void String::setCapacity(const qint32 &capacity)
{
    m_String.reserve(capacity);
}
