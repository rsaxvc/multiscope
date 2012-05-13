#ifndef BITSTREAM_READER_HPP
#define BITSTREAM_READER_HPP

#include "buffer.hpp"

namespace bits
	{
	class reader
		{
		public:
			virtual void insert( const buffer & );
		};
	}
#endif
