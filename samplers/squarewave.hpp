#ifndef SAMPLERS_SQUAREWAVE
#define SAMPLERS_SQUAREWAVE

#include "sampler.hpp"
#include "oscillator.hpp"
#include "streams/samples/buffer.hpp"

namespace samplers
	{
	class squarewave : public oscillator
		{
		public:
			squarewave( samples::sample_type type, double amplitude, double freq ):oscillator(type,amplitude,freq){};
			void emit();
		};
	}

#endif
