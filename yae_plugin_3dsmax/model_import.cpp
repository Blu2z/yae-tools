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

#include "precompiled.h"
#include "model_import.h"

using namespace m2033_3dsmax;

int model_import::DoImport( const TCHAR *name, ImpInterface *ii, Interface *iface, BOOL suppressPrompts )
{
	yae::mesh m;
	bool res = 0;
	yae::file_system fs;

	fs.set_root_from_fname( name );
	res = m.load( name );
	if( !res )
		return IMPEXP_FAIL;

	TriObject *object = CreateNewTriObject();
	Mesh& mesh = object->GetMesh();
	set_mesh( mesh, m );

	INode *node = iface->CreateObjectNode( object );
	node->SetName( (char*)m.get_name().c_str() );

	create_material( node, m.get_texture_name() );

	iface->ForceCompleteRedraw();

	return IMPEXP_SUCCESS;
}

void model_import::set_mesh( Mesh &m1, yae::mesh &m2 )
{
	yae::mesh::vertices v = m2.get_vertices();
	yae::mesh::indices idx = m2.get_indices();
	yae::mesh::texcoords tc = m2.get_tex_coords();

	m1.setNumVerts( v.size() );
	m1.setNumTVerts( tc.size() );
	m1.setNumFaces( idx.size() / 3 );
	m1.setNumTVFaces( idx.size() / 3 );

	for( unsigned i = 0; i < v.size(); i++ )
	{
		m1.setVert( i, v[i].x, v[i].y, v[i].z );
		m1.setTVert( i, tc[i].x, -tc[i].y, 0 );
	}

	for( unsigned i = 0; i < idx.size() / 3; i++ )
	{
		m1.faces[i].setVerts( idx[i*3+2], idx[i*3+1], idx[i*3] );
		m1.tvFace[i].setTVerts( idx[i*3+2], idx[i*3+1], idx[i*3] );
		m1.faces[i].setSmGroup( 1 );
		m1.faces[i].setEdgeVisFlags( 1, 1, 1 );
	}
}

void model_import::ShowAbout( HWND hwnd )
{
	MessageBox( hwnd,
				"You Are Empty Model import plugin.\n"
				"Created by Ivan Shishkin <codingdude@gmail.com>\n",
				"About",
				MB_ICONINFORMATION );
}
void model_import::create_material( INode *node, const std::string& texture )
{
	StdMat *mat;
	BitmapTex *tex;
	BitmapInfo bi;
	size_t size, off;
	mtl_map::iterator it;

	std::string name = texture;
	off = texture.find( "\\" );
	if( off != std::string::npos )
	{
		off++;
		size = texture.length() - off;
		name = texture.substr( off, size );
	}

	it = materials_.find( name );
	if( it != materials_.end() )
	{
		mat = (StdMat*) it->second;
		node->SetMtl( mat );
		return;
	}

	mat = NewDefaultStdMat();
	tex = NewDefaultBitmapTex();

	tex->SetMapName( (TCHAR*)texture.c_str() );
	tex->SetName( name.c_str() );
	tex->SetAlphaAsMono( true );

	mat->SetName( name.c_str() );
	mat->SetSubTexmap( ID_DI, tex );
	mat->SetSubTexmap( ID_OP, tex );
	mat->EnableMap( ID_OP, FALSE );
	mat->SetActiveTexmap( tex );
	mat->SetMtlFlag(MTL_TEX_DISPLAY_ENABLED);

	materials_[name] = mat;

	node->SetMtl( mat );
}