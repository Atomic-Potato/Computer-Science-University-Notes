# Nuts 'n bolts
-  `Internet`: “network of networks”. Interconnected ISPs
- `protocols` control sending, receiving of messages
	e.g., TCP, IP, HTTP, Skype, 802.11
-  `Internet standards`
	- `RFC`: Request for comments
	- `IETF`: Internet Engineering Task Force

# Protocols
protocols define format, order of messages sent and received among network entities, and actions taken on message transmission, receipt

*Comparison example:*
![[Pasted image 20220702112412.png | 400]]

## Protocol layers
Networks are complex, with many “pieces”:
hosts / routers / links of various / media / applications / protocols / hardware, software

There are two competing models for how the software is layered. These are the `OSI (Open Systems Interconnection)` and the `TCP (Transfer Control Protocol)` models.

- `OSI` model:
![[Pasted image 20220702112826.png | 500]]
- `TCP` model:
![[Pasted image 20220702112854.png | 500]]

## Internet protocol stack
- `application`: supporting network
	applications: FTP, SMTP, HTTP
- `transport`: process-process data transfer
	TCP (ex. Email), UDP (ex. Skype)
- `network`: routing of datagrams from source to destination
	IP, routing protocols
- `link`: data transfer between neighboring network elements
	Ethernet, 802.111 (WiFi), PPP
- `physical`: bits “on the wire”

![[Pasted image 20220702114058.png | 100]]

### ISO/OSI reference model
- `presentation`: allow applications to interpret meaning of data, e.g., encryption, compression, machine-specific conventions
- `session`: synchronization, check-pointing, recovery of data exchange

![[Pasted image 20220702114514.png | 100]]

# Headers
When passing in each `layer` a `header/trailer` is created to store data and information about it, this `header` can be used to decode the information received by the other end
![[Pasted image 20220702114959.png | 700]]
## Examples
- **Peer to peer process**
![[Pasted image 20220702115100.png]]
- **An exchange using the Internet model**
![[Pasted image 20220702115141.png]]

