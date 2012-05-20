#ifndef SAMPLER_HPP
#define SAMPLER_HPP

#include "sample_rate.hpp"
#include "streams/samples/writer.hpp"
#include <vector>

namespace samplers
	{
	class sampler : public samples::writer
		{
		public:
			void get_coupling_mode(void);
			std::vector<sample_rate> get_sample_rates();
		};
	}
#endif
