#include "buffer.hpp"
#include <stdint.h>
#include <cassert>

namespace samples
	{
	double buffer::operator[]( size_t idx )const
		{
		assert( idx < num_samples );

		switch( type )
			{
			case S16:
				return ((int16_t*)data)[idx];
			case S8:
				return ((int8_t*)data)[idx];
			case F32:
				return ((float*)data)[idx];
			case F64:
				return ((double*)data)[idx];

			default:
				assert(0);
			}

		return 0.0;
		}
	}
