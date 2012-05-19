#include "nearest.hpp"

namespace downsamplers
	{
	void nearest::insert( const samples::buffer & buf )
		{
		if( current == 0 )
			{
			broadcast( buf );
			}

		current++;
		if( current > rate )
			{
			current = 0;
			}
		}
	}
