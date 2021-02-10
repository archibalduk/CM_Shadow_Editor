#ifndef POINTER_H
#define POINTER_H

// Qt headers
#include <QDataStream>
#include <QVariant>
#include <QVector>
#include <QString>

// --- Database pointer base class --- //
class Pointer
{
protected:
    // Underlying data
    qint32 m_Id;

    // Static text strings
    const static QString s_ErrorMessageInvalidId;
    const static QString s_None;

    // --- Get data: Get id --- //
    qint32 getId() const
    {
        return m_Id;
    }

    // --- Get data: Get text --- //
    template<typename T_Data> QString getText_Actual(QVector<T_Data> &data) const
    {
        // Sanity check
        if(m_Id < 0)
            return s_None;
        else if(m_Id >= data.size())
            return s_ErrorMessageInvalidId;
        else
            return data[m_Id].getName();
    }

    // --- Sanity check: Check whether the current value is within range --- //
    template<typename T_Data> bool isValid_Actual(QVector<T_Data> &data)
    {
        return(m_Id >= -1 && m_Id < data.size());
    }

    // --- Sanity check: Check whether the selected value is within range --- //
    template<typename T_Data> bool isValid_Actual(QVector<T_Data> &data, const qint32 &id)
    {
        return(id >= -1 && id < data.size());
    }

    // --- Set data:: Set id --- //
    template<typename T_Data> bool set_Actual(QVector<T_Data> &data, const qint32 &id)
    {
        // Sanity check
        if(!this->isValid_Actual(data, id))
            return false;
        else {
            m_Id = id;
            return true;
        }
    }

public:
    // Default constructor
    Pointer(const qint32 &id = -1);
    virtual ~Pointer() {}

    // File I/O
    void read(QDataStream &in);
    void write(QDataStream &out);

    // Get data
    virtual QVariant get(const qint32 &role = Qt::DisplayRole) const = 0; // Abstract function
    virtual QString getText() const;
    virtual bool isNone() const;
    virtual bool isPointer() const;

    // Sanity check
    virtual bool isValid() = 0; // Abstract function

    // Set data
    virtual bool set(const qint32 &id) = 0; // Abstract function
    virtual bool set(const QVariant &value) = 0; // Abstract function
};

#endif // POINTER_H
