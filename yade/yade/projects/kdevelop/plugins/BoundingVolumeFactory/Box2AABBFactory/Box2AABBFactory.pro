# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/BoundingVolumeFactory/Box2AABBFactory
# Target is a library:  

LIBS += -lAABB \
        -lBox \
        -lConstants \
        -lM3D \
        -rdynamic 
INCLUDEPATH = ../../../plugins/GeometricalModel/Box \
              ../../../plugins/BoundingVolume/AABB \
              ../../../yade \
              ../../../toolboxes/Math/Constants \
              ../../../toolboxes/Math/M3D 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../plugins/BoundingVolume/AABB/$(YADEDYNLIBPATH) \
               ../../../plugins/GeometricalModel/Box/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Math/Constants/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Math/M3D/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += release \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += Box2AABBFactory.hpp 
SOURCES += Box2AABBFactory.cpp 
