#include "oscillator.hpp"
#include <climits>
#include <stdint.h>
#include <cassert>

namespace samplers
	{
	oscillator::oscillator( samples::sample_type the_type, double the_amplitude, double the_frequency)
		{
		buffer.type = the_type;
		buffer.num_samples = 1;
		amplitude = the_amplitude;
		frequency = the_frequency;
		idx = 0;
		}

	void oscillator::emit_sample( double sample )
		{
		union
			{
			int8_t  s8;
			int16_t s16;
			float   f32;
			double  f64;
			};

		switch(buffer.type)
			{
			case samples::S8:
				assert( sample <= CHAR_MAX );
				assert( sample >= CHAR_MIN );
				s8 = sample;
				buffer.data = &s8;
				break;

			case samples::S16:
				assert( sample <= SHRT_MAX );
				assert( sample >= SHRT_MIN );
				s16 = sample;
				buffer.data = &s16;
				break;

			case samples::F32:
				f32 = sample;
				buffer.data = &f32;
				break;

			case samples::F64:
				f64 = sample;
				buffer.data = &f64;
				break;

			default:
				assert(0);
				break;
			};
		broadcast( buffer );
		}
	}
