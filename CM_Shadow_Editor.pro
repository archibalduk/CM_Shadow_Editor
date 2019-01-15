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
        main.cpp \
        mainwindow.cpp \
    db_modules/database.cpp \
    db_schema/staff.cpp \
    db_containers/staff_data.cpp \
    data_types/date.cpp \
    db_containers/index_data.cpp \
    db_schema/index.cpp \
    data_types/string.cpp \
    db_modules/version.cpp

HEADERS += \
        mainwindow.h \
    db_modules/database.h \
    db_schema/staff.h \
    db_containers/staff_data.h \
    data_types/date.h \
    db_containers/index_data.h \
    db_schema/index.h \
    data_types/string.h \
    db_modules/version.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
