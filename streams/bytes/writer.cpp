#include "writer.hpp"

namespace bytes
	{
	void writer::broadcast( const buffer & buf )
		{
		for( std::list<reader*>::iterator It = registered.begin(); It != registered.end(); It++ )
			{
			(*It)->insert( buf );
			}
		}
	}
