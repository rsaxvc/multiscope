#ifndef FRAMER_SIXPACK_HPP
#define FRAMER_SIXPACK_HPP

#include "../streams/frames/reader.hpp"
#include "../streams/bytes/writer.hpp"

class sixpack: public frames::reader, public bytes::writer
	{
	};
#endif
