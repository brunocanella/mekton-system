TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    servo_test.cpp \
    mecha_test.cpp

INCLUDEPATH += ../src/core

LIBS += -pthread
LIBS += -lgtest
LIBS += -lgtest_main

CONFIG(debug, debug|release) {
    BUILD_FOLDER = debug
} else {
    BUILD_FOLDER = release
}

LIBS += -L../$${BUILD_FOLDER} -lcore

DESTDIR = ./$${BUILD_FOLDER}
OBJECTS_DIR = ../../obj/test/$${BUILD_FOLDER}


include(deployment.pri)
qtcAddDeployment()

