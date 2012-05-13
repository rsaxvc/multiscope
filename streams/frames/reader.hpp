#ifndef FRAMES_READER_HPP
#define FRAMES_READER_HPP

#include <cstddef>

#include "buffer.hpp"

namespace frames
	{
	class reader
		{
		public:
			void insert( const buffer & );
		};
	}
#endif
