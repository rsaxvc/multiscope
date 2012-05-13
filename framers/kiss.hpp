#ifndef FRAMER_KISS_HPP
#define FRAMER_KISS_HPP

#include "../streams/frames/reader.hpp"
#include "../streams/bytes/writer.hpp"

class kiss: public frames::reader, public bytes::writer
	{
	};
#endif
