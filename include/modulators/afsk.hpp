#ifndef MODULATOR_AFSK_HPP
#define MODULATOR_AFSK_HPP

#include "../streams/bits/reader.hpp"
#include "../streams/samples/writer.hpp"

namespace modulator
	{
	class afsk : public bits::reader, public samples::writer
		{
		afsk( double freq_a, double freq_b, double baud_rate );
		};
	}

#endif
