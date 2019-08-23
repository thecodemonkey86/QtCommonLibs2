#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T13:43:06
#
#-------------------------------------------------

QT       -= gui
CONFIG += c++14

TARGET = QtCommon2
TEMPLATE = lib

DEFINES += QTCOMMON2_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
SOURCES += \
    util/string/stringutil.cpp \
    exception/qtexception.cpp \
    util/cryptography/cryptutil.cpp \
    log/log.cpp \
    exception/cancelexception.cpp \
    util/string/dateutil.cpp \
    util/file/fileutil.cpp

HEADERS += \
    qtcommon2_global.h \
    util/collection/orderedset.h \
    core/cast.h \
    util/math/mathutil.h \
    util/string/stringutil.h \
    exception/qtexception.h \
    util/cryptography/cryptutil.h \
    log/log.h \
    exception/cancelexception.h \
    util/string/dateutil.h \
    util/file/fileutil.h

osx {
    QMAKE_LFLAGS_SONAME = -Wl,-install_name,@executable_path/../Frameworks/

}
