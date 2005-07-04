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

#ifndef __MULTIMETHODSEXCEPTIONS_HPP__
#define __MULTIMETHODSEXCEPTIONS_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
///  FactoryError                                                                                //
///////////////////////////////////////////////////////////////////////////////////////////////////

struct MultiMethodsError : public std::runtime_error
{
	explicit MultiMethodsError(const char* msg) : std::runtime_error(msg) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

struct MultiMethodsUndefinedOrder : public MultiMethodsError
{
	explicit MultiMethodsUndefinedOrder(const char* msg) : MultiMethodsError(msg) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

struct MultiMethodsNotExistingClass : public MultiMethodsError
{
	explicit MultiMethodsNotExistingClass(const char* msg) : MultiMethodsError(msg) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

struct MultiMethodsBadVirtualCall : public MultiMethodsError
{
	explicit MultiMethodsBadVirtualCall(const char* msg) : MultiMethodsError(msg) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

struct MultiMethodsExceptions
{
	static const char* NotExistingClass;
	static const char* UndefinedOrder;
	static const char* BadVirtualCall;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif //  __MULTIMETHODSEXCEPTIONS_HPP__

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
