#include "buffer.hpp"
#include "writer.hpp"

namespace bits
    {
	void writer::attach( reader & r )
		{
		registered.push_back( &r );
		}

    void writer::broadcast( const buffer & buf )
        {
        for( std::list<reader*>::iterator It = registered.begin(); It != registered.end(); It++ )
            {
            (*It)->insert( buf );
            }
        }
    }

