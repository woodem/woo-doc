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

#ifndef __PERSISTENTSAPCOLLIDER_HPP__
#define __PERSISTENTSAPCOLLIDER_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "BroadCollider.hpp"
#include "InteractionContainer.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <list>
#include <set>
#include <vector>
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

class PersistentSAPCollider : public BroadCollider
{

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	// represent an extrmity of an Axis ALigned bounding box
	struct AABBBound
	{
		AABBBound(int i, char l) : id(i),lower(l) {};
		int id;		// AABB of the "id" shpere
		char lower; // is it the lower or upper bound of the AABB
		float value;// value of the bound
	};

	// strucuture that compare 2 AABBBounds => used in the sort algorithm
	struct AABBBoundComparator
	{
		bool operator() (shared_ptr<AABBBound> b1, shared_ptr<AABBBound> b2)
		{
			return b1->value<b2->value;
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Attributes										      	///
///////////////////////////////////////////////////////////////////////////////////////////////////

	// number of potential collision = number of colliding AABB
	protected : int nbPotentialCollisions;

	// maximum number of object that that collider can handle
	//protected : unsigned int maxObject;

	// number of AABB
	protected : unsigned int nbObjects;

	// AABB extremity of the sphere number "id" projected onto the X axis
	protected : vector<shared_ptr<AABBBound> > xBounds;

	// AABB extremity of the sphere number "id" projected onto the Y axis
	protected : vector<shared_ptr<AABBBound> > yBounds;

	// AABB extremity of the sphere number "id" projected onto the Z axis
	protected : vector<shared_ptr<AABBBound> > zBounds;

	// collection of AABB that are in collision
	//protected : vector< set<unsigned int> > overlappingBB;
	protected : shared_ptr<InteractionContainer> interactions;
	// upper right corner of the AABB of the objects =>  for spheres = center[i]-radius
	protected : vector<float> maximums;

	// lower left corner of the AABB of the objects =>  for spheres = center[i]+radius
	protected : vector<float> minimums;

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Constructor/Destructor								      	///
///////////////////////////////////////////////////////////////////////////////////////////////////

	/*! Constructor */
	public : PersistentSAPCollider();

	/*! Destructor */
	public : virtual ~PersistentSAPCollider();

///////////////////////////////////////////////////////////////////////////////////////////////////
/// Methods										      	///
///////////////////////////////////////////////////////////////////////////////////////////////////

	protected : virtual void postProcessAttributes(bool deserializing);
	public : void registerAttributes();

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	// return a list "interactions" of pairs of Body which Bounding volume are in collisions
	public : void broadCollisionTest(Body * body);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	// Used the first time broadCollisionTest is called, to initialize and sort the xBounds, yBounds,
	// and zBounds arrays and to initialize the overlappingBB collection
	protected : void updateIds(unsigned int nbElements);

	// Permutation sort the xBounds, yBounds, zBounds arrays according to the "value" field
	// Calls updateOverlapingBBSet every time a permutation between 2 AABB i and j occurs
	protected : void sortBounds(vector<shared_ptr<AABBBound> >& bounds, int nbElements);

	// Tests if the AABBi and AABBj really overlap.
	// If yes, adds the pair (id1,id2) to the collection of overlapping AABBs
	// If no, removes the (id1,id2) to the collection of overlapping AABBs if necessary
	protected : void updateOverlapingBBSet(int id1,int id2);

	// update the "value" field of the xBounds, yBounds, zBounds arrays
	protected : void updateBounds(int nbElements);

	// Used the first time broadCollisionTest is called
	// It is necessary to initialise the overlapping AABB collection because this collection is only
	// incrementally udated each time step
	protected : void findOverlappingBB(vector<shared_ptr<AABBBound> >& bounds, int nbElements);

	REGISTER_CLASS_NAME(PersistentSAPCollider);

};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

REGISTER_SERIALIZABLE(PersistentSAPCollider,false);

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // __PERSISTENTSAPCOLLIDER_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
