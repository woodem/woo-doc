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

#include "Box2Sphere4ErrorTolerant.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "ErrorTolerantContactModel.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


Box2Sphere4ErrorTolerant::Box2Sphere4ErrorTolerant ()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

Box2Sphere4ErrorTolerant::~Box2Sphere4ErrorTolerant ()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

bool Box2Sphere4ErrorTolerant::collide(const shared_ptr<CollisionGeometry> cm1, const shared_ptr<CollisionGeometry> cm2, const Se3& se31, const Se3& se32, shared_ptr<Interaction> c)
{

	//if (se31.rotation == Quaternion())
	//	return collideAABoxSphere(cm1,cm2,se31,se32,c);
	
	Vector3 l,t,p,q,r;
	bool onborder = false;
	Vector3 pt1,pt2,normal;
	Matrix3 axisT,axis;
	float depth;

	shared_ptr<Sphere> s = dynamic_pointer_cast<Sphere>(cm2);
	shared_ptr<Box> obb = dynamic_pointer_cast<Box>(cm1);
	
	Vector3 extents = obb->extents;

	se31.rotation.toRotationMatrix(axisT);
	axis = axisT.Transpose();
	
	p = se32.translation-se31.translation;
	
	l[0] = extents[0];
	t[0] = axis.GetRow(0).dot(p); 
	if (t[0] < -l[0]) { t[0] = -l[0]; onborder = true; }
	if (t[0] >  l[0]) { t[0] =  l[0]; onborder = true; }

	l[1] = extents[1];
	t[1] = axis.GetRow(1).dot(p);
	if (t[1] < -l[1]) { t[1] = -l[1]; onborder = true; }
	if (t[1] >  l[1]) { t[1] =  l[1]; onborder = true; }

	l[2] = extents[2];
	t[2] = axis.GetRow(2).dot(p);
	if (t[2] < -l[2]) { t[2] = -l[2]; onborder = true; }
	if (t[2] >  l[2]) { t[2] =  l[2]; onborder = true; }
	
	if (!onborder) 
	{
		// sphere center inside box. find largest `t' value
		float min = l[0]-fabs(t[0]);
		int mini = 0;
		for (int i=1; i<3; i++) 
		{
			float tt = l[i]-fabs(t[i]);
			if (tt < min) 
			{
				min = tt;
				mini = i;
			}
		}
		
		// contact normal aligned with box edge along largest `t' value
		Vector3 tmp = Vector3(0,0,0);

		tmp[mini] = (t[mini] > 0) ? 1.0 : -1.0;
		
		normal = axisT*tmp;
		
		normal.unitize();
		
		pt1 = se32.translation + normal*min;
		pt2 = se32.translation - normal*s->radius;	
	
		shared_ptr<ErrorTolerantContactModel> cm = shared_ptr<ErrorTolerantContactModel>(new ErrorTolerantContactModel());
		cm->closestPoints.push_back(std::pair<Vector3,Vector3>(pt1,pt2));
		cm->normal = pt1-pt2;
		cm->o1p1 = pt1-se31.translation;
		cm->o2p2 = pt2-se32.translation;
		c->interactionGeometry = cm;
		
		return true;	
	}
	//FIXME : use else instead and signle return
	
	q = axisT*t;
	r = p - q;
	
	depth = s->radius-sqrt(r.dot(r));
	
	if (depth < 0) 
		return false;

	pt1 = q + se31.translation;

	normal = r;
	normal.unitize();

	pt2 = se32.translation - normal * s->radius;
		
	shared_ptr<ErrorTolerantContactModel> cm = shared_ptr<ErrorTolerantContactModel>(new ErrorTolerantContactModel());
	cm->closestPoints.push_back(std::pair<Vector3,Vector3>(pt1,pt2));
	cm->normal = pt1-pt2;
	cm->o1p1 = pt1-se31.translation;
	cm->o2p2 = pt2-se32.translation;
	c->interactionGeometry = cm;


	
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

bool Box2Sphere4ErrorTolerant::reverseCollide(const shared_ptr<CollisionGeometry> cm1, const shared_ptr<CollisionGeometry> cm2,  const Se3& se31, const Se3& se32, shared_ptr<Interaction> c)
{
	bool isColliding = collide(cm2,cm1,se32,se31,c);
	if (isColliding)
	{
		shared_ptr<ErrorTolerantContactModel> cm = dynamic_pointer_cast<ErrorTolerantContactModel>(c->interactionGeometry);

		Vector3 tmp = cm->closestPoints[0].first;
		cm->closestPoints[0].first = cm->closestPoints[0].second;
		cm->closestPoints[0].second = tmp;
		tmp = cm->o1p1;
		cm->o1p1 = cm->o2p2;
		cm->o2p2 = tmp;		
		cm->normal.negate();
	}
	return isColliding;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////