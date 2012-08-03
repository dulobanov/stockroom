QT = gui core webkit
CONFIG += qt warn_on console debug
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/mainwindow.ui ui/login.ui ui/registration.ui \
    dialogs/add_item/add_item.ui \
    dialogs/load_item/load_item.ui \
    dialogs/unload_item/unload_item.ui \
    dialogs/remove_item/remove_item.ui
HEADERS = src/mainwindowimpl.h \
 src/kernel.h \
 src/settings.h \
 src/login.h \
 src/registration.h \
    dialogs/add_item/add_item.h \
    dialogs/load_item/load_item.h \
    dialogs/unload_item/unload_item.h \
    dialogs/remove_item/remove_item.h \
    kernel/c_summary.h \
    kernel/ma_log.h \
    kernel/c_logact.h \
    test/test.h
SOURCES = src/mainwindowimpl.cpp \
 src/main.cpp \
 src/kernel.cpp \
 src/settings.cpp \
 src/login.cpp \
 src/registration.cpp \
    dialogs/add_item/add_item.cpp \
    dialogs/load_item/load_item.cpp \
    dialogs/unload_item/unload_item.cpp \
    dialogs/remove_item/remove_item.cpp \
    kernel/c_summary.cpp \
    kernel/ma_log.cpp \
    kernel/c_logact.cpp \
    test/test.cpp
TEMPLATE = app
