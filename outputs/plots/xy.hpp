#ifndef OUTPUT_XYPLOT_HPP
#define OUTPUT_XYPLOT_HPP

#include "../../streams/samples/reader.hpp"

#include "plot.hpp"
namespace plots
	{
	class xy : public plot
		{
		std::string getName()const{return "XY";};
		double getXRes();
		double getYRes();
		};
	}
#endif
