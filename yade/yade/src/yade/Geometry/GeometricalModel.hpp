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

#ifndef __GEOMETRICALMODEL_H__
#define __GEOMETRICALMODEL_H__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <GL/glut.h>
#include <GL/gl.h>

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Vector3.hpp"
#include "Serializable.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class GeometricalModel : public Serializable
{

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Attributes											///
///////////////////////////////////////////////////////////////////////////////////////////////////

	public : bool visible;
	public : bool wire;
	public : Vector3 diffuseColor; // + autres proprietes

	// construction
	public : GeometricalModel ();

	public : virtual ~GeometricalModel ();

	//public : virtual bool rayIntersection(const Vector3& origin, const Vector3& direction, Vector3& point) = NULL;

	//public : virtual bool loadFromFile(char * fileName) = NULL;
	public : virtual void glDraw() {};
	public : void registerAttributes();
	public : void processAttributes();
	REGISTER_CLASS_NAME(GeometricalModel);

};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(GeometricalModel,false);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __GEOMETRICALMODEL_H__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////