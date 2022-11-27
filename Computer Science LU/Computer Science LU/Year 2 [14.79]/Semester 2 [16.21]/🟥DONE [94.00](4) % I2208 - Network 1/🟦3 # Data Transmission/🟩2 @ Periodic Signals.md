Periodic analog signals can be classified as `simple` or `composite`.

A simple periodic analog signal, **a sine wave**, cannot be decomposed into `simpler` signals. ^simpleSignal

A `composite` periodic analog signal is composed of multiple sine waves. ^compositeSignal

# Amplitude, Frequency and Phase
All signals are composed of 3 properties:
- `Peak Amplitued (A):` maximum strength of signal (Typically measured in volts) ^amplitude

![[Pasted image 20220705131447.png | 300]]
- `Frequency (f):` rate at which the signal repeats (in other words, frequency is the rate of change with respect to
time.) 
	![[Pasted image 20220705131624.png | 300]]^frequency
- `Hertz (Hz)` or cycles per second ^hertzHz
- `period (T)` is the amount of time for one repetition **`(T = 1/f)`** ^period
	-  **Frequency** and **period** are the inverse of each other.
	![[Pasted image 20220705131546.png | 200]]
- `Pahse (sigma):` describes the position of the waveform relative to time Zero. ^phase

**Animation about signal:** https://phet.colorado.edu/sims/html/wave-on-a-string/latest/wave-on-a-string_en.html

## Units of period and frequency
![[Pasted image 20220705131701.png]]

## Extra notes
- If a signal does not change at all, its frequency is zero. If a signal changes instantaneously, its frequency is infinite.
- in a non periodic signal
	- if a signal is infinite in time, then its finite in frequency
	- if a signal is infinite in frequency, then its finite in time
# Frequency domain
![[Pasted image 20220705132347.png | 500]]

## [[🟩2 @ Periodic Signals#^compositeSignal|Composite Analog Signals (cont.)]]
- Composite signal sent at one end of transmission medium, **may not be received in the same form at the other end**
	For example, passing a square wave through any medium will **always** deform the signal
	![[Pasted image 20220705132930.png]]

- `Channel Bandwidth:` range of frequencies passed by the channel *(difference between highest and lowest frequency that channel can allow to pass)* 
	The bandwidth of periodic and non periodic composite signals:
	![[Pasted image 20220705134010.png | 350]]^bandwidth
## Frequency domain and time domain
The frequency domain is more compact and useful when we are dealing with more than one sine wave. For example, The Figure shows three sine waves, each with different amplitude and frequency. All can be represented by three spikes in the frequency domain.
![[Pasted image 20220705133306.png | 500]]

# Fourier series for periodic continuous signals
According to Fourier analysis, any [[🟩2 @ Periodic Signals#^compositeSignal|composite]] signal is a combination of simple sine waves with different frequencies, amplitudes, and phases.

`Note that you dont need to memorize this`
Any periodic signal x(t) of period T and repetition frequency f 0 (f 0 = 1/T) can be represented as an infinite sum of sinusoids of different frequencies and amplitudes – its Fourier Series. Expressed in Two forms:
- The sine/cosine form:
![[Pasted image 20220705133717.png | 500]]

If the composite signal is `periodic`, the decomposition gives a series of signals with discrete frequencies;
![[Pasted image 20220705133839.png | 500]]

if the composite signal is `nonperiodic`, the decomposition gives a combination of sine waves with continuous frequencies
![[Pasted image 20220705133937.png | 500]]

