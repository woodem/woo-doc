#ifdef WIN32
#include <windows.h> // The Win32 versions of the GL header files require that you windows.h before gl.h/glu.h/glut.h, so that you get the #define types like WINGDIAPI and such
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include "Math.hpp"

#include "ComplexBody.hpp"
#include "InteractionVecSet.hpp"
#include "InteractionHashMap.hpp"
#include "BodyRedirectionVector.hpp"
#include "BodyAssocVector.hpp"
#include "BoundingVolumeDispatcher.hpp"
#include "ActionVecVec.hpp"

// FIXME - who is to decide which class to use by default?
ComplexBody::ComplexBody() :
	  Body()
	, bodies(new BodyRedirectionVector)
	, permanentInteractions(new InteractionVecSet)
	, interactions(new InteractionVecSet)
	, actions(new ActionVecVec)
{	
}

//#include "InteractionDescriptionSet.hpp"
void ComplexBody::postProcessAttributes(bool deserializing)
{
	if (deserializing)
	{
		// to build bounding volume if there is a bounding volume updator in the actor list
		// FIXME : I don't know is this is so dirty to do that here
		vector<shared_ptr<Actor> >::iterator ai    = actors.begin();
		vector<shared_ptr<Actor> >::iterator aiEnd =  actors.end();
		for(;ai!=aiEnd;++ai)
			if (dynamic_pointer_cast<BoundingVolumeDispatcher>(*ai))
				(*ai)->action(this);
	}
			
	Body::postProcessAttributes(deserializing);
}

void ComplexBody::registerAttributes()
{
	Body::registerAttributes();
	REGISTER_ATTRIBUTE(actors);
	REGISTER_ATTRIBUTE(bodies);
	REGISTER_ATTRIBUTE(interactions);
	REGISTER_ATTRIBUTE(permanentInteractions);
//	REGISTER_ATTRIBUTE(actions); // FIXME - needed or not ?
}


void ComplexBody::moveToNextTimeStep()
{
	vector<shared_ptr<Actor> >::iterator ai    = actors.begin();
	vector<shared_ptr<Actor> >::iterator aiEnd =  actors.end();
	for(;ai!=aiEnd;++ai)
		if ((*ai)->isActivated())
			(*ai)->action(this);
}