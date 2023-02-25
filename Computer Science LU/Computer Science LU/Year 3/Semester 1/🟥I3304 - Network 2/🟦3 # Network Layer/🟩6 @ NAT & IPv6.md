_Previous [[🟩5 @ Dynamic Routing Protocols]]_

---

# NAT
NAT stands for `Network Address Translation`. It is a technique used to translate private IP addresses used inside a private network into public IP addresses used on the Internet, and vice versa. 
NAT is typically used in networks where multiple devices need to share a single public IP address to access the Internet.

NAT provides a way to extend the limited supply of public IP addresses available on the Internet by allowing multiple devices to share a single public IP address. However, it can also introduce some limitations, such as making it difficult for external devices to initiate connections with devices inside the private network, and making it more difficult to implement end-to-end security protocols.

## Advantages
- Just one IP address needed from provider ISP for all devices
- Can change addresses of host in local network without notifying outside world
- Can change ISP without changing addresses of devices in local network
- Security: devices inside local network not directly addressable  not visible by outside world

## Implementation
- `Outgoing datagrams:` Replace source IP address and port number of every outgoing datagram to **NAT IP address and new port number** _(Remote clients/servers will respond using the NAT IP address and the new port number as destination address)_
  Remember in NAT translation table, every source IP address and port number to NAT IP address and new port number translation pair.
- `Incoming datagrams:` Replace NAT IP address and new port number in destination fields of every incoming datagram with corresponding source IP address and  port number stored in NAT table.

## Visual Representation
![[Pasted image 20230225190754.png]]

## NAT controversies
- Routers “should” only process up to layer 3. Port numbers are meant to be used for addressing processes, not for addressing hosts.
- Address “shortage” should be solved by IPv6
- Violates end-to-end argument  (port # manipulation by network-layer device)
- NAT traversal: what if client wants to connect to server behind NAT?

# Internet Protocol version 6 (IPv6)
`IPv4` is the most widely used protocol and provides unique **32-bit addresses** to devices connected to the Internet. `IPv6`, on the other hand, uses **128-bit addresses** and is designed to provide more address space for the growing number of devices connected to the Internet.

## IPv6 Datagram Format
![[Pasted image 20230225191243.png]]
What’s missing _(compared with IPv4)_:
- No checksum _(to speed processing at routers)_
- No fragmentation/reassembly
- No options _(available as upper-layer, next-header protocol at router)_

## Transitioning from IPv4 to IPv6
Obviously not all routers can be upgraded simultaneously. This is why `Tunneling` is used.

`Tunneling:` IPv6 datagram carried as payload in IPv4 datagram among IPv4 routers _(“packet within a packet”)_
![[Pasted image 20230225191512.png|700]]
![[Pasted image 20230225191649.png|700]]

---
_Previous [[🟩5 @ Dynamic Routing Protocols]]_
