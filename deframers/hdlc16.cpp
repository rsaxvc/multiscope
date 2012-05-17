#include "deframers/hdlc16.hpp"
#include "crc/hdlc16.hpp"

#include <stdint.h>
#include <vector>
#include <cassert>
#include <climits>

#define HDLC_FRAMER 0x7E
namespace deframers
	{

	void hdlc16::insert( const bits::buffer & buf )
	{
	for( size_t i = 0; i < buf.size(); ++i )
		{
		insert_bit( buf[i] );
		}
	}

	void hdlc16::reset( void )
	{
	last_8_bits = 0;
	num_contig_ones = 0;
	bitlocked = false;
	bitbuf.clear();
	}

	bool hdlc16::valid_frame( void )
	{
	size_t bitcnt = bitbuf.size();
	//this can be extended to work for odd HDLC bitframes later
	if( bitcnt % 8 != 0 )
		{
		return false;
		}
	if( bitcnt < 32 )
		{
		return false;
		}
	if( last_8_bits != HDLC_FRAMER )
		{
		return false;
		}
	if( !valid_crc() )
		{
		return false;
		}
	return true;
	}

	void hdlc16::insert_bit( bool bit )
	{
	assert( bit == 0 || bit == 1 );

	last_8_bits = ( last_8_bits << 1 ) | ( bit & 1 );

	if( num_contig_ones == 5 && bit == 0 )
		{
		/*skip stuffed bit*/
		}
	else
		{
		if( bitlocked )
			{
			bitbuf.push_back( bit );
			if( bitbuf.size() > 24 )
				{
				//only insert from 24 bits back
				//this skips the frame CRC(16bit),
				//and skips the end framer byte(8bit)
				crc.insert( bitbuf[ bitbuf.size() - 25 ] );
				}
			}

		if( valid_frame() )
			{
			frames::frame frame = emit_frame();
			frames::buffer buffer;

			buffer.push_back( frame );

			broadcast( buffer );
			}

		if( last_8_bits == HDLC_FRAMER )
			{
			bitbuf.clear();
			bitlocked = true;
			}
		}

	if( bit == 1 )
		{
		num_contig_ones++;
		}
	else
		{
		num_contig_ones = 0;
		}
	}

	frames::frame hdlc16::emit_frame()
	{
	frames::frame retn;

	assert( bitbuf.size() % 8 == 0 );
	assert( bitbuf.size() >= 32 );

	//pack the bits into a buffer, but skip the last three bytes(CRC16+framer)
	for( size_t i = 0; i < bitbuf.size() - ( 3 * 8 ); i+=CHAR_BIT )
		{
		uint8_t accum = 0;
		for( size_t j = CHAR_BIT; j >= 1; --j )
			{
			accum <<= 1;
			accum += bitbuf[ i+j-1 ];
			}
		retn.push_back( accum );
		}
	return retn;
	}

	bool hdlc16::valid_crc()
	{
	uint16_t my_crc;
	uint16_t their_crc;

	assert( bitbuf.size() % 8 == 0 );
	assert( bitbuf.size() >= 32 );

	if( bitbuf.size() >= 32 )
		{
		size_t sz = bitbuf.size();
		my_crc = crc.emit();
		their_crc =
			bitbuf[ sz -  9 ] << 15 |
			bitbuf[ sz - 10 ] << 14 |
			bitbuf[ sz - 11 ] << 13 |
			bitbuf[ sz - 12 ] << 12 |
			bitbuf[ sz - 13 ] << 11 |
			bitbuf[ sz - 14 ] << 10 |
			bitbuf[ sz - 15 ] <<  9 |
			bitbuf[ sz - 16 ] <<  8 |
			bitbuf[ sz - 17 ] <<  7 |
			bitbuf[ sz - 18 ] <<  6 |
			bitbuf[ sz - 19 ] <<  5 |
			bitbuf[ sz - 20 ] <<  4 |
			bitbuf[ sz - 21 ] <<  3 |
			bitbuf[ sz - 22 ] <<  2 |
			bitbuf[ sz - 23 ] <<  1 |
			bitbuf[ sz - 24 ] <<  0 ;
		return my_crc == their_crc;
		}
	return false;
	}

}
