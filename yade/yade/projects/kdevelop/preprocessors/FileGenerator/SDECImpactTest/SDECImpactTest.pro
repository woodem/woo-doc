# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./preprocessors/FileGenerator/SDECImpactTest
# Target is a library:  

LIBS += -lBox \
        -lSphere \
        -lAABB \
        -lSerialization \
        -lMath \
        -lMultiMethods \
        -lInteraction \
        -lAveragePositionRecorder \
        -lInteractionDescriptionSet \
        -lInteractionDescriptionSet2AABBFunctor \
        -lSDECLinkGeometry \
        -lPersistentSAPCollider \
        -lInteractionSphere \
        -lInteractionBox \
        -lVelocityRecorder \
        -lSAPCollider \
        -lEngine \
        -lBody \
        -lForceRecorder \
        -lCundallNonViscousMomentumDampingFunctor \
        -lCundallNonViscousForceDampingFunctor \
        -lActionParameterReset \
        -lActionParameterInitializer \
        -lGravityCondition \
        -lMacroMicroElasticRelationships \
        -lSDECTimeStepper \
        -lElasticContactLaw \
        -lForceRecorder \
        -rdynamic 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../plugins/Body/GeometricalModel/Box/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/BoundingVolume/AABB/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/MultiMethods/$(YADEDYNLIBPATH) \
               ../../../yade/Interaction/Interaction/$(YADEDYNLIBPATH) \
               ../../../plugins/DataRecorder/AveragePositionRecorder/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/InteractionDescription/InteractionDescriptionSet/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/BoundingVolumeFunctor/InteractionDescriptionSet2AABBFunctor/$(YADEDYNLIBPATH) \
               ../../../plugins/Interaction/InteractionGeometry/SDECLinkGeometry/$(YADEDYNLIBPATH) \
               ../../../plugins/Interaction/BroadInteractor/PersistentSAPCollider/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/InteractionDescription/InteractionSphere/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/InteractionDescription/InteractionBox/$(YADEDYNLIBPATH) \
               ../../../plugins/DataRecorder/VelocityRecorder/$(YADEDYNLIBPATH) \
               ../../../plugins/Interaction/BroadInteractor/SAPCollider/$(YADEDYNLIBPATH) \
               ../../../yade/Engine/$(YADEDYNLIBPATH) \
               ../../../yade/Body/Body/$(YADEDYNLIBPATH) \
               ../../../plugins/DataRecorder/ForceRecorder/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterFunctor/CundallNonViscousMomentumDampingFunctor/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterFunctor/CundallNonViscousForceDampingFunctor/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterReset/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/ActionParameterInitializer/$(YADEDYNLIBPATH) \
               ../../../plugins/Engine/Condition/GravityCondition/$(YADEDYNLIBPATH) \
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
HEADERS += SDECImpactTest.hpp 
SOURCES += SDECImpactTest.cpp 