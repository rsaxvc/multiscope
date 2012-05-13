#ifndef BITSTREAM_WRITER_HPP
#define BITSTREAM_WRITER_HPP

#include <list>
#include <vector>
#include "reader.hpp"

namespace bits
	{
	class writer
		{
		public:
			void attach( reader & );
		protected:
			std::list<reader*> registered;
			void broadcast( const std::vector<bool> & );
		};
	}
#endif
