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

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BoundingVolumeDispatcher.hpp"
#include "ComplexBody.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void BoundingVolumeDispatcher::postProcessAttributes(bool deserializing)
{
	postProcessDispatcher2D(deserializing);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void BoundingVolumeDispatcher::registerAttributes()
{
	REGISTER_ATTRIBUTE(functorNames);
	REGISTER_ATTRIBUTE(functorArguments);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

void BoundingVolumeDispatcher::action(Body* body)
{
	ComplexBody * ncb = dynamic_cast<ComplexBody*>(body);
	shared_ptr<BodyContainer>& bodies = ncb->bodies;
	
	for( bodies->gotoFirst() ; bodies->notAtEnd() ; bodies->gotoNext())
	{
		shared_ptr<Body>& b = bodies->getCurrent();
		operator()(b->interactionGeometry,b->boundingVolume,b->physicalParameters->se3,b.get());
	}
		
	operator()(body->interactionGeometry,body->boundingVolume,body->physicalParameters->se3,body);
}


