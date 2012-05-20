#ifndef SAMPLERS_OSCILLATOR
#define SAMPLERS_OSCILLATOR

#include "sampler.hpp"
#include "streams/samples/buffer.hpp"

namespace samplers
	{
	class oscillator : public sampler
		{
		protected:
			samples::buffer buffer;
			double amplitude;
			double frequency;
			int idx;

			void emit_sample( double );
		public:
			oscillator( samples::sample_type the_type, double the_amplitude, double the_frequency);
			virtual void emit() = 0;
		};
	}

#endif
