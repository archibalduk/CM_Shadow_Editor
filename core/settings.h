#ifndef SETTINGS_H
#define SETTINGS_H

// Qt headers
#include <QMenu>

// Application headers
#include "setting_item.h"

// --- Application settings menu --- //
class Settings : public QMenu
{
public:
    // Default constructor
    Settings(QWidget *parent = nullptr);

    // Settings
    SettingItem *setting_DebugMode;
};

#endif // SETTINGS_H
