isEmpty ( YADE_QMAKE_PATH ) {
error( "YADE_QMAKE_PATH internal qmake variable is not set, you should run for example qmake YADE_QMAKE_PATH=/usr/local, this will not work from inside kdevelop (when they will fix it?)" )
}


LIBS += -lSDECLinkPhysics \
        -lElasticContactParameters \
        -lSDECLinkGeometry \
        -lSpheresContactGeometry \
        -lBodyMacroParameters \
        -lyade-lib-wm3-math \
        -lyade-lib-multimethods \
        -lForce \
        -lMomentum \
        -lSphere \
        -lRigidBodyParameters \
        -rdynamic 
INCLUDEPATH += $${YADE_QMAKE_PATH}/include/ \
               ../../../DataClass/InteractionPhysics/SDECLinkPhysics \
               ../../../DataClass/InteractionPhysics/ElasticContactParameters \
               ../../../DataClass/InteractionGeometry/SDECLinkGeometry \
               ../../../DataClass/InteractionGeometry/SpheresContactGeometry \
               ../../../DataClass/PhysicalParameters/BodyMacroParameters 
QMAKE_LIBDIR = ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               ../../../../bin \
               $${YADE_QMAKE_PATH}/lib/yade/yade-package-common \
               $${YADE_QMAKE_PATH}/lib/yade/yade-libs/ 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = ../../../../bin 
CONFIG += debug \
          thread \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += ElasticCohesiveLaw.hpp 
SOURCES += ElasticCohesiveLaw.cpp 