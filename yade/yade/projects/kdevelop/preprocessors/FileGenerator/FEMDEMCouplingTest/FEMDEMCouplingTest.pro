# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./preprocessors/FileGenerator/FEMDEMCouplingTest
# Target is a library:  

LIBS += -lAABB \
        -lFEMSetParameters \
        -lActionParameterInitializer \
        -lActionParameterReset \
        -lInteractionDescriptionSet \
        -lFEMSetTextLoaderFunctor \
        -lFEMLaw \
        -lGravityCondition \
        -rdynamic 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../plugins/Body/BoundingVolume/AABB/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/BodyPhysicalParameters/FEMSetParameters/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterInitializer/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterReset/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/InteractionDescription/InteractionDescriptionSet/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/BodyPhysicalParametersFunctor/FEMSetTextLoaderFunctor/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ConstitutiveLaw/FEMLaw/$(YADEDYNLIBPATH) \
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
HEADERS += FEMDEMCouplingTest.hpp 
SOURCES += FEMDEMCouplingTest.cpp 