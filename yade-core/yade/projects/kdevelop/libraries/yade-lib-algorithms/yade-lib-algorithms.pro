# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./libraries/yade-lib-algorithms
# Target is a library:  

LIBS += -lyade-lib-wm3-math 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = $(YADEDYNLIBPATH)/yade-libs 
DESTDIR = $(YADEDYNLIBPATH)/yade-libs 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += PerlinNoise.hpp 
SOURCES += PerlinNoise.cpp 