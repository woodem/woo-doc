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

inline Se3::Se3()  : Serializable()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Se3::Se3(const Se3& s) : Serializable()
{ 
	translation = s.translation;
	rotation = s.rotation;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Se3::Se3(Vector3 p, Quaternion r) 
{
	translation = p;
	rotation = r;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	

inline Se3 Se3::inverse()
{
	return Se3(-(rotation.inverse()*translation), rotation.inverse());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

inline Se3::Se3(Se3& a,Se3& b) 
{
	translation  = b.rotation.inverse()*(a.translation - b.translation) ;  
	rotation = b.rotation.inverse()*a.rotation  ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	

inline void Se3::toGLMatrix(float m[16])
{

	rotation.toGLMatrix(m);
 	m[12] = translation[0];
	m[13] = translation[1];
	m[14] = translation[2];
		
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	

inline Vector3 Se3::operator * (const Vector3& b ) 
{
	return rotation*b+translation; 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	

inline Se3 Se3::operator * (const Se3& b ) 
{
	return Se3(rotation*b.translation+translation,rotation*b.rotation); 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	

inline Se3 Se3::operator * (const Quaternion& b )
{
	return Se3(translation , rotation*b);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////	