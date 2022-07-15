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

### Bandwidth-delay product
Bandwidth-delay product is a measure of the number of bits we can send out of our system while waiting for news from the receiver.
$$\large \color{pink} Bandwidth-delay \space product = Bandwidth*delay \space time$$
$$\large \color{purple}Utilization \space percentage \space of \space the \space link = \frac{frame \space length}{Bandwidth-delay \space product} * 100$$