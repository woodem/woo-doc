# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/CollisionFunctor/CollisionFunctor4ClosestFeatures/AABox2Sphere4ClosestFeatures
# Target is a library:  

LIBS += -lBox \
        -lSphere \
        -lClosestFeatures \
        -lMath \
        -lGeometry \
        -lInteraction \
        -lMultiMethods \
        -rdynamic 
INCLUDEPATH = ../../../../plugins/GeometricalModel/Box \
              ../../../../plugins/GeometricalModel/Sphere \
              ../../../../plugins/InteractionModel/ClosestFeatures \
              ../../../../yade/yade \
              ../../../../yade/Interaction \
              ../../../../yade/Geometry \
              ../../../../yade/MultiMethods \
              ../../../../yade/Factory \
              ../../../../toolboxes/Libraries/Math \
              ../../../../toolboxes/Libraries/Serialization 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../plugins/GeometricalModel/Box/$(YADEDYNLIBPATH) \
               ../../../../plugins/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../../plugins/InteractionModel/ClosestFeatures/$(YADEDYNLIBPATH) \
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
HEADERS += AABox2Sphere4ClosestFeatures.hpp 
SOURCES += AABox2Sphere4ClosestFeatures.cpp 