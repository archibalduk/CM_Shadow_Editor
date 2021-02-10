#ifndef SETTING_ITEM_H
#define SETTING_ITEM_H

// Qt headers
#include <QAction>
#include <QString>

// --- A setting item linking a QAction to a QSetting --- //
class SettingItem : public QAction
{
private:
    const QString m_Key;

public:
    // Constructor
    SettingItem(const QString &key, const bool &defaultValue = false);

private slots:
    void onToggle(const bool &checked);
};

#endif // SETTING_ITEM_H
