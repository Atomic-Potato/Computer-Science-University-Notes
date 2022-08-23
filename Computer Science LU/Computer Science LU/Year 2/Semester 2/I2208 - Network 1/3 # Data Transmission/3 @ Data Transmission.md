`Bit rate:` how many bits we can transmit per second
# Data Signals
In addition to being represented by an analog signal, information can also be represented by a `digital signal`. 
For example, a 1 can be encoded as a positive voltage and a 0 as zero voltage.
A digital signal can have more than two levels. In this case, we can send more than 1 bit for each level.
![[Pasted image 20220705134432.png | 350]]
**To calculate the number of bits per lever we use this formula:** $\large log_2(totla\space levels)$

- Time and frequency domains of periodic and non periodic digital signals:
![[Pasted image 20220705140340.png | 500]]

# Transmission impairment
Three causes of impairment are `attenuation`, `distortion`, and `noise`.

## Attenuation
`Attenuation` **means a loss of energy.**
When a signal, simple or composite, travels through a medium, it loses some of its energy in overcoming the resistance of the medium.
That is why a wire carrying electric signals gets warm, if not hot.
Some of the electrical energy in the signal is converted to heat.
![[Pasted image 20220705140933.png | 500]]

**To calculate the attenuation (loss of power) we use the following formula:**
$$\large 10*log_{10}(\frac{P_2}{P_1})$$
Where $P_2$ is the received signal and $P_1$ is the originally sent signal (i think it should be in watt, so make sure to convert to that)
- `Some notes:`
	- The result is in decibel
	- $\large 10log_{10}$ converts the input to decibel

### Decibels `dB`
One reason that engineers use the decibel to measure the changes in the strength of a signal is that decibel numbers can be added (or subtracted) when we are measuring several points (cascading) instead of just two.

In the next Figure a signal travels from point 1 to point 4.
![[Pasted image 20220705141631.png | 500]]

In this case, the decibel value can be calculated as: $\large dB = -3+7-3=+1$

## Distortion
Distortion happens due to limited [[2 @ Periodic Signals#^bandwidth|bandwidth]]
![[Pasted image 20220705162651.png | 500]]

## Noise
Basically some external frequency acting on the internal frequency
![[Pasted image 20220705162710.png | 500]]

### Signal to noise ratio (SNR)
To get this ratio we use the following formula:
$$SNR = \frac{power \space of \space signal}{power \space of \space noise}$$
To convert to decibel:
$$10log_{10}(SNR)$$

The values of `SNR` and `SNRdB` for a noiseless channel are
![[Pasted image 20220706124639.png]]

*Examples of high SNR and low SNR:*
![[Pasted image 20220706124714.png | 300]]

# Data Rate Limits
A very important consideration in data communications is how fast we can send data, in bits per second, over a channel. 
Data rate depends on three factors:
-  The [[2 @ Periodic Signals#^bandwidth|bandwidth]] available
- The level of the signals we use
-  The quality of the channel (the level of noise)

## Noiseless channel: Nyquist `bit rate`
The maximum theoretical `bit rate` can be calculated as follows:
$$\large Bit \space Rate = 2*Bandwidth*log_2(L)$$
Where `L` is the number of [[3 @ Data Transmission#Data Signals|signal levels]] used to represent data (The result is in **bps**)

## Noiseless channel: Shannon `capacity`
The maximum theoretical `data rate / capacity` for a noisy channel can be calculated as follows:
$$\large C = B*log_2(1+SNR)$$
Where `B` is the `bandwidth` (The result is in **bps**)

# Calculation notes
- Units to smallen the results
![[table-bits-bytes-k-m-g-t.png | 500]]
	Milli: $/ 1000$
- To convert back from `dB` to `Hz` 
	- we divide by 10 
	- Raise 10 to the power of the result
	![[Pasted image 20220706131129.png]]

- To calculate $\large log_n$ on an old calculator you do the following equation$$\large log(a)*log(n)$$
where `a` is the number you want to find the log to, and `n` is the base