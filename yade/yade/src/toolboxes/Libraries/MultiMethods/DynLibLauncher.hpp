/***************************************************************************
 *   Copyright (C) 2005 by Janek Kozicki                                   *
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

#ifndef DYNLIB_LAUNCHER_HPP
#define DYNLIB_LAUNCHER_HPP

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "Factorable.hpp"
#include "Typelist.hpp"
#include "Functor.hpp"
#include "MultiMethodsExceptions.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
/// base template for classes that provide virtual functions for multiple dispatch,		///
/// in other words for multivirtual function call						///
///////////////////////////////////////////////////////////////////////////////////////////////////
///
///
/// This is a base template for all classes that will provide functions for multiple dispatch.
///
/// To create a new category of virtual functions you must derive from this class, inside you will
/// have provided virtual functions that you must overload to get multivirtual behaviour.
///
/// Depending on the number of dimensions for which you need multiple dispatch you have to overload
/// different virtual functions:
///
/// for 1D, you overload function [*]:
///		public: virtual ResultType go( ArgumentTypeList );
///
/// for 2D, you overload functions [*]:
///		public: virtual ResultType go( ArgumentTypeList );
///		public: virtual ResultType goReverse( ArgumentTypeList );
///
///	function goReverse is called only when DynLibDispatcher has autoSymmetry set to false.
///	otherwise DynLibDispatcher automatically reverses first two arguments, and calls go(),
///	same applies for 3D.
///
/// for 3D, you overload functions (not implemented now, but easy to write) [*]:
///		public: virtual ResultType go( ArgumentTypeList );
///		public: virtual ResultType go012( ArgumentTypeList );  // forwards call to go()
///		public: virtual ResultType go120( ArgumentTypeList );
///		public: virtual ResultType go201( ArgumentTypeList );
///		public: virtual ResultType go021( ArgumentTypeList );
///		public: virtual ResultType go210( ArgumentTypeList );
///
///
/// Template parameters:
///
///	ResultType 		- is the type returned by multivirtual function
///
///	ArgumentTypeList	- is a TypeList of arguments accepted by multivirtual function,
///				  ATTENTION:
///					- for 1D first type in this list must be of type shared_ptr<YourClass>
///					  this first argument acts like *this, in C++ virtual functions
///
///					- for 2D first and second type in this list must be shared_ptr<YourClass>
///					  those argument act like *this1 and *this2
///
///					- for 3D first, second and third type in this list must be shared_ptr<YourClass>
///					  those argument act like *this1 , *this2 and *this3
///
///
///
/// [*]
/// Note about virtual function arguents ArgumentTypeList - all functions take arguments by value
/// only for fundametal types and pure pointers, all other types are passed by referece. For details look 
/// into Loki::TypeTraits::ParameterType. For example if you your class is:
///
/// class ShapeDraw : public DynLibLauncher< std::string , TYPELIST_4(boost::shared_ptr<Shape>,double,char,const std::string) >
/// {}
///
/// then virtual function to overload is:
///		public: virtual std::string go(boost::shared_ptr<Shape>&,double,char,const std::string& );
///
/// references were added where necessary, to optimize call speed.
/// So pay attentions when you overload this function.
///
///////////////////////////////////////////////////////////////////////////////////////////////////

template
<	class ResultType, 		// type returned by multivirtual function
	class ArgumentTypeList		// TypeList of arguments accepted by multivirtual function,
>
class DynLibLauncher : public Factorable
{
	private:
		typedef Loki::FunctorImpl<ResultType, ArgumentTypeList > Impl;
		typedef ArgumentTypeList ParmList;
		typedef typename Impl::Parm1 Parm1;
		typedef typename Impl::Parm2 Parm2;
		typedef typename Impl::Parm3 Parm3;
		typedef typename Impl::Parm4 Parm4;
		typedef typename Impl::Parm5 Parm5;
		typedef typename Impl::Parm6 Parm6;
		typedef typename Impl::Parm7 Parm7;
		typedef typename Impl::Parm8 Parm8;
		typedef typename Impl::Parm9 Parm9;
		typedef typename Impl::Parm10 Parm10;
		typedef typename Impl::Parm11 Parm11;
		typedef typename Impl::Parm12 Parm12;
		typedef typename Impl::Parm13 Parm13;
		typedef typename Impl::Parm14 Parm14;
		typedef typename Impl::Parm15 Parm15;
	
		void	error()
		{
			std::string err = MultiMethodsExceptions::BadVirtualCall;
			throw MultiMethodsBadVirtualCall(err.c_str());
		}

	public:
			DynLibLauncher () {};
		virtual ~DynLibLauncher () {};
		virtual std::string checkOrder() const { return ""; };

// FIXME : we can save some memory by writing specializations for each number of parameters, like FunctorImpl, but it will not make call faster - always it's one virtual redirection. So I'll do that later.

// in following functions a second throw was added - just to bypass compiler warnings - it will never be executed.

		virtual ResultType go	(	Parm1) 							{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2) 						{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3) 					{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4) 				{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5) 				{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6) 			{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7) 		{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8)	{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9)							{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10)						{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11)					{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12)				{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13)			{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13,Parm14)		{ error();throw; };
		virtual ResultType go	(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13,Parm14,Parm15)	{ error();throw; };
		
		virtual ResultType goReverse(	Parm1) 							{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2) 						{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3) 					{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4) 				{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5) 				{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6) 			{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7) 		{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8)	{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9)							{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10)						{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11)					{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12)				{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13)			{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13,Parm14)		{ error();throw; };
		virtual ResultType goReverse(	Parm1,Parm2,Parm3,Parm4,Parm5,Parm6,Parm7,Parm8,
						Parm9,Parm10,Parm11,Parm12,Parm13,Parm14,Parm15)	{ error();throw; };
};

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#define DEFINE_FUNCTOR_ORDER_2D(class1,class2)							\
	public : virtual std::string checkOrder() const						\
	{											\
		return (string(#class1)+" "+string(#class2));					\
	}											\

#define DEFINE_FUNCTOR_ORDER_3D(class1,class2,class3)						\
	public : virtual std::string checkOrder() const						\
	{											\
		return (string(#class1)+" "+string(#class2)+" "+string(#class3));		\
	}											\


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // DYNLIB_LAUNCHER_HPP

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
