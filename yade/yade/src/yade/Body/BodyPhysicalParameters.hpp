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

#ifndef __BodyPhysicalParameters_HPP__
#define __BodyPhysicalParameters_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Serializable.hpp"
#include "Indexable.hpp"
#include "Se3.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class BodyPhysicalParameters : public Serializable, public Indexable
{

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Attributes										      ///
///////////////////////////////////////////////////////////////////////////////////////////////////

	public : Se3r se3;

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor/Destructor								      ///
///////////////////////////////////////////////////////////////////////////////////////////////////

	/*! Constructor */
	public : BodyPhysicalParameters();

	/*! Destructor */
	public : virtual ~BodyPhysicalParameters();

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods										      ///
///////////////////////////////////////////////////////////////////////////////////////////////////

	public : void registerAttributes();
	REGISTER_CLASS_NAME(BodyPhysicalParameters);
	REGISTER_INDEX_COUNTER(BodyPhysicalParameters);
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(BodyPhysicalParameters,false);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __BodyPhysicalParameters_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
