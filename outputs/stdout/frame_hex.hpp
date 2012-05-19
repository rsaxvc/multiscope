#ifndef OUTPUT_STDOUT_FRAME_HEX_HPP
#define OUTPUT_STDOUT_FRAME_HEX_HPP

#include "../../streams/frames/reader.hpp"

namespace output
	{
	namespace stdout
		{
		class frame_hex: public frames::reader
			{
			public:
				void insert( const frames::buffer & );
			};
		}
	}
#endif
