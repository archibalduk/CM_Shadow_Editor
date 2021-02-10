#include "screen_widget.h"

/* ====================================== */
/*      Editor Screen/Display Widget      */
/* ====================================== */

// --- Default constructor --- //
ScreenWidget::ScreenWidget(QWidget *parent) :
    QWidget(parent)
{
    // Layout
    l = new QGridLayout(this);
    l->setAlignment(Qt::AlignTop);
    l->setSpacing(10);
}

// --- Set layout (should be called once all items have been added to the layout --- //
void ScreenWidget::applyLayout()
{
    this->setLayout(l);
}
