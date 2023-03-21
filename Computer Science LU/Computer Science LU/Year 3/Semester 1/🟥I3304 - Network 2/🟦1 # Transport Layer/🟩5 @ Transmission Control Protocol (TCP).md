_Previous [[🟩4 @ User Datagram Protocol (UDP)]]_

---
![[Pasted image 20230222175518.png]]

# Segment Structure
![[Pasted image 20230222175700.png]]

# Sequence Numbers & ACKs
TCP splits data into a sequence of segments while identifying each part of the segment with a sequence number which is the byte where the part starts _(idk how to explain it, just look at the picture)_ 
![[Pasted image 20230222180944.png|1080]]
![[Pasted image 20230222181323.png|300]]

## ACKs
Acknowledgements are the sequence number of the next byte expected from the other side.

Acknowledgements are best explained in the following image: _(pay attention to the data length)_
![[Pasted image 20230222184639.png|600]]

![[Pasted image 20230222185010.png|400]]

**_Note:_** TCP doesnt handle out of order segments on the receiver end, its up to the implementer _(on the sending side i assume)_

# 3-Way Handshake
Before the TCP starts sending data, it should first establish a connection with the server so it would allocate a buffer to hold the data received from the host.
![[Pasted image 20230222190000.png]]

The steps:
1. client host sends TCP SYN segment to server:
	- specifies initial sequence number
	- no data is sent
2. server host receives SYN, replies with SYNACK segment: 
	- server allocates buffers
	- specifies server initial sequence number
3. client receives SYNACK, replies with ACK segment, which may contain data

**_Note:_** The reason why the sequence number / ack number starts with x / y _(the actual sequence number is added to x/y i think)_ instead of 0, is for security reasons so no harmful data can be sent from an outside source with the same sequence / ack number.

btw this is where the SYNACK and SYN are in the segment:
![[Pasted image 20230222191312.png]]

# Closing a TCP connection
When data transfer is complete, each side close their side of connection by sending a TCP segment with `FIN` bit = 1, and respond to received `FIN` with `ACK`
![[Pasted image 20230223130457.png]]

The steps:
1. client end system sends TCP FIN control segment to server
2. server receives FIN, replies with ACK. Closes connection, sends FIN.
3. client receives FIN, replies with ACK. _Enters “timed wait” - will respond with ACK to received FINs_
4. server, receives ACK. Connection closed.

# TCP Flow Control
Both the receiver and sender have a buffer for storing data before moving it to the application layer.

![[Pasted image 20230223131540.png]]

In a nutshell, the sender sends an amount of data less than the `rwnd` _(free buffer space)_ at the receiver. With it also they send how much free space in the buffer of sender there is. 
_Same process for the receiver._

# TCP Congestion Control
Congestion happens when too many networks are sending too much data too fast for the **network _(not the receiver, but the whole network, like a road system)_** to handle. _(This is different from flow control!!)_
Because of this, the receiver will drop packets and it will result in a delay.

## How to handle congestion
To control congestions sender increases transmission rate _(`cwnd`: congestion window size)_, probing for usable bandwidth, until loss occurs:
- **Additive increase:** increase `cwnd` by 1 `MSS` _(Maximum segment size)_ every `RTT` _(Round Trip Time)_ until a data loss is detected.
- **Multiplicative decrease:** cut `cwnd` in half after data loss.

![[Pasted image 20230223142352.png|400]]
![[Pasted image 20230223142457.png|300]]

**TCP sending rate:** roughly send `cwnd` bytes, wait `RTT` for `ACKS`, then send more bytes.
$$rate \approx \frac{cwnd}{RTT} \space bytes/sec$$

## Flow control window OR Congestion control window?
The window size at the sender is set as follows:
```c
Send Window = MIN(flow control window, congestion window)
```

`Flow control window` is advertised by the receiver.
`Congestion window` is adjusted based on feedback from the network.

## Slow Start
At the start, `cwnd = 1 segment` _(**NOTE:** `cwnd` is actually measured in bytes, 1 segment = 1 `MSS` bytes)_

Each time an `ACK` is received, the congestion window is increased by `MSS` bytes:
$$cwnd = cwnd + MSS$$
Things to note when increasing the `cwnd`:
- If an `ACK` acknowledges 2 segments, `cwnd` is still increased by only 1.
- Even if `ACK` acknowledges a segment that is smaller than `MSS` bytes long, `cwnd` is increased by `MSS`.

Because of this the increase of `cwnd` is exponential as you can see in the following example:
![[Pasted image 20230223145804.png|300]]

### ssthresh (Slow Start Threshold) & Congestion Avoidance
The increase of the `cwnd` is exponential until it passes the `ssthresh` where it becomes more linear, this is where we start **congestion avoidance**. So instead we increase `cwnd` with the following formula:
$$cwnd = cwnd + MSS\left( \frac{MSS}{cwnd} \right)$$
![[Pasted image 20230223145804.png|300]]

This is done so we can maximize how much data we can send without causing a congestion.

In summary heres the algorithm for congestion avoidance:
```c
if cwnd < ssthresh :
	Each time an ACK is received :
		cwnd = cwnd + MSS
else /*cwnd >= ssthresh*/
	Each time an ACK is received :
		cwnd = cwnd + MSS * (MSS / cwnd)
```

### Slow Start Example
![[Pasted image 20230223150535.png|700]]

## Detecting and reacting to loss
In the following image you can see at `t = 9` _(x axis)_ the `cwnd` dips down back to 1. This is when TCP detects / assumes theres a congestion at the receiver. 
![[Pasted image 20230223151248.png|400]]

### How do we detect congestion
There are 2 indications that a congestion has occurred:
- Timeout of a retransmission timer, i.e. `ACK` never received.
- Receipt of a duplicate `ACK`.

**What are duplicate `ACKs`?**
Say you have sent 3 segments at the same time:
- first is received and you get an `ACK=2` _(which means receiver is waiting for the second segment)_
- second is not received since you didnt get an `ACK=3`
- third is received and you get an `ACK=2` **again**. This means the second segment is lost and the receiver is still waiting for the second segment.

![[Pasted image 20230223152321.png|400]]
==Correction:== in the image the second ACK is ACK 2 not ACK 3

## Response to congestion detection
There are 2 methods for reacting:
- `TCP Tahoe:`
	Simply sets `cwnd` to1 
- `TCP Reno:`
  - **If duplicate `ACKs` are detected:** `cwnd` is cut in half and then it stars growing linearly _(you'll see why its linear in a sec)_
  - **If timeout is detected:** Simply sets `cwnd` to1

In either reaction **`ssthresh` is set to 1/2 of `cwnd`** just before loss event.

![[Pasted image 20230223151248.png|500]]

# Flow VS Congestion control
Flow control and congestion control are two mechanisms that work to manage the flow of data between communicating hosts in a network, but they have different objectives and operate at different layers of the network stack.

Flow control is a mechanism used to regulate the flow of data between two hosts in a network, typically between a sender and receiver. The purpose of flow control is to ensure that the receiver can handle the amount of data being sent by the sender. Flow control is typically implemented at the transport layer (e.g. TCP) and operates by using a sliding window protocol. The sender and receiver negotiate a window size, which represents the maximum amount of data that can be sent by the sender before waiting for an acknowledgment from the receiver. The sender will send data up to the window size and then wait for the receiver to acknowledge receipt of the data before sending more data. This helps to prevent the receiver from being overwhelmed with data it cannot handle.

Congestion control, on the other hand, is a mechanism used to prevent the network from becoming congested with too much traffic. Congestion can occur when too much data is being sent over the network, causing delays and packet loss. Congestion control is typically implemented at the network layer (e.g. in the IP protocol) and works by regulating the rate of data flow. Congestion control algorithms such as TCP's AIMD (Additive Increase, Multiplicative Decrease) adjust the sending rate based on network conditions, such as packet loss or delay. The algorithm will increase the sending rate when the network is not congested and decrease it when congestion is detected.

In summary, flow control is used to regulate the flow of data between a sender and receiver to ensure that the receiver can handle the data being sent, while congestion control is used to prevent the network from becoming congested with too much traffic.

---
_Previous [[🟩4 @ User Datagram Protocol (UDP)]]_
