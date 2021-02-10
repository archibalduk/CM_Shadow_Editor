#ifndef GROUP_WIDGET_H
#define GROUP_WIDGET_H

// Qt headers
#include <QGroupBox>
#include <QString>
#include <QGridLayout>
#include <QVector>

// Application headers
#include "../inputs/input_base_class.h"

// --- Group/category of widgets (vertically aligned) --- //
class GroupWidget : public QGroupBox
{
private:
    // Row/col tracket
    qint32 m_Col;
    qint32 m_Row;
    const qint32 m_Limit;

    // Layout
    QGridLayout *m_Layout;

public:
    // Constructor
    GroupWidget(const QString &title, QWidget *parent, const qint32 &limit = 14);

    // Set data
    void add(QWidget *widget);

    // --- Add multiple widgets to the layout --- //
    template <typename T> void add(QVector<T*> &widgets, qint32 first = -1, qint32 last = -1)
    {
        // If no first or last value has been passed, use the beginning and/or end accordingly
        if(first < 0)
            first = 0;
        if(last < 0)
            last = widgets.size();

        // Sanity checking (ordering)
        if(last < first) {
            const qint32 tmpLast = first;
            first = last;
            last = tmpLast;
        }

        // Sanity checking (first element)
        if(first < 0)
            first = 0;

        // Sanity checking (last element)
        if(last >= widgets.size())
            last = widgets.size() - 1;

        for(qint32 i = first; i <= last; ++i)
            this->add(widgets[i]);
    }
};

#endif // GROUP_WIDGET_H
