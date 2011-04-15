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

#include "mesh.h"
#include "reader.h"
#include "math.h"
#include "file_system.h"

#define TEXTURES_NUM	5

using namespace yae;

void mesh::clear()
{
	vertices_.clear();
	normals_.clear();
	texcoords_.clear();
	indices_.clear();
	texname_.clear();
	name_.clear();
}

////
// originally writen by iorange
//
bool mesh::load( reader_ptr r )
{
	std::string file_id = r->r_string();
	std::string ver = r->r_string();
	std::string name = r->r_string();
	r->advance(1);
	std::string material = r->r_string();

	std::string texture;
	for( uint32_t i = 0; i < TEXTURES_NUM; i++ ) {
		std::string str = r->r_string();
		if( str != std::string( "notexture" ) )
			texture = str;
	}

	r->advance( 33 );

	uint32_t num_indices = r->r_u32();
	size_t size = num_indices * sizeof(uint16_t);
	mesh::indices i( num_indices );
	r->r_data( &i[0], size );

	uint16_t num_verts = r->r_u16();
	size = num_verts * sizeof(vec3);
	mesh::vertices v( num_verts );
	r->r_data( &v[0], size );

	size = num_verts * sizeof(vec3);
	mesh::normals n( num_verts );
	r->r_data( &n[0], size );

	size = num_verts * sizeof(vec2);
	mesh::texcoords t( num_verts );
	r->r_data( &t[0], size );

	size_t offset = texture.find_last_of( "\\" ) + 1;
	size = texture.length() - offset;
	texture = texture.substr( offset, size );
	size = texture.find_last_of( "." );
	texture = texture.substr( 0, size );
	texture = texture + std::string( ".dds" );

	set_indices(i);
	set_vertices(v);
	set_normals(n);
	set_texcoords(t);
	set_name( name );
	set_texture_name( texture );

	return true;
}

bool mesh::load( const std::string &name )
{
	file_system fs;
	reader_ptr r = fs.open_reader( name );
	if( r.is_null() )
		return false;
	return load( r );
}

void mesh::set_texture_name( const std::string &name )
{
	yae::file_system fs;
	std::string texname = fs.get_full_path( name );
	texname_ = texname;
}