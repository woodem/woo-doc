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

#include "Sphere2Sphere4SDECContactModel.hpp"
#include "InteractionSphere.hpp"
#include "SDECContactGeometry.hpp"
#include "SDECLinkGeometry.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

bool Sphere2Sphere4SDECContactModel::go(	const shared_ptr<InteractionDescription>& cm1,
						const shared_ptr<InteractionDescription>& cm2,
						const Se3r& se31,
						const Se3r& se32,
						const shared_ptr<Interaction>& c)
{
	shared_ptr<InteractionSphere> s1 = dynamic_pointer_cast<InteractionSphere>(cm1);
	shared_ptr<InteractionSphere> s2 = dynamic_pointer_cast<InteractionSphere>(cm2);

	Vector3r normal = se32.translation-se31.translation;
	Real penetrationDepth = s1->radius+s2->radius-normal.normalize();

	shared_ptr<SDECContactGeometry> scm;
	if (c->interactionGeometry)
	{
		scm = dynamic_pointer_cast<SDECContactGeometry>(c->interactionGeometry);
		
		if(! scm) // this is not SDECContactGeometry, so it is SDECLinkGeometry, dispatcher should do this job.
		{
			shared_ptr<SDECLinkGeometry> linkGeometry = dynamic_pointer_cast<SDECLinkGeometry>(c->interactionGeometry);
//			cerr << "it is SpringGeometry ???: " << c->interactionGeometry->getClassName() << endl;
//			assert(linkGeometry);
			if(linkGeometry)
			{
				linkGeometry->normal 			= se32.translation-se31.translation;
				linkGeometry->normal.normalize();
				return true;
			}
			else
				return false; // SpringGeometry !!!???????
		}
	}
	else
		scm = shared_ptr<SDECContactGeometry>(new SDECContactGeometry());
		
	if (penetrationDepth>0)
	{
		scm->contactPoint = se31.translation+(s1->radius-0.5*penetrationDepth)*normal;//0.5*(pt1+pt2);
		scm->normal = normal;
		scm->penetrationDepth = penetrationDepth;
		scm->radius1 = s1->radius;
		scm->radius2 = s2->radius;
				
		if (!c->interactionGeometry)
			c->interactionGeometry = scm;
	
		return true;
	}
	else	
		return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

bool Sphere2Sphere4SDECContactModel::goReverse(	const shared_ptr<InteractionDescription>& cm1,
						const shared_ptr<InteractionDescription>& cm2,
						const Se3r& se31,
						const Se3r& se32,
						const shared_ptr<Interaction>& c)
{
	return go(cm1,cm2,se31,se32,c);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////