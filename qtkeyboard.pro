######################################################################
# Automatically generated by qmake (2.01a) Fri Aug 17 09:12:02 2018
######################################################################

TEMPLATE = app
TARGET = qtkeyboard
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += Global.h KbInput.h KbNum.h Widget.h
FORMS += KbInput.ui KbNum.ui
SOURCES += Global.cpp KbInput.cpp KbNum.cpp main.cpp Widget.cpp
TARGET=./release/qtkeyboard
CONFIG+=Debug
OBJECTS_DIR = ./build/obj/
MOC_DIR = build/moc/
UI_DIR=build/ui
QT += gui core sql xml