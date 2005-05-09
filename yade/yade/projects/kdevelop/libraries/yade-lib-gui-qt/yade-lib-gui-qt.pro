# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./gui/QtGUI
# Target is a library:  

LIBS += -lBody \
        -lOpenGLRenderingEngine \
        -lyade-lib-wm3-math \
        -lyade-lib-multimethods \
        -lyade-lib-factory \
        -lyade-lib-opengl \
        -lyade-lib-threads \
        -lXMLManager \
        -lyade-lib-serialization \
        -lInteraction \
        -lyade-lib-serialization-qt \
        -lboost_date_time \
        -lboost_filesystem \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../yade/Body/Body/$(YADEDYNLIBPATH) \
               ../../plugins/Engine/Sensor/RenderingEngine/OpenGLRenderingEngine/OpenGLRenderingEngine/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-wm3-math/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-multimethods/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-factory/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-opengl/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-threads/$(YADEDYNLIBPATH) \
               ../../serialization/XMLManager/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-serialization/$(YADEDYNLIBPATH) \
               ../../yade/Interaction/Interaction/$(YADEDYNLIBPATH) \
               ../../libraries/yade-lib-serialization-qt/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/yade-lib-wm3-math/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/yade-lib-multimethods/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/yade-lib-factory/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/yade-lib-opengl/$(YADEDYNLIBPATH) \
               ../../../toolboxes/Libraries/yade-lib-threads/$(YADEDYNLIBPATH) \
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
FORMS += YadeQtGeneratedMainWindow.ui \
         QtFileGeneratorController.ui \
         QtGeneratedSimulationController.ui \
         QtGeneratedMessageDialog.ui 
HEADERS += QtGUI.hpp \
           GLViewer.hpp \
           YadeQtMainWindow.hpp \
           QtFileGenerator.hpp \
           SimulationController.hpp \
           QGLThread.hpp \
           SimulationControllerUpdater.hpp \
           MessageDialog.hpp \
           FileDialog.hpp 
SOURCES += QtGUI.cpp \
           GLViewer.cpp \
           YadeQtMainWindow.cpp \
           QtFileGenerator.cpp \
           SimulationController.cpp \
           QGLThread.cpp \
           SimulationControllerUpdater.cpp \
           MessageDialog.cpp \
           FileDialog.cpp 
QtGeneratedSimulationController.ui.target = QtGeneratedSimulationController.ui
QtGeneratedFrontEnd.ui.target = QtGeneratedFrontEnd.ui
QtGUISignalCatcher.ui.target = QtGUISignalCatcher.ui
QtFileGeneratorController.ui.target = QtFileGeneratorController.ui