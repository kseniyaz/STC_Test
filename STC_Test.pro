QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/choosefilewindow.cpp \
    src/main.cpp \
    src/widget.cpp

HEADERS += \
    src/choosefilewindow.h \
    src/widget.h

FORMS += \
    forms/choosefilewindow.ui \
    forms/widget.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
