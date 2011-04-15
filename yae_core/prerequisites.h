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

#ifndef __YAE_PREREQUISITES_H__
#define __YAE_PREREQUISITES_H__

#pragma warning( disable : 4996 )

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <stack>
#include <memory>

#include <assert.h>
#include <math.h>

#if defined(_MSC_VER)

#define NOMINMAX
#include <basetsd.h>

typedef UINT64		uint64_t;
typedef INT64		int64_t;
typedef UINT32		uint32_t;
typedef INT32		int32_t;
typedef UINT16		uint16_t;
typedef INT16		int16_t;
typedef UINT8		uint8_t;
typedef INT8		int8_t;
typedef	UINT_PTR	uintptr_t;
typedef	INT_PTR		intptr_t;

#endif

#include "shared_ptr.h"

namespace yae
{
	enum
	{
		UNUSED_CHUNK_ID = 0x01,
		TEXTURE_NAME_CHUNK_ID = 0x02,
		STATIC_VERTEX_CHUNK_ID = 0x03,
		DYNAMIC_VERTEX_CHUNK_ID = 0x05,
		MODEL_CHUNK_ID = 0x09,
		BONES_CHUNK_ID = 0x0D,
		MESH_NAMES_CHUNK_ID = 0x10,
		SKELETON_NAME_CHUNK_ID = 0x14,
		LEVEL_PARTS_CHUNK_ID = 0x03,
		LEVEL_TEXTURES_CHUNK_ID = 0x02,
		LEVEL_VB_CHUNK_ID = 0x09,
		LEVEL_IB_CHUNK_ID = 0x0A
	};

	class vec3;
	class vec2;
	class mesh;
	class reader;

	typedef std::list<std::string> string_list;
	typedef std::vector<std::string> string_vector;
	typedef shared_ptr<mesh> mesh_ptr;
	typedef shared_ptr<reader> reader_ptr;
	typedef std::vector<mesh_ptr> mesh_vector;
}

#endif // __YAE_PREREQUISITES_H__