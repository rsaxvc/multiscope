#ifndef SAMPLES_BUFFER_HPP
#define SAMPLES_BUFFER_HPP

namespace samples
	{
	enum sample_type
		{
		SAMPLE_S16,
		SAMPLE_S8,
		SAMPLE_F32,
		SAMPLE_F64
		};
	struct buffer
		{
		size_t num_samples;
		sample_type type;
		const void * data;
		};
	}

#endif
