#ifndef PLOT_POLAR_HPP
#define PLOT_POLAR_HPP

#include "plot.hpp"

namespace plots
	{
	class polar : public plot
		{
		std::string getName()const{return "polar";};
		double getRRes();
		};
	}
#endif
