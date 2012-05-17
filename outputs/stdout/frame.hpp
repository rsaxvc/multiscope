#ifndef OUTPUT_STDOUT_FRAME_HPP
#define OUTPUT_STDOUT_FRAME_HPP

#include "../../streams/frames/reader.hpp"

namespace output_stdout
	{
	class frame: public frames::reader
		{
		public:
			void insert( const frames::buffer & );
		};
	}
#endif
