# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./DataClass/InteractionGeometry/SpheresContactGeometry
# Target is a library:  

HEADERS += SpheresContactGeometry.hpp 
SOURCES += SpheresContactGeometry.cpp 
LIBS += -lyade-lib-serialization \
        -lyade-lib-wm3-math \
        -rdynamic 
QMAKE_LIBDIR = /usr/local/lib/yade/yade-libs/ 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = ../../../../../bin 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
INCLUDEPATH += /usr/local/include
