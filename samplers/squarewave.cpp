#include "squarewave.hpp"

#include <cmath>

namespace samplers
	{
	void squarewave::emit()
		{
		emit_sample( sin( idx++ * frequency ) > 0 ? amplitude : -amplitude );
		};
	}
