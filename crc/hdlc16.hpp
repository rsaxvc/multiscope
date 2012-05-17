#ifndef CRC_HDLC16_HPP
#define CRC_HDLC16_HPP

#include <stdint.h>

namespace crc
	{
	class hdlc16
		{
		public:
			hdlc16()
				{
				reset();
				}

			void insert( bool bit )
				{
				bool underflow = state & 1;
				state >>= 1;
				if( underflow != bit )
					{
					state ^= 0x8408;
					}
				}

			uint16_t emit( void )
				{
				return state ^ 0xFFFF;
				}

			void reset( void )
				{
				state = 0xFFFF;
				}
		private:
			uint16_t state;
		};
	}

#endif
