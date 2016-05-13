#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T11:44:56
#
#-------------------------------------------------

QT       += core gui\
           multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindow2.cpp \
    rank.cpp \
    option.cpp \
    score.cpp \
    diff.cpp \
    hit.cpp \
    inrtroduction.cpp \
    music.cpp

HEADERS  += mainwindow.h \
    mainwindow2.h \
    rank.h \
    option.h \
    score.h \
    diff.h \
    hit.h \
    inrtroduction.h \
    music.h

FORMS    += mainwindow.ui \
    mainwindow2.ui \
    rank.ui \
    option.ui \
    score.ui \
    diff.ui \
    inrtroduction.ui \
    music.ui

RESOURCES += \
    res.qrc \
    sound.qrc

DISTFILES +=
