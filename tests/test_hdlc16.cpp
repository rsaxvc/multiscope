#include <cstring>
#include <iostream>
#include "framers/hdlc16.hpp"
#include "deframers/hdlc16.hpp"
#include "outputs/stdout/frame.hpp"

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
output_stdout::frame frame_out;

framer.attach( deframer );
deframer.attach( frame_out );

framer.insert( the_buffer );

deframer.detach( frame_out );
framer.detach( deframer );
}

int main()
{
std::cout<<msg<<std::endl;
run_loopback_test();
return 0;
}
