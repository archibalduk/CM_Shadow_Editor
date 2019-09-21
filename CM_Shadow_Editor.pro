#-------------------------------------------------
#
# Project created by QtCreator 2019-01-14T20:43:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CM_Shadow_Editor
TEMPLATE = app

# Application version
VERSION = 0.1.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# Resources
RC_FILE = CM_Shadow_Editor.rc

SOURCES += \
    data_types/attribute.cpp \
    db_containers/club_comp_data.cpp \
    db_containers/club_data.cpp \
    db_containers/colour_data.cpp \
    db_containers/official_data.cpp \
    db_containers/staff_comp_data.cpp \
    db_schema/colour.cpp \
    db_schema/official.cpp \
    db_schema/staff_comp.cpp \
    db_schema/staff_comp_history.cpp \
    db_schema/staff_preferences.cpp \
    editor/editor_city.cpp \
        main.cpp \
        mainwindow.cpp \
    db_modules/database.cpp \
    db_schema/staff.cpp \
    db_containers/staff_data.cpp \
    data_types/date.cpp \
    db_containers/index_data.cpp \
    db_schema/index.cpp \
    data_types/string.cpp \
    db_modules/version.cpp \
    model/club_comp_model.cpp \
    model/club_model.cpp \
    model/colour_model.cpp \
    model/official_model.cpp \
    model/staff_comp_model.cpp \
    pointer/ptr_nation.cpp \
    ui/main_ui.cpp \
    ui/action_wrapper.cpp \
    editor/editor_staff.cpp \
    model/model_base_class_wrapper.cpp \
    ui/progress_dialog.cpp \
    db_schema/name.cpp \
    db_containers/name_data.cpp \
    db_containers/city_data.cpp \
    db_containers/continent_data.cpp \
    db_containers/nation_data.cpp \
    db_containers/stadium_data.cpp \
    db_schema/city.cpp \
    db_schema/continent.cpp \
    db_schema/nation.cpp \
    db_schema/stadium.cpp \
    data_types/bool.cpp \
    data_types/char.cpp \
    data_types/double.cpp \
    data_types/int.cpp \
    data_types/short.cpp \
    data_types/u_char.cpp \
    model/city_model.cpp \
    model/common_name_model.cpp \
    model/continent_model.cpp \
    model/first_name_model.cpp \
    model/index_model.cpp \
    model/nation_model.cpp \
    model/second_name_model.cpp \
    model/stadium_model.cpp \
    model/staff_model.cpp \
    model/name_model.cpp \
    data_types/primary_key.cpp \
    db_schema/schema_base_class.cpp \
    db_schema/club_comp_history.cpp \
    db_schema/club_comp.cpp \
    db_schema/staff_history.cpp \
    db_schema/club.cpp \
    editor_ui/widgets/group_widget.cpp \
    editor_ui/widgets/screen_widget.cpp \
    editor_ui/outputs/label.cpp \
    editor_ui/inputs/line_edit.cpp \
    editor_ui/inputs/input_base_class.cpp \
    pointer/pointer.cpp \
    pointer/ptr_first_name.cpp \
    pointer/ptr_common_name.cpp \
    pointer/ptr_second_name.cpp \
    shadow/shadow_manager.cpp \
    shadow/shadow_group.cpp \
    shadow/shadow_edit_item.cpp \
    shadow/model/shadow_group_model.cpp \
    editor/editor.cpp \
    editor/shadow_editor.cpp \
    editor_ui/editor_ui.cpp \
    editor_ui/widgets/table_widget.cpp \
    shadow/model/shadow_edit_item_model.cpp \
    editor_ui/inputs/date_edit.cpp \
    editor_ui/inputs/pointer_edit.cpp \
    editor_ui/inputs/pointer_combo_edit.cpp

HEADERS += \
    data_types/attribute.h \
    db_containers/club_comp_data.h \
    db_containers/club_data.h \
    db_containers/colour_data.h \
    db_containers/official_data.h \
    db_containers/staff_comp_data.h \
    db_schema/colour.h \
    db_schema/official.h \
    db_schema/staff_comp.h \
    db_schema/staff_comp_history.h \
    db_schema/staff_preferences.h \
    editor/editor_city.h \
        mainwindow.h \
    db_modules/database.h \
    db_schema/staff.h \
    db_containers/staff_data.h \
    data_types/date.h \
    db_containers/index_data.h \
    db_schema/index.h \
    data_types/string.h \
    db_modules/version.h \
    model/club_comp_model.h \
    model/club_model.h \
    model/colour_model.h \
    model/official_model.h \
    model/staff_comp_model.h \
    pointer/ptr_nation.h \
    ui/main_ui.h \
    ui/action_wrapper.h \
    editor/editor_staff.h \
    model/model.h \
    model/model_base_class_wrapper.h \
    ui/progress_dialog.h \
    db_schema/name.h \
    db_containers/database_container.h \
    db_containers/name_data.h \
    db_containers/city_data.h \
    db_containers/continent_data.h \
    db_containers/nation_data.h \
    db_containers/stadium_data.h \
    db_schema/city.h \
    db_schema/continent.h \
    db_schema/nation.h \
    db_schema/stadium.h \
    data_types/bool.h \
    data_types/char.h \
    data_types/double.h \
    data_types/int.h \
    data_types/short.h \
    data_types/u_char.h \
    model/city_model.h \
    model/common_name_model.h \
    model/continent_model.h \
    model/first_name_model.h \
    model/index_model.h \
    model/name_model.h \
    model/nation_model.h \
    model/second_name_model.h \
    model/stadium_model.h \
    model/staff_model.h \
    data_types/primary_key.h \
    db_schema/schema_base_class.h \
    db_schema/club_comp_history.h \
    db_schema/club_comp.h \
    db_schema/staff_history.h \
    db_schema/club.h \
    editor_ui/widgets/group_widget.h \
    editor_ui/widgets/screen_widget.h \
    editor_ui/outputs/label.h \
    editor_ui/inputs/line_edit.h \
    editor_ui/inputs/input_base_class.h \
    editor_ui/common_ui.h \
    pointer/pointer.h \
    pointer/ptr_first_name.h \
    pointer/ptr_common_name.h \
    pointer/ptr_second_name.h \
    shadow/shadow_manager.h \
    shadow/shadow_group.h \
    shadow/shadow_edit_item.h \
    shadow/model/shadow_group_model.h \
    shadow/shadow_common.h \
    editor/editor.h \
    editor/shadow_editor.h \
    editor_ui/editor_ui.h \
    editor_ui/widgets/table_widget.h \
    shadow/model/shadow_edit_item_model.h \
    editor_ui/inputs/date_edit.h \
    editor_ui/inputs/pointer_edit.h \
    editor_ui/inputs/pointer_combo_edit.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
