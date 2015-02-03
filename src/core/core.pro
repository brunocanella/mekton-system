#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T08:52:27
#
#-------------------------------------------------

#QT -= core gui

TARGET = core
TEMPLATE = lib

CONFIG -= qt
CONFIG += staticlib
CONFIG += c++11

INCLUDEPATH += ../base

LIBS += -lbase

SOURCES += \
    frames/bodyform.cpp \
    frames/frame.cpp \
    frames/mekton.cpp \
    interfaces/validatable.cpp \
    servos/extensions/foot.cpp \
    servos/extensions/hand.cpp \
    servos/arm.cpp \
    servos/armor.cpp \
    servos/head.cpp \
    servos/leg.cpp \
    servos/pod.cpp \
    servos/servo.cpp \
    servos/tail.cpp \
    servos/torso.cpp \
    servos/wing.cpp \
    subassemlies/subassemblies.cpp \
    subassemlies/subassembly.cpp \
    subassemlies/sensor.cpp \
    subassemlies/weapons/weapon.cpp \
    subassemlies/weapons/weapon_type.cpp \
    subassemlies/weapons/weapon_modifier.cpp \
    subassemlies/weapons/weapon_flag.cpp \
    subassemlies/weapons/beam.cpp

HEADERS += \
    frames/bodyform.hpp \
    frames/frame.hpp \
    frames/mekton.hpp \
    frames/model.hpp \
    interfaces/validatable.hpp \
    servos/extensions/foot.hpp \
    servos/extensions/hand.hpp \
    servos/arm.hpp \
    servos/armor.hpp \
    servos/head.hpp \
    servos/leg.hpp \
    servos/pod.hpp \
    servos/servo.hpp \
    servos/servos.hpp \
    servos/tail.hpp \
    servos/torso.hpp \
    servos/wing.hpp \
    subassemlies/subassemblies.hpp \
    subassemlies/subassembly.hpp \
    subassemlies/sensor.hpp \
    subassemlies/weapons/weapon.hpp \
    subassemlies/weapons/weapon_type.hpp \
    subassemlies/weapons/weapon_modifier.hpp \
    subassemlies/weapons/weapon_flag.hpp \
    subassemlies/weapons/beam.hpp

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
