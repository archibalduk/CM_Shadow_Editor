#include "settings.h"

/* ============================== */
/*      Application Settings      */
/* ============================== */

// --- Default constructor --- //
Settings::Settings(QWidget *parent) :
    QMenu(tr("Settings"), parent)
{
    // Debug mode
    setting_DebugMode = new SettingItem("debug_mode");
    setting_DebugMode->setText(tr("Debug mode"));
    this->addAction(setting_DebugMode);
}
