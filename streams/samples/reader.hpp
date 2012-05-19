#ifndef SAMPLE_READER_HPP
#define SAMPLE_READER_HPP

#include "buffer.hpp"

namespace samples
	{
	class reader
		{
		public:
			virtual void insert( const buffer & )=0;
		};
	}
#endif
