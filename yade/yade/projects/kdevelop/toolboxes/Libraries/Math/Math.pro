# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./toolboxes/Libraries/Math
# Target is a library:  

LIBS += -lm \
        -rdynamic 
INCLUDEPATH = ../../../yade/yade \
              ../../../yade/Factory \
              ../../../toolboxes/Libraries/Math \
              ../../../toolboxes/Libraries/Serialization 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = $(YADEDYNLIBPATH) 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += Matrix3.hpp \
           Quaternion.hpp \
           Se3.hpp \
           Vector3.hpp \
           Matrix3.ipp \
           Quaternion.ipp \
           Se3.ipp \
           Vector3.ipp \
           Constants.hpp \
           Rand.hpp \
           Rand.ipp \
           Vector2.hpp \
           Vector2.ipp 
SOURCES += Matrix3.cpp \
           Quaternion.cpp \
           Se3.cpp \
           Vector3.cpp \
           Constants.cpp \
           Rand.cpp \
           Vector2.cpp 