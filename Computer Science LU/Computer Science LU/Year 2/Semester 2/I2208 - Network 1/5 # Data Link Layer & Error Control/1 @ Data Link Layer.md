Communication at the data-link layer is node-to-node.
![[Pasted image 20220707140939.png | 500]]

- Data-link layer of a node is responsible for delivering a datagram to the next node in the path.
	- **sending** node needs to `encapsulate` the datagram received from the network in a frame.
	- **receiving** node needs to `decapsulate` the datagram from the frame.
	![[Pasted image 20220707141147.png | 500]]

# Data-link layer Services
- `Framing: ` A packet at the data-link layer is normally called a frame. A frame may have both a header and a trailer. ^framing
- `Flow control:` If the producer produces items that cannot be consumed, accumulation of items occurs. ^flowControl
- `Error control:` Since electromagnetic signals are susceptible to error, a frame is susceptible to error. ^errorControl
- `Access control`

# DLC & MAC
The data-link layer contains 2 sublayers:
- **Data link control** `(DLC)`
- **Media access control** `(MAC)`

In the following picture, the `DLC` contains the **source IP address "N1"** and the **destination IP address "N8"**
While the `MAC` contains the **link layer addresses "L"** between each node *(like pc and router or router and router).*
So when a new node is reached, the `MAC` address is **decapsulated** and **reads** the `DLC` address and then **encapsulates** it with a new `MAC` address.
![[Pasted image 20220707142116.png]]