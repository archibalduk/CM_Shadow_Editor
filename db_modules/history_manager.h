#ifndef HISTORY_MANAGER_H
#define HISTORY_MANAGER_H

// Qt headers
#include <QDataStream>
#include <QFile>
#include <QString>
#include <QVector>

// Application headers
#include "../ui/progress_dialog.h"

// --- Template class for transferring histories between the .dat file and the parent table --- //
template<typename T_History, typename T_ParentData> class HistoryManager
{
private:
    // Parent data
    QVector<T_ParentData> &m_Container;

    // Data size/counter
    qint32 m_Count;

public:

    /* ======================== */
    /*      History Manager     */
    /* ======================== */

    // --- Constructor --- //
    HistoryManager(QVector<T_ParentData> &parentContainer) :
        m_Container(parentContainer),
        m_Count(0)
    {

    }


    /* ================= */
    /*      File I/O     */
    /* ================= */

    // --- Read data --- //
    bool read(ProgressDialog *progress, const QString &path, const QString &fileName)
    {
        progress->increment(fileName);

        // Open the file (read only)
        QFile file(QString("%1/%2").arg(path).arg(fileName));
        if(!file.open(QIODevice::ReadOnly))
            return false;

        // Data stream
        QDataStream in(&file);
        in.setByteOrder(QDataStream::LittleEndian);

        // Read the data
        const qint32 size = m_Container.size();

        while(!in.atEnd()) {
            T_History tmp;
            tmp.read(in);

            const qint32 id = tmp.getParentId();

            if(id < 0 || id >= size)
                continue;
            else {
                m_Container[id].addHistory(tmp);
                ++m_Count;
            }
        }

        file.close();
        return true;
    }

    // --- Write data --- //
    bool write(ProgressDialog *progress, const QString &path, const QString &fileName, const bool &domestic = true)
    {
        progress->increment(fileName);

        // Open the file
        QFile file(QString("%1/%2").arg(path).arg(fileName));
        if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
            return false;

        // Data stream
        QDataStream out(&file);
        out.setByteOrder(QDataStream::LittleEndian);

        // Reset the counter
        m_Count = 0;

        // Write the data
        const qint32 size = m_Container.size();
        for(qint32 i = 0; i < size; ++i)
            m_Count += m_Container[i].writeHistory(out, domestic);

        file.close();
        return true;
    }


    /* ================= */
    /*      Get Data     */
    /* ================= */

    // --- Get count/size --- //
    qint32 size()
    {
        return m_Count;
    }
};

#endif // HISTORY_MANAGER_H
