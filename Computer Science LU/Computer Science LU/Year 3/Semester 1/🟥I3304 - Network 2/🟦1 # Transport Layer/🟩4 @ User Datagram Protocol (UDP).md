_Next [[🟩5 @ Transmission Control Protocol (TCP)]]_
_Previous [[🟩3 @ Multiplexing & De-Multiplexing]]_

---
UDP is a bare bones internet transport protocol.
It is a _"best effort"_ service, i.e. it sends the message with the best connection but doesnt make sure it got received or something like that. Because of that, segments may be lost or delivered out of order to the app.

Theres no handshaking between UDP sender and receiver. _(Handshaking is sending a message requesting the receiver for connecting and the receiver acknowledging)_
And each  UDP segment handled independently of others.

UDP is used in:
- Streaming services, since they are loss tolerant and data transfer rate sensitive.
- [[DNS]]
- SNMP

However you can add functionality to the UDP in the application layer, this way you can take what you only need in the [[🟩5 @ Transmission Control Protocol (TCP)|TCP]] and implement it in the UDP.

## Segment Header
![[Pasted image 20230222175236.png|400]]

---

_Next [[🟩5 @ Transmission Control Protocol (TCP)]]_
_Previous [[🟩3 @ Multiplexing & De-Multiplexing]]_