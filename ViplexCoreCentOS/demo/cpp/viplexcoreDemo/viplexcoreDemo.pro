#-------------------------------------------------
#
# Project created by QtCreator 2020-10-30T14:02:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = viplexcoreDemo
TEMPLATE = app

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

SOURCES += \
        main.cpp \
    changepassword.cpp \
    demoChildGUI.cpp \
    demoGUI.cpp \
    logindialog.cpp

HEADERS += \
    changepassword.h \
    demoChildGUI.h \
    demoGUI.h \
    logindialog.h
FORMS += \
    changepassword.ui \
    demoChildGUI.ui \
    demoGUI.ui \
    logindialog.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

macx {
# mac only
DESTDIR = $$PWD/../../../bin
INCLUDEPATH += $$PWD/../../../include
LIBS += -L$$PWD/../../../bin -lviplexcore -lviplexcommon

QMAKE_RPATHDIR += ./
QMAKE_RPATHDIR += ./bin/
}
unix:!macx{
# linux only
DESTDIR = $$PWD/../../../bin
INCLUDEPATH += $$PWD/../../../include
LIBS += -L$$PWD/../../../bin -lviplexcore -lviplexcommon

QMAKE_RPATHDIR += ./
QMAKE_RPATHDIR += ./lib/
QMAKE_LFLAGS += -Wl,-z,origin \'-Wl,-rpath, $${QMAKE_RPATHDIR}\'
}
win32 {
# windows only
DESTDIR = $$PWD/../../../bin
INCLUDEPATH += $$PWD/../../../include
LIBS += -L$$PWD/../../../lib -lviplexcore -lviplexcommon
}

SUBDIRS += \
    viplexcoreDemo.pro
