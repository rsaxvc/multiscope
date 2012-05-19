#include <iostream>
#include "frame_hex.hpp"

namespace output
	{
	namespace stdout
		{
		void frame_hex::insert( const frames::buffer & buf )
			{
			//here we should save the stream flags
			std::cout<<std::hex;

			for( frames::buffer::const_iterator frame_iterator = buf.begin(); frame_iterator != buf.end(); frame_iterator++ )
				{
				for( frames::frame::const_iterator byte_iterator = frame_iterator->begin(); byte_iterator != frame_iterator->end(); byte_iterator++ )
					{
					std::cout<<(int)(*byte_iterator);
					}
				std::cout<<std::endl;
				}
			//here we should restore the stream flags
			}
		}
	}
