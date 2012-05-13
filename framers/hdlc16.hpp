#ifndef FRAMER_HDLC16_HPP
#define FRAMER_HDLC16_HPP

#include "../streams/frames/reader.hpp"
#include "../streams/bits/writer.hpp"

#include <vector>
namespace framers
	{
	class hdlc16: public bits::writer, public frames::reader
		{
		public:
			void insert( const frames::buffer & );
		private:
			void encoder_insert( bool bit );
			int num_contig_ones;
			size_t output_cnt;
			std::vector<bool> bitbuf;
		};
	}
#endif
