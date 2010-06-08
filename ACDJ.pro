QT += phonon
TARGET = ACDJ
TEMPLATE = app

CONFIG += qt debug
DESTDIR = Debug
MOC_DIR = Debug
OBJECTS_DIR = Debug

SOURCES += main.cpp \
    songinfowidget.cpp \
    song.cpp \
    playlistmodel.cpp \
    mainwindow.cpp \
    mainwidget.cpp
HEADERS += songinfowidget.h \
    song.h \
    playlistmodel.h \
    mainwindow.h \
    mainwidget.h
FORMS += mainwindow.ui
