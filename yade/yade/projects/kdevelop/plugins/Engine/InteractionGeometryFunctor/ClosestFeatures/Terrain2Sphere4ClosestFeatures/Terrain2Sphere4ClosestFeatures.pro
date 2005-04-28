# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/Interaction/InteractionGeometryFunctor/ClosestFeatures/Terrain2Sphere4ClosestFeatures
# Target is a library:  

LIBS += -lTerrain \
        -lClosestFeatures \
        -lMath \
        -lInteraction \
        -lMultiMethods \
        -lSphere \
        -lDistances \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../../plugins/Geometry/GeometricalModel/Terrain/$(YADEDYNLIBPATH) \
               ../../../../../plugins/Interaction/InteractionGeometry/ClosestFeatures/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../../../yade/Interaction/Interaction/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/MultiMethods/$(YADEDYNLIBPATH) \
               ../../../../../plugins/Geometry/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/ComputationalGeometry/Distances/$(YADEDYNLIBPATH) \
               ../../../../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../../../../yade/Interaction/$(YADEDYNLIBPATH) \
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
HEADERS += Terrain2Sphere4ClosestFeatures.hpp 
SOURCES += Terrain2Sphere4ClosestFeatures.cpp 