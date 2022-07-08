![[Pasted image 20220702120558.png]]

# Layers `Semi-Important`
## Physical Layer
**The physical layer is responsible for transmitting individual bits from one node to the next.**

Physical characteristics of interfaces and media
- Representation of bits without interpretation
- Data rate: number of bits per second
- Synchronization of bits
- Deal with the transmission medium
![[Pasted image 20220702115257.png | 600]]

## Data Link Layer
**The data link layer is responsible for transmitting frames from one node to the next.**

Data Link Layer Responsibilities
Defines frames into manageable data units
- Physical addressing
- Flow control
- Error control, ACM at the PHY layer
- Access control

![[Pasted image 20220702115614.png | 600]]

*Example:*
![[Pasted image 20220702115657.png | 600]]

## Network Layer
**The network layer is responsible for the delivery of packets from the original source to the final destination.**

Network Layer Responsibilities
- Source-to-destination delivery, possibly across multiple networks
- Logical addressing
- Routing

![[Pasted image 20220702115851.png | 600]]

*Example:*
![[Pasted image 20220702115928.png | 500]]

## Transport Layer
**The transport layer is responsible for delivery of a message from one process to another.**

Transport Layer Responsibilities
- Process-to-process delivery of entire message
- Port addressing
- Segmentation and reassembly
- Connection control: connectionless or connection-oriented
- End-to-end flow control
- End-to-end error control

![[Pasted image 20220702120135.png | 600]]

*Example: `(important)`*
![[Pasted image 20220702120354.png]]

## Application Layer
**The application layer is responsible for providing services to the user.**
![[Pasted image 20220702120516.png | 600]]
