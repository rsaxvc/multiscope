#ifndef FILTERS_DOWNSAMPLER_HPP
#define FILTERS_DOWNSAMPLER_HPP

#include "streams/samples/reader.hpp"
#include "streams/samples/writer.hpp"

namespace filters
	{
	class filter: public samples::reader, public samples::writer
		{
		};
	}

#endif
