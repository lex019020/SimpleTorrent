QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    torrent.cpp \
    torrentelement.cpp \
    torrentelementlist.cpp \
    torrentmanager.cpp

HEADERS += \
    downloader.h \
    mainwindow.h \
    settings.h \
    torrent.h \
    torrentelement.h \
    torrentelementlist.h \
    torrentmanager.h

FORMS += \
    mainwindow.ui \
    torrentelement.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Загрузки/libtorrent-rasterbar-2.0.2/bin/gcc-9/release/cxxstd-14-iso/debug-symbols-on/threading-multi/release/ -ltorrent-rasterbar
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Загрузки/libtorrent-rasterbar-2.0.2/bin/gcc-9/release/cxxstd-14-iso/debug-symbols-on/threading-multi/debug/ -ltorrent-rasterbar
#else:unix: LIBS += -L$$PWD/../Загрузки/libtorrent-rasterbar-2.0.2/bin/gcc-9/release/cxxstd-14-iso/debug-symbols-on/threading-multi/ -ltorrent-rasterbar

INCLUDEPATH += $$PWD/../Загрузки/libtorrent-rasterbar-2.0.2/include/libtorrent
#DEPENDPATH += $$PWD/../Загрузки/libtorrent-rasterbar-2.0.2/include/libtorrent

unix|win32: LIBS += -ltorrent.21
