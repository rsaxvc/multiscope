#ifndef OUTPUT_STDOUT_SAMPLE_HPP
#define OUTPUT_STDOUT_SAMPLE_HPP

#include "../../streams/samples/reader.hpp"

namespace output
	{
	namespace stdout
		{
		class sample: public samples::reader
			{
			public:
				void insert( const samples::buffer & );
			};
		}
	}
#endif
