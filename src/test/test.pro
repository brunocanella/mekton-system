TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    base/property_test.cpp \
    core/servo_test.cpp \
    core/mecha_test.cpp \
    globals.cpp

INCLUDEPATH += ../core
INCLUDEPATH += ../base

LIBS += -pthread
LIBS += -lgtest
LIBS += -lgtest_main

CONFIG(debug, debug|release) {
    BUILD_FOLDER = debug
} else {
    BUILD_FOLDER = release
}

LIBS += -L../../bin/$${BUILD_FOLDER} -lcore -lbase

DESTDIR = ../../bin/test/$${BUILD_FOLDER}
OBJECTS_DIR = ../../obj/test/$${BUILD_FOLDER}

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    globals.hpp

