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
 
#ifndef __SPHERE2AABBFACTORY_H__
#define __SPHERE2AABBFACTORY_H__

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "BoundingVolumeFunctor.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

class Sphere2AABBFunctor : public BoundingVolumeFunctor
{
	public : void go(	  const shared_ptr<InteractionDescription>& cm
				, shared_ptr<BoundingVolume>& bv
				, const Se3r& se3
				, const Body*	);
	REGISTER_CLASS_NAME(Sphere2AABBFunctor);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(Sphere2AABBFunctor,false);

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __SPHERE2AABBFACTORY_H__

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////