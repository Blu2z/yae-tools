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

#ifndef __YAE_MESH_H__
#define __YAE_MESH_H__

#include "prerequisites.h"

namespace yae
{
	class mesh
	{
	public:
		typedef std::vector<vec3> vertices;
		typedef std::vector<vec3> normals;
		typedef std::vector<vec2> texcoords;
		typedef std::vector<uint16_t> indices;

		mesh();
		~mesh();

		bool load( const std::string &name );
		bool load( reader_ptr r );

		void clear();

		void set_vertices( vertices v );
		void set_indices( indices ids );
		void set_normals( normals n );
		void set_texcoords( texcoords tc );
		void set_name( const std::string &name );
		void set_texture_name( const std::string &name );

		std::string get_name() const;
		std::string get_texture_name() const;
		vertices get_vertices() const;
		normals get_normals() const;
		texcoords get_tex_coords() const;
		indices get_indices() const;

	private:
		vertices	vertices_;
		normals		normals_;
		texcoords	texcoords_;
		indices		indices_;

		std::string	texname_;
		std::string	name_;
	};

	inline mesh::mesh() {}
	inline mesh::~mesh() {}

	inline void mesh::set_vertices( vertices v ) { vertices_ = v; }
	inline void mesh::set_indices( indices ids ) { indices_ = ids; }
	inline void mesh::set_normals( normals n ) { normals_ = n; }
	inline void mesh::set_texcoords( texcoords tc ) { texcoords_ = tc; }
	inline void mesh::set_name( const std::string &name ) { name_ = name; }

	inline std::string mesh::get_name() const { return name_; }
	inline std::string mesh::get_texture_name() const { return texname_; }
	inline mesh::vertices mesh::get_vertices() const { return vertices_; }
	inline mesh::normals mesh::get_normals() const { return normals_; }
	inline mesh::texcoords mesh::get_tex_coords() const { return texcoords_; }
	inline mesh::indices mesh::get_indices() const { return indices_; }
}

#endif // __YAE_MESH_H__