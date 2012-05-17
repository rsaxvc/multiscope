#include "framers/hdlc16.hpp"
#include "crc/hdlc16.hpp"

#include <stdint.h>
#include <vector>
#include <ostream>
#include <cassert>

#define HDLC_FRAMER 0x7E
namespace framers
	{

	static inline bool get_bit( const frames::frame & buf, size_t bit_idx )
	{
	return ( buf[ bit_idx >> 3 ] >> ( bit_idx & 0x07 ) ) & 1;
	}

	std::ostream& operator<< (std::ostream& out, const hdlc16 & framer )
	{
	for( size_t i = 0; i < framer.bitbuf.size(); ++i )
		{
		out<< ( framer.bitbuf[i] ? 1 : 0);
		}
	return out;
	}

	void hdlc16::insert( const frames::buffer & buf )
	{
	crc::hdlc16 crc;
	uint8_t crc_hi;
	uint8_t crc_lo;

	assert( bitbuf.size() == 0 );

	for( frames::buffer::const_iterator frame_iterator = buf.begin(); frame_iterator != buf.end(); frame_iterator++ )
		{
		num_contig_ones = 0;

		/*add a frame marker, not computing CRC, not bitstuffing */
		for( size_t i = 0; i < 8; ++i )
			{
			bitbuf.push_back( ( HDLC_FRAMER >> i ) & 0x01 );
			}

		/*add the data, while computing CRC*/
		for( size_t i = 0; i < frame_iterator->size() * 8; ++i )
		    {
		    bool bit = get_bit( *frame_iterator, i );
			crc.insert( bit );
		    encoder_insert( bit );
		    }

		/*finish CRC and append (And bitstuff it)*/
		crc_lo = crc.emit() & 0xFF;
		crc_hi = crc.emit() >> 8;

		for( size_t i = 0; i < 8; ++i )
			{
			encoder_insert( ( crc_lo >> i ) & 1 );
			}

		for( size_t i = 0; i < 8; ++i )
			{
			encoder_insert( ( crc_hi >> i ) & 1 );
			}

		/*Tack on a frame marker, but don't bitstuff it nor compute crc*/
		for( size_t i = 0; i < 8; ++i )
			{
			bitbuf.push_back( ( HDLC_FRAMER >> i ) & 0x01 );
			}

		broadcast( bitbuf );
		bitbuf.clear();
		}
	}

	void hdlc16::encoder_insert( bool bit )
	{
	bitbuf.push_back( bit );
	if( bit == 1 )
		{
		num_contig_ones++;
		}
	else
		{
		num_contig_ones = 0;
		};

	if( num_contig_ones == 5 )
		{
		/*bit-stuff a 0 after 5 contiguous ones*/
		bitbuf.push_back( 0 );
		num_contig_ones = 0;
		}
	}
}
