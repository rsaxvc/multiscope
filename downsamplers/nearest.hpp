#ifndef DOWNSAMPLERS_NEAREST_HPP
#define DOWNSAMPLERS_NEAREST_HPP

#include "downsampler.hpp"

namespace downsamplers
	{
	class nearest : public downsampler
		{
		public:
			nearest(int the_rate):current(0),rate(the_rate){}
			void insert( const samples::buffer & buf );
		private:
			int current;//counts how many before we need to keep one
			int rate;//keep a sample this often
		};
	}

#endif
