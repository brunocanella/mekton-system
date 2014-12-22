#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T08:52:27
#
#-------------------------------------------------

QT       -= core gui

TARGET = core
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    mecha_stats.cpp \
    mecha.cpp \
    servo.cpp \
    subassembly.cpp

HEADERS += \
    mecha_stats.hpp \
    mecha.hpp \
    servo.hpp \
    subassembly.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG(debug, debug|release) {
    BUILD_FOLDER = debug
} else {
    BUILD_FOLDER = release
}



DESTDIR = ../../bin/$${BUILD_FOLDER}
OBJECTS_DIR = ../../obj/$${BUILD_FOLDER}
