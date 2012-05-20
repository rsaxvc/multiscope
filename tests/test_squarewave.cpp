#include <cstring>
#include <iostream>
#include "samplers/squarewave.hpp"
#include "outputs/stdout/sample.hpp"

static const char msg[]="If you can read this twice, the frame was printed once, and framed/deframed/printed once.";

static void run_test( double amplitude )
{
std::cout<<"You should see a squarewave of amplitude:"<<amplitude<<std::endl;

samplers::squarewave sqwave(samples::S16, amplitude, 3.1415/3);
output::stdout::sample sampleout;

sqwave.attach( sampleout );
for( size_t i = 0; i < 10; ++i )
	{
	sqwave.emit();
	}
sqwave.detach( sampleout );
}

int main()
{
run_test(10);
return 0;
}
