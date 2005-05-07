/***************************************************************************
 *   Copyright (C) 2004 by Janek Kozicki                                   *
 *   cosurgi@berlios.de                                                    *
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

#ifndef ACTION_DAMPING_DISPATCHER_HPP
#define ACTION_DAMPING_DISPATCHER_HPP

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine.hpp"
#include "DynLibDispatcher.hpp"
#include "PhysicalAction.hpp"
#include "PhysicalActionEngineUnit.hpp"

class Body;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class PhysicalActionMetaEngine : 
	  public Engine
	, public DynLibDispatcher
		<	  TYPELIST_2( PhysicalAction , PhysicalParameters )	// base classess for dispatch
			, PhysicalActionEngineUnit				// class that provides multivirtual call
			, void						// return type
			, TYPELIST_3(	  const shared_ptr<PhysicalAction>&	// function arguments
					, const shared_ptr<PhysicalParameters>& 
					, const Body *
				    )
		>
{
	public 		: virtual void action(Body* body);
	public		: virtual void registerAttributes();
	protected	: virtual void postProcessAttributes(bool deserializing);
	REGISTER_CLASS_NAME(PhysicalActionMetaEngine);
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(PhysicalActionMetaEngine,false);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ACTION_DAMPING_DISPATCHER_HPP