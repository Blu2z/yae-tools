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

#include "file_system.h"
#include "reader.h"

using namespace yae;

static inline void fix_slashes( std::string &s )
{
	uint32_t i = 0;
	size_t len = s.length();
	while( len-- != 0 ) {
		if( s[i] == '\\' )
			s[i] = '/';
		i++;
	}
}

std::string file_system::root_;

bool file_system::set_root_from_fname( const std::string& file )
{
	int size;
	std::string file_name;

	file_name = file;
	fix_slashes( file_name );
	size = file_name.rfind( "/gameres" );
	if( size == std::string::npos )
	{
		return 0;
	}
	file_name = file_name.substr( 0, size );
	file_system::set_root_dir( file_name );

	return 1;
}

std::string file_system::get_full_path( const std::string& filename )
{
	std::string fname = filename;
	fix_slashes( fname );
	return root_ + std::string( "/gameres/textures/$dds/" ) + fname;
}

reader_ptr file_system::open_reader( const std::string& name )
{
	FILE* file;
	uint8_t *data;
	size_t size;

	file = fopen( name.c_str(), "rb" );
	if( !file )
	{
		return reader_ptr();
	}

	fseek( file, 0, SEEK_END );
	size = ftell( file );
	fseek( file, 0, SEEK_SET );
	data = new uint8_t[size];
	fread( data, 1, size, file );
	fclose( file );

	reader *r = new reader( data, size );

	return reader_ptr( r );
}

bool file_system::file_exists( const std::string &path )
{
	FILE *f = fopen( path.c_str(), "r" );
	bool result = (f != 0);
	if( result )
		fclose(f);
	return result;
}