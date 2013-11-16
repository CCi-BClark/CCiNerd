#-------------------------------------------------
#
# Project created by QtCreator 2013-11-08T08:50:23
#
#-------------------------------------------------

SUBDIRS = src

include(src/src/xlsx/qtxlsx.pri)

TARGET = CCiData

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui

SOURCES += main.cpp\
        mainwindow.cpp \
    tabwidget.cpp \
    targetwidget.cpp \
    selectfield.cpp

HEADERS  += mainwindow.h \
    tabwidget.h \
    targetwidget.h \
    selectfield.h

FORMS    += mainwindow.ui \
    tabwidget.ui \
    targetwidget.ui \
    selectfield.ui

RESOURCES += \
    rc.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/src/src/xlsx/release/ -lQt0Xlsxd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/src/src/xlsx/debug/ -lQt0Xlsxd
else:unix: LIBS += -L$$OUT_PWD/src/src/xlsx/ -lQt0Xlsxd

INCLUDEPATH += $$PWD/src/src/xlsx
DEPENDPATH += $$PWD/src/src/xlsx
