/*************************************************************************
*  Copyright (C) 2004 by Janek Kozicki                                   *
*  cosurgi@berlios.de                                                    *
*  Copyright (C) 2006 by Bruno Chareyre                                  *
*  bruno.chareyre@hmg.inpg.fr                                            *
*                                                                        *
*  This program is free software; it is licensed under the terms of the  *
*  GNU General Public License v2 or later. See file LICENSE for details. *
*************************************************************************/


#include "ResultantForceEngine.hpp"
#include "yade/yade-package-common/ParticleParameters.hpp"
#include "yade/yade-package-common/Force.hpp"
#include "StiffnessMatrix.hpp"
#include <yade/yade-lib-wm3-math/Math.hpp>


#include <yade/yade-core/MetaBody.hpp>


ResultantForceEngine::ResultantForceEngine() : actionParameterStiffnessMatrix(new StiffnessMatrix), actionParameterForce(new Force)
{
cerr << "constructeur de ResultantForceEngine" << std::endl;
	interval =1;
	damping = 0.1;
	force = Vector3r::ZERO;
	previoustranslation = Vector3r::ZERO;
	stiffness = Vector3r::ZERO;
	max_vel = 0.001;
}

ResultantForceEngine::~ResultantForceEngine()
{
}


void ResultantForceEngine::registerAttributes()
{
	DeusExMachina::registerAttributes();
	REGISTER_ATTRIBUTE(interval);
	REGISTER_ATTRIBUTE(damping);
	REGISTER_ATTRIBUTE(force);
	REGISTER_ATTRIBUTE(previoustranslation);
	REGISTER_ATTRIBUTE(stiffness);
	REGISTER_ATTRIBUTE(max_vel);
}



void ResultantForceEngine::applyCondition(Body* body)
{
	//cerr << "void ResultantForceEngine::applyCondition(Body* body)" << std::endl;
	MetaBody * ncb = dynamic_cast<MetaBody*>(body);
	shared_ptr<BodyContainer>& bodies = ncb->bodies;
	
	std::vector<int>::const_iterator ii = subscribedBodies.begin();
	std::vector<int>::const_iterator iiEnd = subscribedBodies.end();
	
	//cerr << "std::vector<int>::const_iterator iiEnd = subscribedBodies.end();" << Omega::instance().getCurrentIteration() << std::endl;
	
	
	
	for(;ii!=iiEnd;++ii)
	{
	//cerr << "for(;ii!=iiEnd;++ii)" << std::endl;
	//if( bodies->exists(*ii) ) 
	//{
		//Update stiffness only if it has been computed by StiffnessCounter (see "interval")
		if (Omega::instance().getCurrentIteration() % interval == 0)	stiffness =
		(static_cast<StiffnessMatrix*>( ncb->physicalActions->find (*ii, actionParameterStiffnessMatrix->getClassIndex() ).get() ))->stiffness;
	
		//cerr << "static_cast<StiffnessMatrix*>( ncb->physicalActions->find (*ii, actionParameterStiffnessMatrix->getClassIndex() ).get() ))->stiffness" << std::endl;
		
		if(PhysicalParameters* p = dynamic_cast<PhysicalParameters*>((*bodies)[*ii]->physicalParameters.get()))
		{
			//cerr << "dynamic_cast<PhysicalParameters*>((*bodies)[*ii]->physicalParameters.get()" << std::endl;
			StiffnessMatrix* sm = static_cast<StiffnessMatrix*>( ncb->physicalActions->find (*ii, actionParameterStiffnessMatrix->getClassIndex() ).get() );
			
			Vector3r effectiveforce =
			 	static_cast<Force*>( ncb->physicalActions->find( *ii,actionParameterForce->getClassIndex() ).get() )->force; 
			Vector3r deltaf (effectiveforce - force);
			Vector3r translation 
				(stiffness.x()==0 ? Mathr::sign(deltaf.x())*max_vel : Mathr::sign(deltaf.x())*std::min( abs(deltaf.x()/stiffness.x()), max_vel),
				stiffness.y()==0 ? Mathr::sign(deltaf.y())*max_vel : Mathr::sign(deltaf.y())*std::min( abs(deltaf.y()/stiffness.y()), max_vel),
				stiffness.z()==0 ? Mathr::sign(deltaf.z())*max_vel : Mathr::sign(deltaf.z())*std::min( abs(deltaf.z()/stiffness.z()), max_vel) );
			previoustranslation = (1-damping)*translation + 0.9*previoustranslation;// formula for "steady-flow" evolution with fluctuations
			p->se3.position	+= previoustranslation;
			//p->velocity		=  previoustranslation/dt;//FIXME : useless???	
		}		
	//}
	}
}


