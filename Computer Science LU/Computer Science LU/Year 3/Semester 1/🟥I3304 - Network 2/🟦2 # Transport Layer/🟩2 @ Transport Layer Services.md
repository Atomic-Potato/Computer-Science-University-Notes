_Next [[🟩3 @ Multiplexing & De-Multiplexing]]_
_Previous [[🟩1 @ ICMP & Trace Route]]_

---

![[Pasted image 20230222162651.png]]
![[Pasted image 20230222162830.png]]


The transport layer in a nutshell handles which application is sending and receiving the message/segment.

# Services & Protocols
Transport layer provides **logical communication** between application processes running on different hosts.

The **sender** breaks the application messages into segments, passes to network layer.
While the **receiver** reassembles segments into messages, passes to application layer

## Transport Protocols
There are 2 transport protocols available to Internet applications:
- `TCP:` Transmission Control Protocol: In a nutshell, it sends messages reliably, i.e. theres no data loss when the message is received:
	- Reliable, in-order delivery 
	- Congestion control
	- Flow control
	- Connection setup
- `UDP:` User Datagram Protocol: In a nutshell, it sends messages without waiting for acknowledgement, it used heavily in real-time data transfer:
	- Unreliable, unordered delivery
	- No-frills extension of “best-effort” IP

---
_Next [[🟩3 @ Multiplexing & De-Multiplexing]]_
_Previous [[🟩1 @ ICMP & Trace Route]]_