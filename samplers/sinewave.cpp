#include "sinewave.hpp"

#include <cmath>

namespace samplers
	{
	void sinewave::emit()
		{
		emit_sample( amplitude * sin( idx++ * frequency ) );
		};
	}
