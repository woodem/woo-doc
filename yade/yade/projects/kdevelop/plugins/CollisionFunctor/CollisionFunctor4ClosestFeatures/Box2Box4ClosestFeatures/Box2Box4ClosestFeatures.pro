# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/CollisionFunctor/CollisionFunctor4ClosestFeatures/Box2Box4ClosestFeatures
# Target is a library:  

LIBS += -lBox \
        -lClosestFeatures \
        -lConstants \
        -lM3D \
        -lIntersections \
        -rdynamic 
INCLUDEPATH = ../../../../plugins/GeometricalModel/Box \
              ../../../../plugins/InteractionModel/ClosestFeatures \
              ../../../../yade \
              ../../../../toolboxes/ComputationalGeometry/Intersections \
              ../../../../toolboxes/Math/M3D \
              ../../../../toolboxes/Math/Constants 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../plugins/GeometricalModel/Box/$(YADEDYNLIBPATH) \
               ../../../../plugins/InteractionModel/ClosestFeatures/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/Math/Constants/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/Math/M3D/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/ComputationalGeometry/Intersections/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += release \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += Box2Box4ClosestFeatures.hpp 
SOURCES += Box2Box4ClosestFeatures.cpp 
