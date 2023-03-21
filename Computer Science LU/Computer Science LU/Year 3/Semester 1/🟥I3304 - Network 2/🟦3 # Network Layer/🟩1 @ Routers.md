_Next [[🟩2 @ Routing]]_

---

# Routers

Routers use `static routes` and `dynamic routing` protocols to learn about remote networks and build their routing tables.
They encapsulate the packet and forward it to the interface indicated in routing table.

## Architecture overview
high-level view of generic router architecture:
![[Pasted image 20230224182954.png|600]]

## Input port functions
![[Pasted image 20230224183344.png|450]]
`Decentralized switching:`
- using header field values, lookup output port using forwarding table in input port memory
  goal: complete input port processing at ‘line speed’ 
  Input port queuing: if datagrams arrive faster than forwarding rate into switch fabric
- `destination-based forwarding:` forward based only on destination IP address _(traditional)_
- `generalized forwarding:` forward based on any set of header field values

### destination-based forwarding
We have many IP addresses on the internet _("4 billion +")_ and we cant possibly make 4 billion interfaces for each IP address, so instead we set a range of IP addresses to a single interface:
![[Pasted image 20230224185547.png|400]]

Once a packet is reached and we want to forward it, we match the destination IP with the **longest matching prefix** in the table
![[Pasted image 20230224185701.png|600]]

# Default Gateways
To enable network access, devices must be configured with the following IP address information:
- `IP address:` Identifies a unique host on a local network.
- `Subnet mask:` Identifies the host’s network subnet.
- `Default gateway:` Identifies which router a packet is sent to when the destination is not on the same local network subnet.
  
![[Pasted image 20230225091116.png|700]]

# Network Documentation
Network documentation helps employees get familiar with the network infrastructure, and helpful when troubleshooting network performance.

It should include at least the following in a topology diagram and addressing table:
- Device names
- Interfaces
- IP addresses and subnet masks
- Default gateways

![[Pasted image 20230225091831.png|700]]

# Assigning an IP to a Host
There are 2 ways of assigning an IP address to a Host:
- `Statically Assigned IP address:` The host is manually assigned an IP address, subnet mask and default gateway. A DNS server IP address can also be assigned. It is used:
	- To identify specific network resources such as network servers and printers.
	- In very small networks with few hosts.
- `Dynamically Assigned IP Address:` IP Address information is dynamically assigned by a server using **Dynamic Host Configuration Protocol _(DHCP)_.**

## DHCP: Dynamic Host Configuration Protocol
With DHCP, a host can dynamically obtains IP address from network server when it _“joins”_ a network

DHCP also:
- Can renew its lease on address in use
- Allows reuse of addresses _(only hold address while connected/on)_
- Support for mobile users who join/leave network

DHCP communication messages with host overview:
- Host broadcasts `DHCP DISCOVER` message _[optional]_
- DHCP server responds with `DHCP OFFER` message _[optional]_
- Host requests IP address: `DHCP REQUEST` message
- DHCP server sends address: `DHCP ACK` message

### Example: DHCP client-server scenario
![[Pasted image 20230225095613.png|625]]
![[Pasted image 20230225095642.png|625]]

### DHCP Other Functionalities 
DHCP can return more than just allocated IP address on subnet, it also can:
- Assigning the address of the first-hop router for client _(**Reminder:** first hop meaning if they want to send data to other networks, this router is the first hop the data needs to go to)_
- Assigning a Name and an IP address of the DNS sever
- Assigning a network mask

## How to switch between Static and Dynamic on Windows
![[Pasted image 20230225100036.png]]
![[Pasted image 20230225100042.png]]

---
_Next [[🟩2 @ Routing]]_
