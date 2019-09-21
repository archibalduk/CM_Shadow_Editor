#ifndef SCREEN_WIDGET_H
#define SCREEN_WIDGET_H

// Qt headers
#include <QGridLayout>
#include <QWidget>

// --- Editor screen/page widget --- //
class ScreenWidget : public QWidget
{
public:
    // Constructor
    ScreenWidget(QWidget *parent);
    ~ScreenWidget() {}

    // Layout
    QGridLayout *l;
    void applyLayout();
};

#endif // SCREEN_WIDGET_H
