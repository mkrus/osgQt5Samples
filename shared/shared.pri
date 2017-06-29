CONFIG += c++11

DL=
debug {
    DL=d
}

INCLUDEPATH += /Users/Shared/Local/include $$PWD
LIBS += -L/Users/Shared/Local/lib -losg$${DL} -losgDB$${DL} -losgGA$${DL} -losgViewer$${DL} -lOpenThreads$${DL}
LIBS += -L$$OUT_PWD/../shared -losgRenderer
QMAKE_LFLAGS += '-Wl,-rpath,\'/Users/Shared/Local/lib\''
QMAKE_CXXFLAGS += -Wno-overloaded-virtual
