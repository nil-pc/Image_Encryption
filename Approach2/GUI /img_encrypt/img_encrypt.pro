#-------------------------------------------------
#
# Project created by QtCreator 2020-05-22T06:03:26
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG   +=c++11
CONFIG += link_pkgconfig
PKGCONFIG += opencv

TARGET = en_de_image
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imgenc.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
