#include "ExplicitMassSpringLaw.hpp"
#include "Omega.hpp"
#include "ComplexBody.hpp"
#include "Mesh2D.hpp"
#include "SpringGeometry.hpp"
#include "SpringPhysics.hpp"
#include "ParticleParameters.hpp"
#include "ActionForce.hpp"
#include "ActionMomentum.hpp"

ExplicitMassSpringLaw::ExplicitMassSpringLaw () : InteractionLaw(), actionForce(new ActionForce) , actionMomentum(new ActionMomentum)
{
}

void ExplicitMassSpringLaw::registerAttributes()
{
	REGISTER_ATTRIBUTE(springGroupMask);
}


void ExplicitMassSpringLaw::respondToInteractions(Body * body)
{
	ComplexBody * massSpring = dynamic_cast<ComplexBody*>(body);
	shared_ptr<BodyContainer>& bodies = massSpring->bodies;
	shared_ptr<InteractionContainer>& permanentInteractions = massSpring->permanentInteractions;
	shared_ptr<ActionContainer>& actions = massSpring->actions;
	
	Vector3r gravity = Omega::instance().getGravity();
	
	for(permanentInteractions->gotoFirst() ; permanentInteractions->notAtEnd(); permanentInteractions->gotoNext())
	{
		const shared_ptr<Interaction>& spring = permanentInteractions->getCurrent();
		int id1 = spring->getId1();
		int id2 = spring->getId2();
		
		if( !(  (*bodies)[id1]->getGroupMask() & (*bodies)[id2]->getGroupMask() & springGroupMask) )
			continue; // skip other groups
		
		ParticleParameters * p1 = static_cast<ParticleParameters*>((*bodies)[id1]->physicalParameters.get());
		ParticleParameters * p2 = static_cast<ParticleParameters*>((*bodies)[id2]->physicalParameters.get());
		
		SpringPhysics* physics		= static_cast<SpringPhysics*>(spring->interactionPhysics.get());
		SpringGeometry* geometry	= static_cast<SpringGeometry*>(spring->interactionGeometry.get());
		
		Vector3r v1 = p2->se3.translation;
		Vector3r v2 = p1->se3.translation;
		
		Real l  = (v2-v1).length();
		
		Real l0 = physics->initialLength;
		
		Vector3r dir = (v2-v1);
		dir.normalize();
		
		Real e  = (l-l0)/l0;
		Real relativeVelocity = dir.dot((p1->velocity-p2->velocity));
		Vector3r f3 = (e*physics->stiffness + relativeVelocity* ( 1.0 - physics->damping )  )*dir;
		
		static_cast<ActionForce*>   ( actions->find( id1 , actionForce->getClassIndex() ).get() )->force    -= f3;
		static_cast<ActionForce*>   ( actions->find( id2 , actionForce->getClassIndex() ).get() )->force    += f3;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Gravity														///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	shared_ptr<ActionForce> af(new ActionForce);
	
	for( bodies->gotoFirst() ; bodies->notAtEnd() ; bodies->gotoNext())
	{
		if(bodies->getCurrent()->getGroupMask() & springGroupMask)
		{
			ParticleParameters * p = static_cast<ParticleParameters*>(bodies->getCurrent()->physicalParameters.get());
			static_cast<ActionForce*>( massSpring->actions->find( bodies->getCurrent()->getId() , actionForce->getClassIndex() ).get() )->force += gravity*p->mass;
		}
	}
}
