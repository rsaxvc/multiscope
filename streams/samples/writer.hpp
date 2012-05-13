#ifndef SAMPLE_WRITER_HPP
#define SAMPLE_WRITER_HPP

#include "buffer.hpp"
#include "reader.hpp"

namespace samples
	{
	class writer
		{
        public:
            void attach( reader & );
        private:
            std::list<reader*> registered;
            void broadcast( const buffer & );
		};
	}
#endif
