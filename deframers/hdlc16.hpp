#ifndef DEFRAMER_HDLC16_HPP
#define DEFRAMER_HDLC16_HPP

#include "../streams/frames/writer.hpp"
#include "../streams/bits/reader.hpp"
#include "../crc/hdlc16.hpp"

#include <vector>
namespace deframers
	{
	class hdlc16: public bits::reader, public frames::writer
		{
		public:
			void insert( const bits::buffer & );
			hdlc16(){reset();}
		private:
			void reset( void );
			bool valid_frame( void );
			void insert_bit( bool bit );
			bool valid_crc( void );
			frames::frame emit_frame();

			bool bitlocked;
			uint8_t num_contig_ones;
			uint8_t last_8_bits;
			crc::hdlc16 crc;
			std::vector<bool> bitbuf;
		};
	}
#endif
