#ifndef SAMPLER_HPP
#define SAMPLER_HPP

#include "sample_rate.hpp"
#include <vector>

class sampler
	{
	public:
		void get_coupling_mode(void);
		std::vector<sample_rate> get_sample_rates();
	};

#endif
