#ifndef MODULATOR_GMSK_HPP
#define MODULATOR_GMSK_HPP

#include "../streams/bits/reader.hpp"
#include "../streams/samples/writer.hpp"

namespace modulator
	{
	class gmsk : public bits::reader, public samples::writer
		{
		};
	}

#endif
