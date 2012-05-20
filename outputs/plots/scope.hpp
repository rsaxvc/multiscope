#ifndef PLOT_SCOPE_HPP
#define PLOT_SCOPE_HPP

#include "plot.hpp"

namespace plots
	{
	class scope : public plot
		{
		public:
			std::string getName()const;
		};
	}

#endif
