#ifndef SAMPLE_WRITER_HPP
#define SAMPLE_WRITER_HPP

#include "buffer.hpp"
#include "reader.hpp"

#include <list>

namespace samples
	{
	class writer
		{
        public:
			~writer();
            void attach( reader & );
            void detach( reader & );
        protected:
            std::list<reader*> registered;
            void broadcast( const buffer & );
		};
	}
#endif
