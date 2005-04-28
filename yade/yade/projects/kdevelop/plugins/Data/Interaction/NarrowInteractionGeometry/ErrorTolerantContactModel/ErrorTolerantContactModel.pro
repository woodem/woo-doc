# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/Interaction/InteractionGeometry/ErrorTolerantContactModel
# Target is a library:  

LIBS += -lMath \
        -lSerialization \
        -lFactory \
        -lInteraction \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/Libraries/Factory/$(YADEDYNLIBPATH) \
               ../../../../yade/Interaction/$(YADEDYNLIBPATH) \
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
HEADERS += ErrorTolerantContactModel.hpp 
SOURCES += ErrorTolerantContactModel.cpp 