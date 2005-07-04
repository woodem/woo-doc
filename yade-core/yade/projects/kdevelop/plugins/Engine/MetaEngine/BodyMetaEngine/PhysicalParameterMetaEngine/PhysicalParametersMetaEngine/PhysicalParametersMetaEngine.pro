# Plik utworzony przez menad?era projekt�w kdevelopa
# ------------------------------------------- 
# Podkatalog wzgl?dem g?�wnego katalogu projektu: ./plugins/Engine/MetaEngine/BodyMetaEngine/PhysicalParameterMetaEngine/PhysicalParametersMetaEngine
# Cel to biblioteka 

LIBS += -rdynamic 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = $(YADEDYNLIBPATH) 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += PhysicalParametersMetaEngine.hpp \
           PhysicalParametersEngineUnit.hpp 
SOURCES += PhysicalParametersMetaEngine.cpp 