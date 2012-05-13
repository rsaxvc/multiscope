#ifndef FRAMES_BUFFER_HPP
#define FRAMES_BUFFER_HPP

#include <vector>

namespace frames
	{
	typedef std::vector<unsigned char> frame;
	typedef std::vector<frame> buffer;
	}

#endif
