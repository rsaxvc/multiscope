#ifndef BYTES_WRITER_HPP
#define BYTES_WRITER_HPP

#include "reader.hpp"

#include <list>

namespace bytes
	{
	class writer
		{
		public:
			void attach( reader & );
		private:
			void broadcast( const buffer & );
			std::list<reader*>registered;
		};
	}
#endif
