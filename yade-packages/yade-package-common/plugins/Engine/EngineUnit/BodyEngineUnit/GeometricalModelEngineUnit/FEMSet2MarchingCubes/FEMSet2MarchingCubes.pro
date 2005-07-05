# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./plugins/Engine/EngineUnit/BodyEngineUnit/GeometricalModelEngineUnit/FEMSet2MarchingCubes
# Target is a library:  

LIBS += -lGeometricalModelMetaEngine \
        -lParticleParameters \
        -lLatticeBeamParameters \
        -lLineSegment \
        -lLatticeSetParameters \
        -rdynamic 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../../../../plugins/Engine/MetaEngine/BodyMetaEngine/GeometricalModelMetaEngine/GeometricalModelMetaEngine/$(YADEDYNLIBPATH) \
               /usr/local/lib/yade/yade-libs/ \
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
HEADERS += FEMSet2MarchingCubes.hpp 
SOURCES += FEMSet2MarchingCubes.cpp 