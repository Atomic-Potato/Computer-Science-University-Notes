Flow control refers to a set of procedures used to restrict the amount of data that the sender can send before waiting for acknowledgment. (Controlled in the `Network Layer`)

# Protocols
## For noiseless Channels (Theoretical)
- `Simplest protocol:` a unidirectional protocol in which data frames are traveling in only one direction from the sender to receiver, assuming that the receiver can immediately handle the received frames 
![[Pasted image 20220714234245.png | 500]]
- `Stop and Wait Protocol:` To prevent the receiver from becoming overwhelmed with frames, the **sender** sends a frame and **waits for acknowledgment** from the **receiver** before sending the next frame.
![[Pasted image 20220714234502.png | 500]]

## For Noisy Channels
- `Stop and Wait ARQ:` In this method we keep a copy of the sent frame and retransmitting of the frame when a timer expires.
_We use sequence numbers to number the frames.  Sequence Number : $0 ~(2^m -1)\%2$, and then repeated_
When the frame arrives, an **acknowledgement** gets sent back to the sender
_The acknowledgement is the next number in the sequence_
![[Pasted image 20220714235221.png | 500]]
![[Pasted image 20220714235238.png | 400]]

- `Go-back N ARQ:` 
	In this method the sender sends multiple frames before receiving acknowledgement for the first one
	The number of frames that can be sent at once is decided using a **window**
	If  the **ack is not received** in a time period, then all the frames in the current window are **retransmitted**

	*Example:*
	![[Pasted image 20221002184135.png]]
	This processes can be described verbally like so *(Sf is the start of the window, Sn is the next frame, Sn-Sf <= window size)*:
		send 0 -- Sf=0, Sn=1
		send 1 -- Sf = 0, Sn = 2
		...
		receive ack1 -- Sf=1, Sn = 4
		...
	![[Pasted image 20221002153434.png | 600]]

- `Selective repeat ARQ:`
	![[Pasted image 20221002184624.png]]
### Bandwidth-delay product
Bandwidth-delay product is a measure of the number of bits we can send out of our system while waiting for news from the receiver.
$$\large \color{pink} Bandwidth\space delay \space product = Bandwidth(bits)*delay(seconds) \space time$$
(bandwidth delay product is in bits)
$$\large \color{purple}Utilization \space percentage \space of \space the \space link = \frac{frame \space length}{Bandwidth-delay \space product} * 100$$