#ifndef __BALLISTICDYNAMICENGINE_H__
#define __BALLISTICDYNAMICENGINE_H__

#include "DynamicEngine.hpp"

class BallisticDynamicEngine : public DynamicEngine
{
	private : Vector3 prevVelocity;
	private : Vector3 prevAngularVelocity;
	private : bool first;
	public : float damping;

	// construction
	public : BallisticDynamicEngine ();
	public : ~BallisticDynamicEngine ();

	public : void processAttributes();
	public : void registerAttributes();

	public : void respondToCollisions(Body* body);
	REGISTER_CLASS_NAME(BallisticDynamicEngine);
};

REGISTER_SERIALIZABLE(BallisticDynamicEngine,false);

#endif // __BALLISTICDYNAMICENGINE_H__