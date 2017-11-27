#-------------------------------------------------
#
# Project created by QtCreator 2017-11-21T11:59:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartBoardV3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    admin.cpp \
    teacher.cpp

HEADERS  += mainwindow.h \
    admin.h \
    teacher.h

FORMS    += mainwindow.ui \
    admin.ui \
    teacher.ui
