#ifndef MODULATOR_BPSK_HPP
#define MODULATOR_BPSK_HPP

#include "../streams/bits/reader.hpp"
#include "../streams/samples/writer.hpp"

namespace modulator
	{
	class bpsk : public bits::reader, public samples::writer
		{
		bpsk( double freq_a, double freq_b, double baud_rate );
		};
	}


#endif
