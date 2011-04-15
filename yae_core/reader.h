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

#ifndef __YAE_READER_H__
#define __YAE_READER_H__

#include "prerequisites.h"

namespace yae
{
	class reader
	{
	public:
		enum {COMPRESSED_CHUNK = 0x80000000 };

		reader();
		reader( void *data, size_t size );
		~reader();

		size_t open_chunk( bool *compressed = 0 );
		size_t open_chunk( uint32_t id, bool *compressed = 0 );
		reader_ptr decompress_chunk( uint32_t id );
		void close_chunk();
		void close_all_chunks();

		uint32_t chunk_id() const;
		void* data() const;
		size_t size() const;

		size_t tell() const;
		size_t elapsed() const;
		void seek( uint32_t pos );
		void advance( uint32_t offset );

		void r_data( void *data, size_t size );
		void* skip( size_t size );
		void* ptr() const;

		int8_t r_s8();
		uint8_t r_u8();
		int16_t r_s16();
		uint16_t r_u16();
		int32_t r_s32();
		uint32_t r_u32();

		size_t r_sz( char *str, size_t size );
		std::string r_string();

	private:
		struct chunk
		{
			uint32_t	id;
			uint8_t		*begin;
			uint8_t		*end;
		};

		union
		{
			uint8_t	*m_ptr;
			int8_t	*m_s8_ptr;
			uint16_t	*m_u16_ptr;
			int16_t	*m_s16_ptr;
			uint32_t	*m_u32_ptr;
			int32_t	*m_s32_ptr;
		};

		std::stack<chunk> m_chunks;

		uint8_t		*m_begin;
		uint8_t		*m_end;
	};
}

#endif // __YAE_READER_H__