#ifndef BYTES_READER_HPP
#define BYTES_READER_HPP

#include <cstddef>

#include "buffer.hpp"

namespace bytes
	{
	class reader
		{
		public:
			virtual void insert( const buffer & );
		};
	}
#endif
