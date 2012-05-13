#ifndef FRAMES_WRITER_HPP
#define FRAMES_WRITER_HPP

#include "reader.hpp"

#include <list>

namespace frames
	{
	class writer
		{
		public:
			void attach(reader&);
		private:
			std::list<reader*>registered;
			void broadcast( const buffer & );
		};
	}
#endif
