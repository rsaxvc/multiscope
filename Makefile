CFLAGS=-O0 -g -Wall
CXXFLAGS=$(CFLAGS)
LDFLAGS=
SOURCES=`ls *.cpp`
BUILDS=test_compile
all: .depend $(BUILDS)

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

test_compile:\
	test_compile.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

clean:
	rm -f *.o .depend $(BUILDS)
