# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/CollisionFunctor/CollisionFunctor4ClosestFeatures/Box2Box4ClosestFeatures
# Target is a library:  

LIBS += -lBox \
        -lClosestFeatures \
        -lIntersections \
        -lMath \
        -lGeometry \
        -lInteraction \
        -lMultiMethods \
        -rdynamic 
INCLUDEPATH = ../../../../plugins/GeometricalModel/Box \
              ../../../../plugins/InteractionModel/ClosestFeatures \
              ../../../../yade/yade \
              ../../../../yade/Interaction \
              ../../../../yade/Geometry \
              ../../../../yade/MultiMethods \
              ../../../../yade/Factory \
              ../../../../toolboxes/ComputationalGeometry/Intersections \
              ../../../../toolboxes/Libraries/Math \
              ../../../../toolboxes/Libraries/Serialization 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../plugins/GeometricalModel/Box/$(YADEDYNLIBPATH) \
               ../../../../plugins/InteractionModel/ClosestFeatures/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/ComputationalGeometry/Intersections/$(YADEDYNLIBPATH) \
               ../../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../../../yade/Interaction/$(YADEDYNLIBPATH) \
               ../../../../yade/MultiMethods/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += Box2Box4ClosestFeatures.hpp 
SOURCES += Box2Box4ClosestFeatures.cpp 