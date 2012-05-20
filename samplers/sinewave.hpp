#ifndef SAMPLERS_SINEWAVE
#define SAMPLERS_SINEWAVE

#include "sampler.hpp"
#include "oscillator.hpp"
#include "streams/samples/buffer.hpp"

namespace samplers
	{
	class sinewave : public oscillator
		{
		public:
            sinewave( samples::sample_type type, double amplitude, double freq ):oscillator(type,amplitude,freq){};
			void emit();
		};
	}

#endif
