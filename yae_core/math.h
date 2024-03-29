/******************************************************************************
DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
                    Version 2, December 2004 

 Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 

 Everyone is permitted to copy and distribute verbatim or modified 
 copies of this license document, and changing it is allowed as long 
 as the name is changed. 

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 

  0. You just DO WHAT THE FUCK YOU WANT TO. 

******************************************************************************/

#ifndef __YAE_MATH_H__
#define __YAE_MATH_H__

#include "prerequisites.h"

namespace yae
{
	class vec2
	{
	public:
		float x, y;

		vec2();
		vec2( float _x, float _y );
		~vec2();

		vec2 operator + ( const vec2& vector ) const;
		vec2 operator - ( const vec2& vector ) const;
		vec2 operator * ( const vec2& vector ) const;
		vec2 operator * ( const float val ) const;
		 vec2 operator / ( const vec2& vector ) const;
		vec2 operator / ( const float val ) const;

		vec2& operator += ( const vec2& vector );
		vec2& operator -= ( const vec2& vector );
		vec2& operator *= ( const vec2& vector );
		vec2& operator *= ( const float val );
		vec2& operator /= ( const vec2& vector );
		vec2& operator /= ( const float val );

		bool operator == ( const vec2& vector ) const;
		bool operator != ( const vec2& vector ) const;

		float dot( const vec2& vector );
		float dotabs( const vec2& vector );

		vec2& operator = ( const vec2& vector );

		float operator [] ( const unsigned id );

		bool operator > ( const vec2& vector );
		bool operator < ( const vec2& vector );

		float length();
		float normalize();
	};

	class vec3
	{
	public:
		float x, y, z;

		vec3();
		vec3( float _x, float _y, float _z );
		~vec3();

		vec3 operator + ( const vec3& vector ) const;
		vec3 operator - ( const vec3& vector ) const;
		vec3 operator * ( const vec3& vector ) const;
		vec3 operator * ( const float val ) const;
		 vec3 operator / ( const vec3& vector ) const;
		vec3 operator / ( const float val ) const;

		vec3& operator += ( const vec3& vector );
		vec3& operator -= ( const vec3& vector );
		vec3& operator *= ( const vec3& vector );
		vec3& operator *= ( const float val );
		vec3& operator /= ( const vec3& vector );
		vec3& operator /= ( const float val );

		bool operator == ( const vec3& vector ) const;
		bool operator != ( const vec3& vector ) const;

		float dot( const vec3& vector );
		float dotabs( const vec3& vector );

		vec3& operator = ( const vec3& vector );

		float operator [] ( const unsigned id );

		bool operator > ( const vec3& vector );
		bool operator < ( const vec3& vector );

		float length();
		float normalize();
	};
}

#endif // __YAE_MATH_H__