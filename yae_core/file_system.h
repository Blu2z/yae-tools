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

#ifndef __YAE_FILE_SYSTEM_H__
#define __YAE_FILE_SYSTEM_H__

#include "prerequisites.h"

namespace yae
{
	class file_system
	{
	public:
		reader_ptr open_reader( const std::string& name );

		inline void set_root_dir( const std::string& root ) { root_ = root; }
		inline const std::string& get_root_dir() { return root_; }

		bool set_root_from_fname( const std::string& file );
		std::string get_full_path( const std::string& filename );

		bool file_exists( const std::string &path );

	private:
		static std::string root_;
	};
}

#endif // __YAE_FILE_SYSTEM_H__