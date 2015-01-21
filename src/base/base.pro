#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T08:51:32
#
#-------------------------------------------------

QT       -= core gui

TARGET = base
TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++11

SOURCES +=

HEADERS += property.hpp \
    typedefs.hpp \
    ensure.hpp \
    memory_utils.hpp

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
