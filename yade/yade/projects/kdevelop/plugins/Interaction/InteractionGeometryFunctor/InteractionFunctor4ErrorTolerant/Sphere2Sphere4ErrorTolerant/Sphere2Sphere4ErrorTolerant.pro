# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/Interaction/InteractionGeometryFunctor/InteractionFunctor4ErrorTolerant/Sphere2Sphere4ErrorTolerant
# Target is a library:  

LIBS += -lSphere \
        -lBody \
        -lEngine \
        -lInteraction \
        -lGeometry \
        -lMultiMethods \
        -lFactory \
        -lMath \
        -lErrorTolerantContactModel \
        -lSerialization \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../../plugins/Geometry/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../../../yade/Body/$(YADEDYNLIBPATH) \
               ../../../../../yade/Engine/$(YADEDYNLIBPATH) \
               ../../../../../yade/Interaction/$(YADEDYNLIBPATH) \
               ../../../../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/MultiMethods/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Factory/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../../../plugins/Interaction/InteractionGeometry/ErrorTolerantContactModel/$(YADEDYNLIBPATH) \
               ../../../../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
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
HEADERS += Sphere2Sphere4ErrorTolerant.hpp 
SOURCES += Sphere2Sphere4ErrorTolerant.cpp 