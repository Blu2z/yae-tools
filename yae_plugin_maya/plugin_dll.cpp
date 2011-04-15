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
#include "yae_model_translator.h"

#include <maya/MFnPlugin.h>

using namespace yae_maya;

MStatus initializePlugin( MObject obj )
{
    MFnPlugin plugin( obj, "Ivan Shiskin <codingdude@gmail.com>", "1.0", "Any" );


	MStatus s =  plugin.registerFileTranslator( "You Are Empty Model Translator",
										"",
										yae_model_translator::creator );
	if (!s) {
		s.perror("registerFileTranslator");
		return s;
	}
    
    return s;
}

MStatus uninitializePlugin( MObject obj )
{
    MFnPlugin plugin( obj );
	if( !plugin.deregisterFileTranslator( "You Are Empty Model Translator" ) )
		return MS::kFailure;
    return MS::kSuccess;
}