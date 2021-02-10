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
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

# QtXlsx
QXLSX_PARENTPATH=spreadsheet/xlsx/         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=spreadsheet/xlsx/header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=spreadsheet/xlsx/source/  # current QXlsx source path is ./source/
include(spreadsheet/xlsx/QXlsx.pri)

# Resources
RC_FILE = CM_Shadow_Editor.rc

SOURCES += \
    core/setting_item.cpp \
    core/settings.cpp \
    data_types/attribute.cpp \
    db_containers/club_comp_data.cpp \
    db_containers/club_comp_history_data.cpp \
    db_containers/club_data.cpp \
    db_containers/colour_data.cpp \
    db_containers/non_player_data.cpp \
    db_containers/official_data.cpp \
    db_containers/player_data.cpp \
    db_containers/staff_comp_data.cpp \
    db_containers/staff_comp_history_data.cpp \
    db_containers/staff_history_data.cpp \
    db_containers/staff_preferences_data.cpp \
    db_modules/database_values.cpp \
    db_schema/colour.cpp \
    db_schema/non_player.cpp \
    db_schema/official.cpp \
    db_schema/player.cpp \
    db_schema/staff_comp.cpp \
    db_schema/staff_comp_history.cpp \
    db_schema/staff_preferences.cpp \
    db_transfer/city_transfer.cpp \
    db_transfer/database_transfer.cpp \
    editor/editor_city.cpp \
    editor/editor_colour.cpp \
    editor_ui/inputs/pointer_line_edit.cpp \
    editor_ui/inputs/spin_box.cpp \
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
    model/value_model.cpp \
    pointer/ptr_club.cpp \
    pointer/ptr_nation.cpp \
    pointer/ptr_staff.cpp \
    spreadsheet/spreadsheet.cpp \
    spreadsheet/spreadsheet_file.cpp \
    spreadsheet/spreadsheet_file_csv.cpp \
    spreadsheet/spreadsheet_file_xlsx.cpp \
    spreadsheet/xlsx/source/xlsxabstractooxmlfile.cpp \
    spreadsheet/xlsx/source/xlsxabstractsheet.cpp \
    spreadsheet/xlsx/source/xlsxcell.cpp \
    spreadsheet/xlsx/source/xlsxcellformula.cpp \
    spreadsheet/xlsx/source/xlsxcelllocation.cpp \
    spreadsheet/xlsx/source/xlsxcellrange.cpp \
    spreadsheet/xlsx/source/xlsxcellreference.cpp \
    spreadsheet/xlsx/source/xlsxchart.cpp \
    spreadsheet/xlsx/source/xlsxchartsheet.cpp \
    spreadsheet/xlsx/source/xlsxcolor.cpp \
    spreadsheet/xlsx/source/xlsxconditionalformatting.cpp \
    spreadsheet/xlsx/source/xlsxcontenttypes.cpp \
    spreadsheet/xlsx/source/xlsxdatavalidation.cpp \
    spreadsheet/xlsx/source/xlsxdatetype.cpp \
    spreadsheet/xlsx/source/xlsxdocpropsapp.cpp \
    spreadsheet/xlsx/source/xlsxdocpropscore.cpp \
    spreadsheet/xlsx/source/xlsxdocument.cpp \
    spreadsheet/xlsx/source/xlsxdrawing.cpp \
    spreadsheet/xlsx/source/xlsxdrawinganchor.cpp \
    spreadsheet/xlsx/source/xlsxformat.cpp \
    spreadsheet/xlsx/source/xlsxmediafile.cpp \
    spreadsheet/xlsx/source/xlsxnumformatparser.cpp \
    spreadsheet/xlsx/source/xlsxrelationships.cpp \
    spreadsheet/xlsx/source/xlsxrichstring.cpp \
    spreadsheet/xlsx/source/xlsxsharedstrings.cpp \
    spreadsheet/xlsx/source/xlsxsimpleooxmlfile.cpp \
    spreadsheet/xlsx/source/xlsxstyles.cpp \
    spreadsheet/xlsx/source/xlsxtheme.cpp \
    spreadsheet/xlsx/source/xlsxutility.cpp \
    spreadsheet/xlsx/source/xlsxworkbook.cpp \
    spreadsheet/xlsx/source/xlsxworksheet.cpp \
    spreadsheet/xlsx/source/xlsxzipreader.cpp \
    spreadsheet/xlsx/source/xlsxzipwriter.cpp \
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
    editor_ui/inputs/pointer_combo_edit.cpp \
    value_containers/job_for_club_data.cpp \
    value_containers/playing_squad_data.cpp \
    value_containers/staff_classification_data.cpp \
    value_containers/value_container.cpp \
    value_pointer/ptr_job_for_club.cpp \
    value_pointer/ptr_playing_squad.cpp \
    value_pointer/ptr_staff_classification.cpp \
    value_pointer/value_pointer.cpp

HEADERS += \
    core/setting_item.h \
    core/settings.h \
    data_types/attribute.h \
    db_containers/club_comp_data.h \
    db_containers/club_comp_history_data.h \
    db_containers/club_data.h \
    db_containers/colour_data.h \
    db_containers/non_player_data.h \
    db_containers/official_data.h \
    db_containers/player_data.h \
    db_containers/simple_container.h \
    db_containers/staff_comp_data.h \
    db_containers/staff_comp_history_data.h \
    db_containers/staff_history_data.h \
    db_containers/staff_preferences_data.h \
    db_modules/database_values.h \
    db_modules/history_manager.h \
    db_schema/colour.h \
    db_schema/non_player.h \
    db_schema/official.h \
    db_schema/player.h \
    db_schema/staff_comp.h \
    db_schema/staff_comp_history.h \
    db_schema/staff_preferences.h \
    db_transfer/city_transfer.h \
    db_transfer/database_transfer.h \
    editor/editor_city.h \
    editor/editor_colour.h \
    editor_ui/inputs/pointer_line_edit.h \
    editor_ui/inputs/spin_box.h \
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
    model/value_model.h \
    pointer/ptr_club.h \
    pointer/ptr_nation.h \
    pointer/ptr_staff.h \
    spreadsheet/spreadsheet.h \
    spreadsheet/spreadsheet_file.h \
    spreadsheet/spreadsheet_file_csv.h \
    spreadsheet/spreadsheet_file_xlsx.h \
    spreadsheet/xlsx/header/xlsxabstractooxmlfile.h \
    spreadsheet/xlsx/header/xlsxabstractooxmlfile_p.h \
    spreadsheet/xlsx/header/xlsxabstractsheet.h \
    spreadsheet/xlsx/header/xlsxabstractsheet_p.h \
    spreadsheet/xlsx/header/xlsxcell.h \
    spreadsheet/xlsx/header/xlsxcell_p.h \
    spreadsheet/xlsx/header/xlsxcellformula.h \
    spreadsheet/xlsx/header/xlsxcellformula_p.h \
    spreadsheet/xlsx/header/xlsxcelllocation.h \
    spreadsheet/xlsx/header/xlsxcellrange.h \
    spreadsheet/xlsx/header/xlsxcellreference.h \
    spreadsheet/xlsx/header/xlsxchart.h \
    spreadsheet/xlsx/header/xlsxchart_p.h \
    spreadsheet/xlsx/header/xlsxchartsheet.h \
    spreadsheet/xlsx/header/xlsxchartsheet_p.h \
    spreadsheet/xlsx/header/xlsxcolor_p.h \
    spreadsheet/xlsx/header/xlsxconditionalformatting.h \
    spreadsheet/xlsx/header/xlsxconditionalformatting_p.h \
    spreadsheet/xlsx/header/xlsxcontenttypes_p.h \
    spreadsheet/xlsx/header/xlsxdatavalidation.h \
    spreadsheet/xlsx/header/xlsxdatavalidation_p.h \
    spreadsheet/xlsx/header/xlsxdatetype.h \
    spreadsheet/xlsx/header/xlsxdocpropsapp_p.h \
    spreadsheet/xlsx/header/xlsxdocpropscore_p.h \
    spreadsheet/xlsx/header/xlsxdocument.h \
    spreadsheet/xlsx/header/xlsxdocument_p.h \
    spreadsheet/xlsx/header/xlsxdrawing_p.h \
    spreadsheet/xlsx/header/xlsxdrawinganchor_p.h \
    spreadsheet/xlsx/header/xlsxformat.h \
    spreadsheet/xlsx/header/xlsxformat_p.h \
    spreadsheet/xlsx/header/xlsxglobal.h \
    spreadsheet/xlsx/header/xlsxmediafile_p.h \
    spreadsheet/xlsx/header/xlsxnumformatparser_p.h \
    spreadsheet/xlsx/header/xlsxrelationships_p.h \
    spreadsheet/xlsx/header/xlsxrichstring.h \
    spreadsheet/xlsx/header/xlsxrichstring_p.h \
    spreadsheet/xlsx/header/xlsxsharedstrings_p.h \
    spreadsheet/xlsx/header/xlsxsimpleooxmlfile_p.h \
    spreadsheet/xlsx/header/xlsxstyles_p.h \
    spreadsheet/xlsx/header/xlsxtheme_p.h \
    spreadsheet/xlsx/header/xlsxutility_p.h \
    spreadsheet/xlsx/header/xlsxworkbook.h \
    spreadsheet/xlsx/header/xlsxworkbook_p.h \
    spreadsheet/xlsx/header/xlsxworksheet.h \
    spreadsheet/xlsx/header/xlsxworksheet_p.h \
    spreadsheet/xlsx/header/xlsxzipreader_p.h \
    spreadsheet/xlsx/header/xlsxzipwriter_p.h \
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
    editor_ui/inputs/pointer_combo_edit.h \
    value_containers/job_for_club_data.h \
    value_containers/playing_squad_data.h \
    value_containers/staff_classification_data.h \
    value_containers/value_container.h \
    value_pointer/ptr_job_for_club.h \
    value_pointer/ptr_playing_squad.h \
    value_pointer/ptr_staff_classification.h \
    value_pointer/value_pointer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CM_Shadow_Editor.qrc

DISTFILES += \
    icons/application.ico \
    icons/cities.png \
    spreadsheet/xlsx/QXlsx.pri

SUBDIRS += \
    spreadsheet/xlsx/QXlsx.pro
