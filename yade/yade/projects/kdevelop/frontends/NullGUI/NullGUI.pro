# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./frontends/YadeQtGUI
# Target is a library:  

LIBS += -lSerialization \
        -lRigidBody \
        -lMath \
        -lBody \
        -lIOManager \
        -lEngine \
        -lGeometry \
        -lInteraction \
        -lFrontEnd \
        -lMultiMethods \
        -rdynamic 
INCLUDEPATH = ../../plugins/Body/RigidBody \
              ../../yade/yade \
              ../../yade/Body \
              ../../yade/Engine \
              ../../yade/Interaction \
              ../../yade/Geometry \
              ../../yade/MultiMethods \
              ../../yade/Factory \
              ../../toolboxes/Libraries/FrontEnd \
              ../../toolboxes/Libraries/Math \
              ../../toolboxes/Libraries/IOManager \
              ../../toolboxes/Libraries/Serialization 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
               ../../plugins/Body/RigidBody/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../yade/Body/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/IOManager/$(YADEDYNLIBPATH) \
               ../../yade/Engine/$(YADEDYNLIBPATH) \
               ../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../yade/Interaction/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/FrontEnd/$(YADEDYNLIBPATH) \
               ../../yade/MultiMethods/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += NullGUI.hpp
SOURCES += NullGUI.cpp