CFLAGS=-O0 -g -Wall -I .
CXXFLAGS=$(CFLAGS)
LDFLAGS=
SOURCES=`find . | grep "\.cpp"`
TESTS=test_compile test_hdlc16
BUILDS=$(TESTS)
all: .depend $(BUILDS)

.depend:
	fastdep $(SOURCES) > .depend

-include .depend

test_hdlc16:\
	tests/test_hdlc16.o\
	framers/hdlc16.o\
	deframers/hdlc16.o\
	streams/bits/writer.o\
	streams/frames/writer.o\
	outputs/stdout/frame.o
	$(CXX) -o $@ $(LDFLAGS) $^

test_compile:\
	deframers/hdlc16.o\
	downsamplers/nearest.o\
	framers/hdlc16.o\
	outputs/stdout/frame.o\
	streams/bits/writer.o\
	streams/bytes/writer.o\
	streams/frames/writer.o\
	streams/samples/writer.o\
	tests/test_compile.o
	$(CXX) -o $@ $(LDFLAGS) $^

clean:
	rm -f .depend $(BUILDS) `find . | grep "\.o"`
