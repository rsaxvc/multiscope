#ifndef FRAMES_READER_HPP
#define FRAMES_READER_HPP

#include <cstddef>

#include "buffer.hpp"

namespace frames
	{
	class reader
		{
		public:
			virtual void insert( const buffer & )=0;
		};
	}
#endif
