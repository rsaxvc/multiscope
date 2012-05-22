CC=gocache gcc
CXX=gocache g++
CFLAGS=-O0 -g -Wall -I . -Wall -Wextra
CXXFLAGS=$(CFLAGS)
LDFLAGS=
SOURCES=`find . | grep "\.cpp"`
TESTS=test_compile test_hdlc16 test_squarewave test_sinewave
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
	outputs/stdout/frame.o\
	outputs/stdout/frame_hex.o
	$(CXX) -o $@ $(LDFLAGS) $^

test_sinewave:\
	tests/test_sinewave.o\
	samplers/oscillator.o\
	samplers/sinewave.o\
	streams/samples/buffer.o\
	streams/samples/writer.o\
	outputs/stdout/sample.o
	$(CXX) -o $@ $(LDFLAGS) $^

test_squarewave:\
	tests/test_squarewave.o\
	samplers/oscillator.o\
	samplers/squarewave.o\
	streams/samples/buffer.o\
	streams/samples/writer.o\
	outputs/stdout/sample.o
	$(CXX) -o $@ $(LDFLAGS) $^

test_compile:\
	deframers/hdlc16.o\
	downsamplers/nearest.o\
	filters/exponential_smoother.o\
	framers/hdlc16.o\
	outputs/stdout/frame.o\
	outputs/stdout/frame_hex.o\
	outputs/stdout/sample.o\
	samplers/oscillator.o\
	samplers/sinewave.o\
	samplers/squarewave.o\
	streams/bits/writer.o\
	streams/bytes/writer.o\
	streams/frames/writer.o\
	streams/samples/buffer.o\
	streams/samples/writer.o\
	tests/test_compile.o
	$(CXX) -o $@ $(LDFLAGS) $^

clean:
	rm -f .depend $(BUILDS) `find . | grep "\.o"`
