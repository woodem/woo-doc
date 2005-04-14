/***************************************************************************
 *   Copyright (C) 2004 by Olivier Galizzi                                 *
 *   olivier.galizzi@imag.fr                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "SDECTriaxialTest.hpp"

#include "SimpleBody.hpp"
#include "ComplexBody.hpp"

#include "Box.hpp"
#include "AABB.hpp"
#include "Sphere.hpp"
#include "ComplexBody.hpp"
#include "PersistentSAPCollider.hpp"
#include "BodyMacroParameters.hpp"
#include <fstream>
#include "IOManager.hpp"
#include "ElasticContactLaw.hpp"
#include "BodyMacroParameters.hpp"
#include "Interaction.hpp"
#include "BoundingVolumeDispatcher.hpp"
#include "InteractionDescriptionSet2AABBFunctor.hpp"
#include "InteractionDescriptionSet.hpp"
#include "MacroMicroElasticRelationships.hpp"
#include "SDECTimeStepper.hpp"


#include "ActionParameterDispatcher.hpp"
#include "CundallNonViscousForceDampingFunctor.hpp"
#include "CundallNonViscousMomentumDampingFunctor.hpp"

#include "InteractionGeometryDispatcher.hpp"
#include "InteractionPhysicsDispatcher.hpp"
#include "InteractionBox.hpp"
#include "InteractionSphere.hpp"
#include "ActionParameterDispatcher.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

SDECTriaxialTest::SDECTriaxialTest() : FileGenerator()
{
	lowerCorner 		= Vector3r(1000,1000,1000);
	upperCorner 		= Vector3r(-1000,-1000,-1000);
	
	spacing 		= 0.03;
	disorder 		= 0.3;
	nbSpheres 		= Vector3r(6,6,6);
	
	sphereYoungModulus 	= 15000000.0;
	spherePoissonRatio 	= 0.2;
	sphereFrictionDeg 	= 18.0;
	minRadius 		= 0.01;
	maxRadius 		= 0.035;
	
	boxYoungModulus 	= 15000000.0;
	boxPoissonRatio 	= 0.2;
	boxFrictionDeg 		= -18.0;
	
	density			= 2600;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

SDECTriaxialTest::~SDECTriaxialTest()
{

}

void SDECTriaxialTest::registerAttributes()
{
	REGISTER_ATTRIBUTE(sphereYoungModulus);
	REGISTER_ATTRIBUTE(spherePoissonRatio);
	
	REGISTER_ATTRIBUTE(spacing);
	REGISTER_ATTRIBUTE(disorder);
	REGISTER_ATTRIBUTE(nbSpheres);
	
	REGISTER_ATTRIBUTE(sphereYoungModulus);
	REGISTER_ATTRIBUTE(spherePoissonRatio);
	REGISTER_ATTRIBUTE(sphereFrictionDeg);
	REGISTER_ATTRIBUTE(minRadius);
	REGISTER_ATTRIBUTE(maxRadius);
	
	REGISTER_ATTRIBUTE(boxYoungModulus);
	REGISTER_ATTRIBUTE(boxPoissonRatio);
	REGISTER_ATTRIBUTE(boxFrictionDeg);
	
	REGISTER_ATTRIBUTE(density);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

string SDECTriaxialTest::generate()
{
	return "";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void SDECTriaxialTest::createBox(shared_ptr<Body>& body, Vector3r position, Vector3r extents, bool wire)
{
	body = shared_ptr<Body>(new SimpleBody(0,2));
	shared_ptr<BodyMacroParameters> physics(new BodyMacroParameters);
	shared_ptr<AABB> aabb(new AABB);
	shared_ptr<Box> gBox(new Box);
	shared_ptr<InteractionBox> iBox(new InteractionBox);
	
	Quaternionr q;
	q.fromAxisAngle( Vector3r(0,0,1),0);

	body->isDynamic			= false;
	
	physics->angularVelocity	= Vector3r(0,0,0);
	physics->velocity		= Vector3r(0,0,0);
	physics->mass			= extents[0]*extents[1]*extents[2]*density*2; 
	physics->inertia		= Vector3r(
							  physics->mass*(extents[1]*extents[1]+extents[2]*extents[2])/3
							, physics->mass*(extents[0]*extents[0]+extents[2]*extents[2])/3
							, physics->mass*(extents[1]*extents[1]+extents[0]*extents[0])/3
						);
//	physics->mass			= 0;
//	physics->inertia		= Vector3r(0,0,0);
	physics->se3			= Se3r(position,q);

	physics->young			= boxYoungModulus;
	physics->poisson		= boxPoissonRatio;
	physics->frictionAngle		= boxFrictionDeg * Mathr::PI/180.0;

	aabb->diffuseColor		= Vector3r(1,0,0);

	gBox->extents			= extents;
	gBox->diffuseColor		= Vector3f(1,1,1);
	gBox->wire			= wire;
	gBox->visible			= true;
	gBox->shadowCaster		= false;
	
	iBox->extents			= extents;
	iBox->diffuseColor		= Vector3f(1,1,1);

	body->boundingVolume		= aabb;
	body->interactionGeometry	= iBox;
	body->geometricalModel		= gBox;
	body->physicalParameters	= physics;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

void SDECTriaxialTest::createSphere(shared_ptr<Body>& body, int i, int j, int k)
{
	body = shared_ptr<Body>(new SimpleBody(0,1));
	shared_ptr<BodyMacroParameters> physics(new BodyMacroParameters);
	shared_ptr<AABB> aabb(new AABB);
	shared_ptr<Sphere> gSphere(new Sphere);
	shared_ptr<InteractionSphere> iSphere(new InteractionSphere);
	
	Quaternionr q;
	q.fromAxisAngle( Vector3r(0,0,1),0);
	
	Vector3r position		= ( Vector3r(i,j,k)
					  + Vector3r(Mathr::symmetricRandom(),Mathr::symmetricRandom(),Mathr::symmetricRandom())*disorder)*spacing;
	
	Real radius 			= (Mathr::intervalRandom(minRadius,maxRadius));
	
	body->isDynamic			= true;
	
	physics->angularVelocity	= Vector3r(0,0,0);
	physics->velocity		= Vector3r(0,0,0);
	physics->mass			= 4.0/3.0*Mathr::PI*radius*radius*radius*density;
	physics->inertia		= Vector3r(2.0/5.0*physics->mass*radius*radius,2.0/5.0*physics->mass*radius*radius,2.0/5.0*physics->mass*radius*radius); //
	physics->se3			= Se3r(position,q);
	physics->young			= sphereYoungModulus;
	physics->poisson		= spherePoissonRatio;
	physics->frictionAngle		= sphereFrictionDeg * Mathr::PI/180.0;

	aabb->diffuseColor		= Vector3r(0,1,0);

	gSphere->radius			= radius;
	gSphere->diffuseColor		= Vector3f(Mathf::unitRandom(),Mathf::unitRandom(),Mathf::unitRandom());
	gSphere->wire			= false;
	gSphere->visible		= true;
	gSphere->shadowCaster		= true;
	
	iSphere->radius			= radius;
	iSphere->diffuseColor		= Vector3f(0.8,0.3,0.3);

	body->interactionGeometry	= iSphere;
	body->geometricalModel		= gSphere;
	body->boundingVolume		= aabb;
	body->physicalParameters	= physics;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////