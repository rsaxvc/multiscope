#ifndef DEMODULATORS_FREQUENCY_DETECTOR_HPP
#define DEMODULATORS_FREQUENCY_DETECTOR_HPP

#include "streams/samples/reader.hpp"
#include "streams/samples/writer.hpp"

namespace demodulators
	{
	class frequency_detector: private samples::reader, private samples::writer
		{
		public:
			frequency_detector( double the_freq, int timeslice /*how many samples a bit is*/ );
		};
	}

#endif
