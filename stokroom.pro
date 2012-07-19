QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/login.ui
HEADERS = src/mainwindowimpl.h src/kernel.h src/settings.h src/login.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/kernel.cpp \
 src/settings.cpp \
 src/login.cpp
TEMPLATE = app
