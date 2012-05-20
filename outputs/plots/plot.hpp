#ifndef PLOT_PLOT_HPP
#define PLOT_PLOT_HPP

#include "streams/samples/reader.hpp"

namespace plots
	{
	class plot
		{
		public:
			virtual std::string getName()const;
		};
	}
#endif
