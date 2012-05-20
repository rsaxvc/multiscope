#include <cstring>
#include <iostream>
#include "samplers/sinewave.hpp"
#include "outputs/stdout/sample.hpp"

static void run_test( double amplitude )
{
std::cout<<"You should see a sinewave of amplitude:"<<amplitude<<std::endl;

samplers::sinewave sinwave(samples::F32, amplitude, 3.1415/10);
output::stdout::sample sampleout;

sinwave.attach( sampleout );
for( size_t i = 0; i < 30; ++i )
	{
	sinwave.emit();
	}
sinwave.detach( sampleout );
}

int main()
{
run_test(10);
return 0;
}
