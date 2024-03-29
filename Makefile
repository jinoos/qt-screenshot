#############################################################################
# Makefile for building: screenshot
# Generated by qmake (2.01a) (Qt 4.8.6) on: Mon Aug 18 02:55:06 2014
# Project:  screenshot.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile screenshot.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DJSON_INTEGER_IS_LONG_LONG=1 -DLOG_FILELINE -D_ELPP_QT_LOGGING -D_ELPP_THREAD_SAFE -D_ELPP_DEBUG_ERRORS -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -Wall -g -std=c++11 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtWebKit -I/usr/include/qt4 -Ihiredis -Ijansson-2.6/src -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu ./hiredis/async.o ./hiredis/hiredis.o ./hiredis/net.o ./hiredis/sds.o ./jansson-2.6/src/.libs/libjansson.a ./procps-3.2.8/proc/readproc.o ./procps-3.2.8/proc/alloc.o ./procps-3.2.8/proc/pwcache.o -lQtWebKit -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
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

OBJECTS_DIR   = ./

####### Files

SOURCES       = capture.cpp \
		main.cpp \
		request.cpp \
		result.cpp \
		redis.cpp \
		common.cpp \
		json.cpp \
		webviewremoveque.cpp \
		webviewremover.cpp \
		logging.c \
		util.cpp moc_capture.cpp \
		moc_webviewremover.cpp
OBJECTS       = capture.o \
		main.o \
		request.o \
		result.o \
		redis.o \
		common.o \
		json.o \
		webviewremoveque.o \
		webviewremover.o \
		logging.o \
		util.o \
		moc_capture.o \
		moc_webviewremover.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		screenshot.pro
QMAKE_TARGET  = screenshot
DESTDIR       = 
TARGET        = screenshot

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: screenshot.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtWebKit.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile screenshot.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtWebKit.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile screenshot.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/screenshot1.0.0 || $(MKDIR) .tmp/screenshot1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/screenshot1.0.0/ && $(COPY_FILE) --parents capture.hh request.hh result.hh redis.hh common.hh json.hh webviewremoveque.hh webviewremover.hh logging.h util.hh version.h .tmp/screenshot1.0.0/ && $(COPY_FILE) --parents capture.cpp main.cpp request.cpp result.cpp redis.cpp common.cpp json.cpp webviewremoveque.cpp webviewremover.cpp logging.c util.cpp .tmp/screenshot1.0.0/ && (cd `dirname .tmp/screenshot1.0.0` && $(TAR) screenshot1.0.0.tar screenshot1.0.0 && $(COMPRESS) screenshot1.0.0.tar) && $(MOVE) `dirname .tmp/screenshot1.0.0`/screenshot1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/screenshot1.0.0


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

compiler_moc_header_make_all: moc_capture.cpp moc_webviewremover.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_capture.cpp moc_webviewremover.cpp
moc_capture.cpp: common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h \
		capture.hh
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) capture.hh -o moc_capture.cpp

moc_webviewremover.cpp: common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h \
		webviewremover.hh
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) webviewremover.hh -o moc_webviewremover.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

capture.o: capture.cpp capture.hh \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o capture.o capture.cpp

main.o: main.cpp common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

request.o: request.cpp request.hh \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o request.o request.cpp

result.o: result.cpp result.hh \
		request.hh \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o result.o result.cpp

redis.o: redis.cpp redis.hh \
		hiredis/hiredis.h \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o redis.o redis.cpp

common.o: common.cpp common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o common.o common.cpp

json.o: json.cpp json.hh \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		webviewremover.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o json.o json.cpp

webviewremoveque.o: webviewremoveque.cpp webviewremoveque.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o webviewremoveque.o webviewremoveque.cpp

webviewremover.o: webviewremover.cpp webviewremover.hh \
		common.hh \
		jansson-2.6/src/jansson.h \
		jansson-2.6/src/jansson_config.h \
		redis.hh \
		hiredis/hiredis.h \
		request.hh \
		result.hh \
		capture.hh \
		webviewremoveque.hh \
		easyloggingpp/src/easylogging++.h \
		util.hh \
		version.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o webviewremover.o webviewremover.cpp

logging.o: logging.c logging.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o logging.o logging.c

util.o: util.cpp util.hh \
		procps-3.2.8/proc/readproc.h \
		procps-3.2.8/proc/procps.h \
		procps-3.2.8/proc/pwcache.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o util.o util.cpp

moc_capture.o: moc_capture.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_capture.o moc_capture.cpp

moc_webviewremover.o: moc_webviewremover.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_webviewremover.o moc_webviewremover.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

