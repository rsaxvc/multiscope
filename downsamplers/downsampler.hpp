#ifndef DOWNSAMPLERS_DOWNSAMPLER_HPP
#define DOWNSAMPLERS_DOWNSAMPLER_HPP

#include "streams/samples/reader.hpp"
#include "streams/samples/writer.hpp"

namespace downsamplers
	{
	class downsampler: public samples::reader, public samples::writer
		{
		};
	}

#endif
