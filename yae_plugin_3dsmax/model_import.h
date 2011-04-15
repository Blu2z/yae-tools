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

#ifndef __3DSMAX_MODEL_IMPORT_H__
#define __3DSMAX_MODEL_IMPORT_H__

namespace m2033_3dsmax
{
class model_import : public SceneImport
{
public:
	int				ExtCount() { return 1; }
	const TCHAR*	Ext( int i ) { return "ds2md"; }
	const TCHAR*	LongDesc() { return "You Are Empty Model Importer"; }
	const TCHAR*	ShortDesc() { return "You Are Empty Model Importer"; }
	const TCHAR*	AuthorName() { return "Ivan Shishkin"; }
	const TCHAR*	CopyrightMessage() { return "Copyright (C) 2010 Ivan Shishkin <codingdude@gmail.com>"; }
	const TCHAR*	OtherMessage1() { return ""; }
	const TCHAR*	OtherMessage2() { return ""; }
	unsigned int	Version() { return 100; }
	int				ZoomExtents() { return ZOOMEXT_NOT_IMPLEMENTED; }
	void			DeleteThis() { delete this; }

	void ShowAbout( HWND hwnd );

	int DoImport( const TCHAR *name, ImpInterface *ii, Interface *i, BOOL suppressPrompts );

	void set_mesh( Mesh &m1, yae::mesh &m2 );

private:
	typedef std::map<std::string, Mtl*> mtl_map;

	void create_material( INode *node, const std::string& texture );

	mtl_map			materials_;
};
}

#endif // __3DSMAX_MODEL_IMPORT_H__