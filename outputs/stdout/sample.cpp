#include <iostream>
#include "sample.hpp"

namespace output
	{
	namespace stdout
		{
		void sample::insert( const samples::buffer & buf )
			{
			for( size_t i = 0; i < buf.num_samples; ++i )
				{
				std::cout<<buf[i]<<std::endl;
				}
			}
		}
	}
