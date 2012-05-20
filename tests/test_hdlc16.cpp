#include <cstring>
#include <iostream>
#include "framers/hdlc16.hpp"
#include "deframers/hdlc16.hpp"
#include "outputs/stdout/frame.hpp"
#include "outputs/stdout/frame_hex.hpp"

static const char msg[]="If you can read this twice, the frame was printed once, and framed/deframed/printed once.";

static void run_loopback_test()
{
frames::frame the_frame;
for( size_t i = 0; i < strlen(msg); ++i )
	{
	the_frame.push_back( msg[i] );
	}
frames::buffer the_buffer;
the_buffer.push_back( the_frame );

framers::hdlc16 framer;
deframers::hdlc16 deframer;
output::stdout::frame frame_out;
output::stdout::frame_hex frame_hex_out;

framer.attach( deframer );
deframer.attach( frame_out );
deframer.attach( frame_hex_out );

framer.insert( the_buffer );

deframer.detach( frame_out );
deframer.detach( frame_hex_out );
framer.detach( deframer );
}

int main()
{
std::cout<<msg<<std::endl;
std::cout<<"And then we'll print it in hex"<<std::endl;
run_loopback_test();
return 0;
}
