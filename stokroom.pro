QT = gui core webkit
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/login.ui ui/registration.ui
HEADERS = src/mainwindowimpl.h \
 src/kernel.h \
 src/settings.h \
 src/login.h \
 src/registration.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/kernel.cpp \
 src/settings.cpp \
 src/login.cpp \
 src/registration.cpp
TEMPLATE = app
