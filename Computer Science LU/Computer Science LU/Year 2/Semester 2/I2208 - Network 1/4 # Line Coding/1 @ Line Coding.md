# Digital-to-Digital Conversion
Converts sequence of bits to a digital signal
![[Pasted image 20220706163924.png | 500]]

Although the actual [[2 @ Periodic Signals#^bandwidth|bandwidth]] of a digital signal is `infinite`, the effective bandwidth is `finite`.
*A digital signal that carries information is nonperiodic. So, bandwidth of nonperiodic signal is continuous with an infinite range theoretically.*

# Self-Synchronization
Receiver’s bit intervals must correspond exactly to the sender’s bit intervals
Self-synchronizing signal includes timing information
If the receiver’s clock is out of synchronization, these alerting points can reset the clock.

Effect of lack of sync:
![[Pasted image 20220706164347.png | 400]]

A good encoded digital signal must contain a provision for synchronization (clock extraction)
Frequent transitions in the signal is needed to extract the clock