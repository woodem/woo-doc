# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/Interaction/InteractionGeometryFunctor/InteractionFunctor4SDECContactModel/Sphere2Sphere4SDECContactModel
# Target is a library:  

LIBS += -lSphere \
        -lSerialization \
        -lMath \
        -lGeometry \
        -lInteraction \
        -lMultiMethods \
        -lSDECContactGeometry \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../../plugins/Geometry/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../../../../yade/Interaction/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/MultiMethods/$(YADEDYNLIBPATH) \
               ../../../../../plugins/Interaction/InteractionGeometry/SDECContactGeometry/$(YADEDYNLIBPATH) \
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
HEADERS += Sphere2Sphere4SDECContactModel.hpp 
SOURCES += Sphere2Sphere4SDECContactModel.cpp 