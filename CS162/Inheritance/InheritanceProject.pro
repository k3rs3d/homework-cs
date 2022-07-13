TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Armor.cpp \
    Character.cpp \
    Weapon.cpp \
    RangedWeapon.cpp \
    Item.cpp \
    characterTester.cpp \
    itemHeirarchyTester.cpp
SOURCES +=
SOURCES +=

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

HEADERS += \
    Armor.h \
    Character.h \
    Weapon.h \
    RangedWeapon.h \
    Item.h \
    doctest.h

