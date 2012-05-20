#ifndef SAMPLES_BUFFER_HPP
#define SAMPLES_BUFFER_HPP

#include <cstddef>

namespace samples
	{
	enum sample_type
		{
		S16,
		S8,
		F32,
		F64
		};
	struct buffer
		{
		size_t num_samples;
		sample_type type;
		const void * data;
		double operator[]( size_t idx )const;
		};
	}

#endif
