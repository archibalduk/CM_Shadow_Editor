#ifndef EDITOR_UI_H
#define EDITOR_UI_H

// Qt headers
#include <QDataWidgetMapper>
#include <QLineEdit>
#include <QListView>
#include <QSortFilterProxyModel>
#include <QString>
#include <QTabWidget>
#include <QWidget>

// Application headers
#include "../ui/main_ui.h"
#include "outputs/label.h"

// Editor widgets
#include "widgets/group_widget.h"
#include "widgets/screen_widget.h"

// --- Editor user interface base class --- //
class EditorUi : public QWidget
{
public:
    // Constructor
    EditorUi(const QString &title, MainUi *parent, QSortFilterProxyModel*proxy, const qint32 &displayColumn = 0);

protected:
    // Mapper
    QDataWidgetMapper *m_Mapper;

    // Model
    QSortFilterProxyModel *m_Proxy;

    // Navigation
    QListView *m_NavigationList;
    QLineEdit *m_NavigationSearch;

    // Strings
    static const QString s_TextBasicData;

    // User interface (members)
    QWidget *m_HeadingArea;
    QTabWidget *m_EditorDisplay;

    // User interface (functions)
    void addScreen(QWidget *screen, const QString &title);
    void init();

    // --- Populate a QVector of input widgets --- //
    template<typename T> void initInputWidgets(QVector<T*> &container, const qint32 &count)
    {
        for(qint32 i = 0; i < count; ++i)
            container.push_back(new T(this));
    }

protected slots:    
    // Model
    void modelResetCommenced();
    void modelResetComplete();
    void onRowCountChange(const QModelIndex &parent, int first, int last);

    // Navigation
    void toFirst();
    void toLast();
    void toNewest();
    void toNext();
    void toPrevious();

    // Proxy <--> Mapper
    void onProxyChanged(const QModelIndex & index);

private:
    // Labels
    Label *m_LabelDisplayText;
    Label *m_LabelRecordId;

    // Model
    void setModel(QSortFilterProxyModel*proxy, const qint32 &displayColumn);

    // User interface
    void setHeadingArea();
    void setUserInterface();
};

#endif // EDITOR_UI_H
