# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/InteractionModel/ClosestFeatures
# Target is a library:  

LIBS += -lM3D \
        -lConstants \
        -rdynamic 
INCLUDEPATH = ../../../yade \
              ../../../toolboxes/Math/Constants \
              ../../../toolboxes/Math/M3D 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../toolboxes/Math/M3D/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Math/Constants/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += release \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += ClosestFeatures.hpp 
SOURCES += ClosestFeatures.cpp 
