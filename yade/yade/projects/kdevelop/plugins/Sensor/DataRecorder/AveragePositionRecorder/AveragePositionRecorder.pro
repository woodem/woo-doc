# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/DataRecorder/AveragePositionRecorder
# Target is a library:  

LIBS += -lBody \
        -lRigidBodyParameters \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../yade/Body/$(YADEDYNLIBPATH) \
               ../../plugins/Body/RigidBody/$(YADEDYNLIBPATH) \
               ../../yade/Body/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += AveragePositionRecorder.hpp 
SOURCES += AveragePositionRecorder.cpp 