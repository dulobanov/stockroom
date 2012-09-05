#############################################################################
# Makefile for building: bin/stokroom
# Generated by qmake (2.01a) (Qt 4.8.1) on: Wed Sep 5 11:45:31 2012
# Project:  stokroom.pro
# Template: app
# Command: /home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/qmake -spec ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m32 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++-32 -I. -I../../qt_sdk/Desktop/Qt/4.8.1/gcc/include/QtCore -I../../qt_sdk/Desktop/Qt/4.8.1/gcc/include/QtGui -I../../qt_sdk/Desktop/Qt/4.8.1/gcc/include/QtWebKit -I../../qt_sdk/Desktop/Qt/4.8.1/gcc/include -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -m32 -Wl,-rpath,/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib -lQtWebKit -lQtGui -L/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/mainwindowimpl.cpp \
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
		test/test.cpp \
		log/log_impl.cpp \
		mainwin/tables/summarytable.cpp \
		additional/checker.cpp \
		mainwin/tables/activitytable.cpp build/moc_mainwindowimpl.cpp \
		build/moc_kernel.cpp \
		build/moc_settings.cpp \
		build/moc_login.cpp \
		build/moc_registration.cpp \
		build/moc_add_item.cpp \
		build/moc_load_item.cpp \
		build/moc_unload_item.cpp \
		build/moc_remove_item.cpp \
		build/moc_c_summary.cpp \
		build/moc_ma_log.cpp \
		build/moc_c_logact.cpp \
		build/moc_test.cpp \
		build/moc_log_impl.cpp \
		build/moc_summarytable.cpp \
		build/moc_checker.cpp \
		build/moc_activitytable.cpp
OBJECTS       = build/mainwindowimpl.o \
		build/main.o \
		build/kernel.o \
		build/settings.o \
		build/login.o \
		build/registration.o \
		build/add_item.o \
		build/load_item.o \
		build/unload_item.o \
		build/remove_item.o \
		build/c_summary.o \
		build/ma_log.o \
		build/c_logact.o \
		build/test.o \
		build/log_impl.o \
		build/summarytable.o \
		build/checker.o \
		build/activitytable.o \
		build/moc_mainwindowimpl.o \
		build/moc_kernel.o \
		build/moc_settings.o \
		build/moc_login.o \
		build/moc_registration.o \
		build/moc_add_item.o \
		build/moc_load_item.o \
		build/moc_unload_item.o \
		build/moc_remove_item.o \
		build/moc_c_summary.o \
		build/moc_ma_log.o \
		build/moc_c_logact.o \
		build/moc_test.o \
		build/moc_log_impl.o \
		build/moc_summarytable.o \
		build/moc_checker.o \
		build/moc_activitytable.o
DIST          = ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		stokroom.pro
QMAKE_TARGET  = stokroom
DESTDIR       = bin/
TARGET        = bin/stokroom

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_mainwindow.h build/ui_login.h build/ui_registration.h build/ui_add_item.h build/ui_load_item.h build/ui_unload_item.h build/ui_remove_item.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: stokroom.pro  ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++-32/qmake.conf ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtWebKit.prl \
		/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl
	$(QMAKE) -spec ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtWebKit.prl:
/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++-32 CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro

dist: 
	@$(CHK_DIR_EXISTS) build/stokroom1.0.0 || $(MKDIR) build/stokroom1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/stokroom1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.h src/kernel.h src/settings.h src/login.h src/registration.h dialogs/add_item/add_item.h dialogs/load_item/load_item.h dialogs/unload_item/unload_item.h dialogs/remove_item/remove_item.h kernel/c_summary.h kernel/ma_log.h kernel/c_logact.h test/test.h log/log_impl.h mainwin/tables/summarytable.h additional/checker.h mainwin/tables/activitytable.h build/stokroom1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.cpp src/main.cpp src/kernel.cpp src/settings.cpp src/login.cpp src/registration.cpp dialogs/add_item/add_item.cpp dialogs/load_item/load_item.cpp dialogs/unload_item/unload_item.cpp dialogs/remove_item/remove_item.cpp kernel/c_summary.cpp kernel/ma_log.cpp kernel/c_logact.cpp test/test.cpp log/log_impl.cpp mainwin/tables/summarytable.cpp additional/checker.cpp mainwin/tables/activitytable.cpp build/stokroom1.0.0/ && $(COPY_FILE) --parents ui/mainwindow.ui ui/login.ui ui/registration.ui dialogs/add_item/add_item.ui dialogs/load_item/load_item.ui dialogs/unload_item/unload_item.ui dialogs/remove_item/remove_item.ui build/stokroom1.0.0/ && (cd `dirname build/stokroom1.0.0` && $(TAR) stokroom1.0.0.tar stokroom1.0.0 && $(COMPRESS) stokroom1.0.0.tar) && $(MOVE) `dirname build/stokroom1.0.0`/stokroom1.0.0.tar.gz . && $(DEL_FILE) -r build/stokroom1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_mainwindowimpl.cpp build/moc_kernel.cpp build/moc_settings.cpp build/moc_login.cpp build/moc_registration.cpp build/moc_add_item.cpp build/moc_load_item.cpp build/moc_unload_item.cpp build/moc_remove_item.cpp build/moc_c_summary.cpp build/moc_ma_log.cpp build/moc_c_logact.cpp build/moc_test.cpp build/moc_log_impl.cpp build/moc_summarytable.cpp build/moc_checker.cpp build/moc_activitytable.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_mainwindowimpl.cpp build/moc_kernel.cpp build/moc_settings.cpp build/moc_login.cpp build/moc_registration.cpp build/moc_add_item.cpp build/moc_load_item.cpp build/moc_unload_item.cpp build/moc_remove_item.cpp build/moc_c_summary.cpp build/moc_ma_log.cpp build/moc_c_logact.cpp build/moc_test.cpp build/moc_log_impl.cpp build/moc_summarytable.cpp build/moc_checker.cpp build/moc_activitytable.cpp
build/moc_mainwindowimpl.cpp: build/ui_mainwindow.h \
		mainwin/tables/activitytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		mainwin/tables/summarytable.h \
		src/settings.h \
		src/login.h \
		build/ui_login.h \
		src/registration.h \
		build/ui_registration.h \
		test/test.h \
		log/log_impl.h \
		dialogs/add_item/add_item.h \
		additional/checker.h \
		dialogs/load_item/load_item.h \
		src/mainwindowimpl.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/mainwindowimpl.h -o build/moc_mainwindowimpl.cpp

build/moc_kernel.cpp: kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		src/kernel.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/kernel.h -o build/moc_kernel.cpp

build/moc_settings.cpp: src/login.h \
		build/ui_login.h \
		src/registration.h \
		build/ui_registration.h \
		src/settings.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/settings.h -o build/moc_settings.cpp

build/moc_login.cpp: build/ui_login.h \
		src/login.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/login.h -o build/moc_login.cpp

build/moc_registration.cpp: build/ui_registration.h \
		src/registration.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/registration.h -o build/moc_registration.cpp

build/moc_add_item.cpp: additional/checker.h \
		dialogs/add_item/add_item.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) dialogs/add_item/add_item.h -o build/moc_add_item.cpp

build/moc_load_item.cpp: src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		additional/checker.h \
		dialogs/load_item/load_item.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) dialogs/load_item/load_item.h -o build/moc_load_item.cpp

build/moc_unload_item.cpp: dialogs/unload_item/unload_item.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) dialogs/unload_item/unload_item.h -o build/moc_unload_item.cpp

build/moc_remove_item.cpp: dialogs/remove_item/remove_item.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) dialogs/remove_item/remove_item.h -o build/moc_remove_item.cpp

build/moc_c_summary.cpp: kernel/c_logact.h \
		kernel/ma_log.h \
		kernel/c_summary.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) kernel/c_summary.h -o build/moc_c_summary.cpp

build/moc_ma_log.cpp: kernel/ma_log.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) kernel/ma_log.h -o build/moc_ma_log.cpp

build/moc_c_logact.cpp: kernel/ma_log.h \
		kernel/c_logact.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) kernel/c_logact.h -o build/moc_c_logact.cpp

build/moc_test.cpp: kernel/ma_log.h \
		log/log_impl.h \
		test/test.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) test/test.h -o build/moc_test.cpp

build/moc_log_impl.cpp: log/log_impl.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) log/log_impl.h -o build/moc_log_impl.cpp

build/moc_summarytable.cpp: src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		mainwin/tables/summarytable.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) mainwin/tables/summarytable.h -o build/moc_summarytable.cpp

build/moc_checker.cpp: additional/checker.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) additional/checker.h -o build/moc_checker.cpp

build/moc_activitytable.cpp: src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		mainwin/tables/activitytable.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) mainwin/tables/activitytable.h -o build/moc_activitytable.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: build/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_mainwindow.h build/ui_login.h build/ui_registration.h build/ui_add_item.h build/ui_load_item.h build/ui_unload_item.h build/ui_remove_item.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_mainwindow.h build/ui_login.h build/ui_registration.h build/ui_add_item.h build/ui_load_item.h build/ui_unload_item.h build/ui_remove_item.h
build/ui_mainwindow.h: ui/mainwindow.ui \
		mainwin/tables/summarytable.h \
		mainwin/tables/activitytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic ui/mainwindow.ui -o build/ui_mainwindow.h

build/ui_login.h: ui/login.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic ui/login.ui -o build/ui_login.h

build/ui_registration.h: ui/registration.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic ui/registration.ui -o build/ui_registration.h

build/ui_add_item.h: dialogs/add_item/add_item.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic dialogs/add_item/add_item.ui -o build/ui_add_item.h

build/ui_load_item.h: dialogs/load_item/load_item.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic dialogs/load_item/load_item.ui -o build/ui_load_item.h

build/ui_unload_item.h: dialogs/unload_item/unload_item.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic dialogs/unload_item/unload_item.ui -o build/ui_unload_item.h

build/ui_remove_item.h: dialogs/remove_item/remove_item.ui
	/home/den/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic dialogs/remove_item/remove_item.ui -o build/ui_remove_item.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/mainwindowimpl.o: src/mainwindowimpl.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h \
		mainwin/tables/activitytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		mainwin/tables/summarytable.h \
		src/settings.h \
		src/login.h \
		build/ui_login.h \
		src/registration.h \
		build/ui_registration.h \
		test/test.h \
		log/log_impl.h \
		dialogs/add_item/add_item.h \
		additional/checker.h \
		dialogs/load_item/load_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/mainwindowimpl.o src/mainwindowimpl.cpp

build/main.o: src/main.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h \
		mainwin/tables/activitytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		mainwin/tables/summarytable.h \
		src/settings.h \
		src/login.h \
		build/ui_login.h \
		src/registration.h \
		build/ui_registration.h \
		test/test.h \
		log/log_impl.h \
		dialogs/add_item/add_item.h \
		additional/checker.h \
		dialogs/load_item/load_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/kernel.o: src/kernel.cpp src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/kernel.o src/kernel.cpp

build/settings.o: src/settings.cpp src/settings.h \
		src/login.h \
		build/ui_login.h \
		src/registration.h \
		build/ui_registration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/settings.o src/settings.cpp

build/login.o: src/login.cpp src/login.h \
		build/ui_login.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/login.o src/login.cpp

build/registration.o: src/registration.cpp src/registration.h \
		build/ui_registration.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/registration.o src/registration.cpp

build/add_item.o: dialogs/add_item/add_item.cpp dialogs/add_item/add_item.h \
		additional/checker.h \
		build/ui_add_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/add_item.o dialogs/add_item/add_item.cpp

build/load_item.o: dialogs/load_item/load_item.cpp dialogs/load_item/load_item.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h \
		additional/checker.h \
		build/ui_load_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/load_item.o dialogs/load_item/load_item.cpp

build/unload_item.o: dialogs/unload_item/unload_item.cpp dialogs/unload_item/unload_item.h \
		build/ui_unload_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/unload_item.o dialogs/unload_item/unload_item.cpp

build/remove_item.o: dialogs/remove_item/remove_item.cpp dialogs/remove_item/remove_item.h \
		build/ui_remove_item.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/remove_item.o dialogs/remove_item/remove_item.cpp

build/c_summary.o: kernel/c_summary.cpp kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/c_summary.o kernel/c_summary.cpp

build/ma_log.o: kernel/ma_log.cpp kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/ma_log.o kernel/ma_log.cpp

build/c_logact.o: kernel/c_logact.cpp kernel/c_logact.h \
		kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/c_logact.o kernel/c_logact.cpp

build/test.o: test/test.cpp test/test.h \
		kernel/ma_log.h \
		log/log_impl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/test.o test/test.cpp

build/log_impl.o: log/log_impl.cpp log/log_impl.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/log_impl.o log/log_impl.cpp

build/summarytable.o: mainwin/tables/summarytable.cpp mainwin/tables/summarytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/summarytable.o mainwin/tables/summarytable.cpp

build/checker.o: additional/checker.cpp additional/checker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/checker.o additional/checker.cpp

build/activitytable.o: mainwin/tables/activitytable.cpp mainwin/tables/activitytable.h \
		src/kernel.h \
		kernel/c_summary.h \
		kernel/c_logact.h \
		kernel/ma_log.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/activitytable.o mainwin/tables/activitytable.cpp

build/moc_mainwindowimpl.o: build/moc_mainwindowimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_mainwindowimpl.o build/moc_mainwindowimpl.cpp

build/moc_kernel.o: build/moc_kernel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_kernel.o build/moc_kernel.cpp

build/moc_settings.o: build/moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_settings.o build/moc_settings.cpp

build/moc_login.o: build/moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_login.o build/moc_login.cpp

build/moc_registration.o: build/moc_registration.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_registration.o build/moc_registration.cpp

build/moc_add_item.o: build/moc_add_item.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_add_item.o build/moc_add_item.cpp

build/moc_load_item.o: build/moc_load_item.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_load_item.o build/moc_load_item.cpp

build/moc_unload_item.o: build/moc_unload_item.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_unload_item.o build/moc_unload_item.cpp

build/moc_remove_item.o: build/moc_remove_item.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_remove_item.o build/moc_remove_item.cpp

build/moc_c_summary.o: build/moc_c_summary.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_c_summary.o build/moc_c_summary.cpp

build/moc_ma_log.o: build/moc_ma_log.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_ma_log.o build/moc_ma_log.cpp

build/moc_c_logact.o: build/moc_c_logact.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_c_logact.o build/moc_c_logact.cpp

build/moc_test.o: build/moc_test.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_test.o build/moc_test.cpp

build/moc_log_impl.o: build/moc_log_impl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_log_impl.o build/moc_log_impl.cpp

build/moc_summarytable.o: build/moc_summarytable.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_summarytable.o build/moc_summarytable.cpp

build/moc_checker.o: build/moc_checker.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_checker.o build/moc_checker.cpp

build/moc_activitytable.o: build/moc_activitytable.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_activitytable.o build/moc_activitytable.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

