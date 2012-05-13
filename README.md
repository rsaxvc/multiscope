multiscope
==========

**current stage**: lofty pipe dream absorbing time until the idea is more concrete

**What it should do:**

The idea is to abstract the various i/o formats (discrete-analog-samples-stream, bit-stream, byte-stream, frame-stream)
so that pluggable modules can be created easily.

At work, sometimes I deal with various specialized pieces of equipment, from spectrum-analysers and AM/FM test-kits, to modulator units.
For the most part, it seems like everything I needed could easily run on a desktop, given an appropriate sampler unit (Keep in mind,
I was doing fairly low-bandwidth stuff), instead of daisy-chaining tools together.

*Radio tools and testing*
Ideally, you should be able to construct a simple AX.25 radio receiver using the following modules:
	tunable FM radio for the 2-meter band(pure analog device, takes in FM, outputs analog audio)
	sound card for audio-sampling(multiscope software driver)
	afsk demodulator(multiscope software)
	nrzi decoder(multiscope software)
	hdlc16 deframer(multiscope software)
But not only would you have a radio, you could inspect the intermediate forms at each layer. This would've been very useful for me
when building an AX.25 receiver, to have something to compare results against.

*Spectrum Analyser*
A spectrum analyser is a tool that plots power-distribution over frequency range for a given signal. Effectively, it plots a
fast fourier transform in realtime.

*An oscilloscope*
An oscilloscope is a tool for plotting a signal over time. Many scopes can plot two signals against each other.
Multiscope should be able to do this in near-realtime, at least for slower sample-rates.

**potential challenges**
*Latency*
Since a user could be viewing different signals on the display at the same time, multiscope
may need some concept of time instead of just blit-the-dots as quickly as possible. Especially as 
the different signals can be derived from the same input. Ex, viewing AFSK bits and the audio
samples that made them.

*Throughput*
certain tasks, like QAM demodulation, require a fair amount of processing, and
currently are done using ASICs or FPGAs for high-density datastreams. Hopefully, it may
prove possible to offload some of these tasks to tools like GNU-software-defined-radio and
other tools.

*Configurability*
Users should be able to make their own plugins, and it shouldn't be terribly hard.
Additionally, users should be able to modify the pipeline quickly at runtime.
The display should probably state what each channel is measuring.
