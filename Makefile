#############################################################################
# Makefile for building: bin/stokroom
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Jul 20 23:41:43 2012
# Project:  stokroom.pro
# Template: app
# Command: /home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/qmake -spec ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -I. -I../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/include/QtCore -I../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/include/QtGui -I../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/include -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib -lQtGui -L/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/qmake
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
		src/login.cpp build/moc_mainwindowimpl.cpp \
		build/moc_kernel.cpp \
		build/moc_settings.cpp \
		build/moc_login.cpp
OBJECTS       = build/mainwindowimpl.o \
		build/main.o \
		build/kernel.o \
		build/settings.o \
		build/login.o \
		build/moc_mainwindowimpl.o \
		build/moc_kernel.o \
		build/moc_settings.o \
		build/moc_login.o
DIST          = ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
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

$(TARGET): build/ui_mainwindow.h build/ui_login.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: stokroom.pro  ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++/qmake.conf ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl
	$(QMAKE) -spec ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../../develop/qt_sdk/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile stokroom.pro

dist: 
	@$(CHK_DIR_EXISTS) build/stokroom1.0.0 || $(MKDIR) build/stokroom1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/stokroom1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.h src/kernel.h src/settings.h src/login.h build/stokroom1.0.0/ && $(COPY_FILE) --parents src/mainwindowimpl.cpp src/main.cpp src/kernel.cpp src/settings.cpp src/login.cpp build/stokroom1.0.0/ && $(COPY_FILE) --parents ui/mainwindow.ui ui/login.ui build/stokroom1.0.0/ && (cd `dirname build/stokroom1.0.0` && $(TAR) stokroom1.0.0.tar stokroom1.0.0 && $(COMPRESS) stokroom1.0.0.tar) && $(MOVE) `dirname build/stokroom1.0.0`/stokroom1.0.0.tar.gz . && $(DEL_FILE) -r build/stokroom1.0.0


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

compiler_moc_header_make_all: build/moc_mainwindowimpl.cpp build/moc_kernel.cpp build/moc_settings.cpp build/moc_login.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_mainwindowimpl.cpp build/moc_kernel.cpp build/moc_settings.cpp build/moc_login.cpp
build/moc_mainwindowimpl.cpp: build/ui_mainwindow.h \
		src/mainwindowimpl.h
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/mainwindowimpl.h -o build/moc_mainwindowimpl.cpp

build/moc_kernel.cpp: src/kernel.h
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/kernel.h -o build/moc_kernel.cpp

build/moc_settings.cpp: src/login.h \
		build/ui_login.h \
		src/settings.h
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/settings.h -o build/moc_settings.cpp

build/moc_login.cpp: build/ui_login.h \
		src/login.h
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) src/login.h -o build/moc_login.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: build/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) build/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_mainwindow.h build/ui_login.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_mainwindow.h build/ui_login.h
build/ui_mainwindow.h: ui/mainwindow.ui
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic ui/mainwindow.ui -o build/ui_mainwindow.h

build/ui_login.h: ui/login.ui
	/home/user/develop/qt_sdk/Desktop/Qt/4.8.1/gcc/bin/uic ui/login.ui -o build/ui_login.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/mainwindowimpl.o: src/mainwindowimpl.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/mainwindowimpl.o src/mainwindowimpl.cpp

build/main.o: src/main.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h \
		src/settings.h \
		src/login.h \
		build/ui_login.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/kernel.o: src/kernel.cpp src/kernel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/kernel.o src/kernel.cpp

build/settings.o: src/settings.cpp src/settings.h \
		src/login.h \
		build/ui_login.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/settings.o src/settings.cpp

build/login.o: src/login.cpp src/login.h \
		build/ui_login.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/login.o src/login.cpp

build/moc_mainwindowimpl.o: build/moc_mainwindowimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_mainwindowimpl.o build/moc_mainwindowimpl.cpp

build/moc_kernel.o: build/moc_kernel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_kernel.o build/moc_kernel.cpp

build/moc_settings.o: build/moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_settings.o build/moc_settings.cpp

build/moc_login.o: build/moc_login.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_login.o build/moc_login.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

