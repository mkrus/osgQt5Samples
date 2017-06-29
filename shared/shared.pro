CONFIG += c++11

DL=
debug {
    DL=d
}

INCLUDEPATH += /Users/Shared/Local/include $$PWD
LIBS += -L/Users/Shared/Local/lib -losg$${DL} -losgDB$${DL} -losgGA$${DL} -losgViewer$${DL} -lOpenThreads$${DL}
QMAKE_LFLAGS += '-Wl,-rpath,\'/Users/Shared/Local/lib\''
QMAKE_CXXFLAGS += -Wno-overloaded-virtual

TARGET=osgRenderer
TEMPLATE=lib
CONFIG+=static

SOURCES += \
    $$PWD/osgbaserenderer.cpp

HEADERS += \
    $$PWD/osgbaserenderer.h
