#include <iostream>
#include "frame.hpp"

namespace output_stdout
	{
	void frame::insert( const frames::buffer & buf )
		{
		for( frames::buffer::const_iterator frame_iterator = buf.begin(); frame_iterator != buf.end(); frame_iterator++ )
			{
			for( frames::frame::const_iterator byte_iterator = frame_iterator->begin(); byte_iterator != frame_iterator->end(); byte_iterator++ )
				{
				std::cout<<(char)(*byte_iterator);
				}
			std::cout<<std::endl;
			}
		}
	}
