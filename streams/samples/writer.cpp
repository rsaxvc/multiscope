#include "buffer.hpp"
#include "writer.hpp"

#include <algorithm>
#include <cassert>

namespace samples
    {
	void writer::attach( reader & r )
		{
		registered.push_back( &r );
		}

	void writer::detach( reader & r )
		{
		std::list<reader*>::iterator It = find( registered.begin(), registered.end(), &r );
		if( It != registered.end() )
			{
			registered.erase( It );
			}
		else
			{
			assert( 0 );//tried to remove object that wasn't attached
			}
		}

    void writer::broadcast( const buffer & buf )
        {
        for( std::list<reader*>::iterator It = registered.begin(); It != registered.end(); It++ )
            {
            (*It)->insert( buf );
            }
        }

	writer::~writer()
		{
		//everyone should've disconeccted by now
		assert( registered.size() == 0 );
		}
    }

