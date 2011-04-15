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

class model_import_class_desc : public ClassDesc
{
public:
	int				IsPublic() { return TRUE; }
	void*			Create( BOOL loading ) { return new model_import; }
	const TCHAR*	ClassName() { return "ModelImport"; }
	SClass_ID		SuperClassID() { return SCENE_IMPORT_CLASS_ID; }
	Class_ID		ClassID() { return Class_ID(0x4aab7275, 0x7e25049e); }
	const TCHAR*    Category() { return _T(""); }
};

model_import_class_desc	model_import_description;

BOOL WINAPI DllMain( HINSTANCE hinst,ULONG reason, LPVOID reserved )
{
	return TRUE;
}

__declspec( dllexport ) const TCHAR* LibDescription()
{
	return "You Are Empty Import Plugin.";
}

__declspec( dllexport ) int LibInitialize(void)
{
	return 1;
}

__declspec( dllexport ) int LibShutdown(void)
{
	return 1;
}

__declspec( dllexport ) int LibNumberClasses()
{
	return 1;
}

__declspec( dllexport ) ClassDesc *LibClassDesc( int i ) 
{
	switch( i )
	{
	case 0:
		return (ClassDesc*) &model_import_description;
	}

	return 0;
}

__declspec( dllexport ) ULONG LibVersion()
{
	return VERSION_3DSMAX;
}