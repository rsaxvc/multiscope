CFLAGS=-O0 -g -Wall -I .
CXXFLAGS=$(CFLAGS)
LDFLAGS=
SOURCES=`find . | grep "\.cpp"`
TESTS=test_compile
BUILDS=$(TESTS)
all: .depend $(BUILDS)

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

test_compile:\
	tests/test_compile.o\
	framers/hdlc16.o\
	streams/bytes/writer.o\
	streams/bits/writer.o
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^

clean:
	rm -f .depend $(BUILDS) `find . | grep "\.o"`
