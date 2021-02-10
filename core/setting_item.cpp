#include "setting_item.h"

// Qt headers
#include <QSettings>

/* ====================== */
/*      Setting Item      */
/* ====================== */

// --- Default constructor --- //
SettingItem::SettingItem(const QString &key, const bool &defaultValue) :
    m_Key(key)
{
    this->setCheckable(true);
    QObject::connect(this, &QAction::toggled,
                     this, &SettingItem::onToggle);

    QSettings settings;
    const bool value = settings.value(key, defaultValue).toBool();
    this->setChecked(value);
}

/* =============== */
/*      Slots      */
/* =============== */

// --- QAction toggled --- //
void SettingItem::onToggle(const bool &checked)
{
    QSettings settings;
    settings.setValue(m_Key, checked);
}
