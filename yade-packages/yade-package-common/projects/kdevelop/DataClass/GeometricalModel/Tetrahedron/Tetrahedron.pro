# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./DataClass/GeometricalModel/Tetrahedron
# Target is a library:  

HEADERS += Tetrahedron.hpp 
SOURCES += Tetrahedron.cpp 
LIBS += -lyade-lib-multimethods \
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