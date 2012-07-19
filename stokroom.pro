QT = gui core
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui
HEADERS = src/mainwindowimpl.h src/kernel.h src/settings.h dialogs/login.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/kernel.cpp \
 src/settings.cpp \
 dialogs/login.cpp
TEMPLATE = app
