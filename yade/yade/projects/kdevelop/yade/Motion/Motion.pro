# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./yade/Engine
# Target is a library:  

HEADERS += ActionDispatcher.hpp \
           ActionFunctor.hpp \
           ActionContainer.hpp \
           Action.hpp \
           ConstitutiveLaw.hpp \
           KinematicMotion.hpp 
SOURCES += ActionDispatcher.cpp \
           ActionContainer.cpp \
           ConstitutiveLaw.cpp \
           KinematicMotion.cpp 
LIBS += -rdynamic
INCLUDEPATH = $(YADEINCLUDEPATH)
MOC_DIR = $(YADECOMPILATIONPATH)
UI_DIR = $(YADECOMPILATIONPATH)
OBJECTS_DIR = $(YADECOMPILATIONPATH)
QMAKE_LIBDIR = $(YADEDYNLIBPATH)
QMAKE_CXXFLAGS_RELEASE += -lpthread \
-pthread
QMAKE_CXXFLAGS_DEBUG += -lpthread \
-pthread
DESTDIR = $(YADEDYNLIBPATH)
CONFIG += debug \
warn_on \
dll
TEMPLATE = lib
