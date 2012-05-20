#include "exponential_smoother.hpp"
#include <cassert>

namespace filters
	{
	exponential_smoother::exponential_smoother( double the_ratio )
		{
		ratio = the_ratio;
		init = 0;
		assert( ratio > 0.0 && ratio < 1.0 );
		}

	void exponential_smoother::insert_sample( double sample )
		{
		if( init == true )
			{
			residue = ( ratio * residue ) + ( ( 1 - ratio ) * sample );
			}
		else
			{
			residue = sample;
			init = true;
			}

		samples::buffer buf;
		buf.num_samples  = 1;
		buf.data = &residue;
		buf.type = samples::F64;
		broadcast( buf );
		}

	void exponential_smoother::insert( const samples::buffer & buf )
		{
		size_t i;
		for( i = 0; i < buf.num_samples; ++i )
			{
			insert_sample( buf[ i ] );
			}
		residue = buf[0];
		}
	}
