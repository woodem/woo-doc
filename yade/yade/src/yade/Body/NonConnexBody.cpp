#ifdef WIN32
#include <windows.h> // The Win32 versions of the GL header files require that you windows.h before gl.h/glu.h/glut.h, so that you get the #define types like WINGDIAPI and such
#endif

#include <GL/gl.h>
#include <GL/glut.h>
#include "Constants.hpp"
#include "NonConnexBody.hpp"

NonConnexBody::NonConnexBody() : Body()
{
}
NonConnexBody::~NonConnexBody() 
{

}


void NonConnexBody::glDraw()
{	
	
	std::vector<shared_ptr<Body> >::iterator bi = bodies.begin();
	std::vector<shared_ptr<Body> >::iterator biEnd = bodies.end();
	
	glPushMatrix();
	
	float angle;
	Vector3 axis;	
	se3.rotation.toAngleAxis(angle,axis);

	glTranslatef(se3.translation[0],se3.translation[1],se3.translation[2]);
	glRotated(angle*Constants::RAD_TO_DEG,axis[0],axis[1],axis[2]);
		
	glDisable(GL_LIGHTING);
	
	for(; bi != biEnd ; ++bi)
		(*bi)->glDraw();	
		
	glPopMatrix();
	
}

void NonConnexBody::processAttributes()
{

}

void NonConnexBody::registerAttributes()
{
	Body::registerAttributes();
	
	REGISTER_ATTRIBUTE(bodies);
//	REGISTER_ATTRIBUTE(narrowCollider);
//	REGISTER_ATTRIBUTE(broadCollider);
//	REGISTER_ATTRIBUTE(kinematic);
	REGISTER_ATTRIBUTE(permanentInteractions);
}

void NonConnexBody::updateBoundingVolume(Se3& se3)
{
	for(unsigned int i=0;i<bodies.size();i++)
		bodies[i]->updateBoundingVolume(se3);
}

void NonConnexBody::updateCollisionGeometry(Se3& )
{

}

void NonConnexBody::moveToNextTimeStep()
{

	vector<shared_ptr<Actor> >::iterator ai    = actors.begin();
	vector<shared_ptr<Actor> >::iterator aiEnd =  actors.end();
	for(;ai!=aiEnd;++ai)
		if ((*ai)->isActivated())
			(*ai)->action(this);

// FIND INTERACTIONS
	// serach for potential collision (maybe in to steps for hierarchical simulation)
//	if (broadCollider!=0)
//		broadCollider->broadCollisionTest(bodies,interactions);
	// this has to split the contact list into several constact list according to the physical type
	// (RigidBody,FEMBody ...) of colliding body
//	if (narrowCollider!=0)
//		narrowCollider->narrowCollisionPhase(bodies,interactions);
// MOTION
	// for each contact list we call the correct dynamic engine
	//if (dynamic!=0)
	//	dynamic->respondToCollisions(this,interactions); //effectiveDt == dynamic->...
	//if (kinematic!=0)
	//	kinematic->moveToNextTimeStep(bodies);

	// FIXME : do we need to walk through the tree of objects in a different way than below ??	
	for(unsigned int i=0;i<bodies.size();i++)
		bodies[i]->moveToNextTimeStep();

	
}