#ifndef FILTERS_EXPONENTIAL_SMOOTHER_HPP
#define FILTERS_EXPONENTIAL_SMOOTHER_HPP

#include "filter.hpp"

//A low-pass filter

namespace filters
	{
	class exponential_smoother : public filter
		{
		public:
			exponential_smoother(double the_ratio);
			void insert( const samples::buffer & buf );
		private:
			void insert_sample( double sample );
			double ratio;
			double residue;
			bool init;
		};
	}

#endif
