#ifndef __SIMPLESPRINGDYNAMICENGINE_H__
#define __SIMPLESPRINGDYNAMICENGINE_H__

#include "InteractionSolver.hpp"
class ActionParameter;


class SimpleSpringLaw : public InteractionSolver
{
	private : shared_ptr<ActionParameter> actionForce;
	private : shared_ptr<ActionParameter> actionMomentum;

	// construction
	public : SimpleSpringLaw ();
	
	public : void registerAttributes();

	public : void calculateForces(Body* body);
	REGISTER_CLASS_NAME(SimpleSpringLaw);
};

REGISTER_SERIALIZABLE(SimpleSpringLaw,false);

#endif // __SIMPLESPRINGDYNAMICENGINE_H__