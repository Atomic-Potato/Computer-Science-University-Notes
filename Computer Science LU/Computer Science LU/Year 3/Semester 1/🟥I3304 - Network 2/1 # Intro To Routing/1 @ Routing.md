Routers use `static routes` and `dynamic routing` protocols to learn about remote networks and build their routing tables.
Then they use these tables to determine the best path to send packets. 

# Routing Table
A routing table helps routers to make efficient routing decisions to forward a packet.

This table contains:
- Destination network address
- subnet mask
- gateway
- Interface _(usually ethernet interfaces)_

## How does it work
1. Computer sends a packet to a router
2. router receives packet & analyzes according to the routing table, to determine the most efficient path to send the packet
3. Routers keep on routing the packet
4. Packet reaches a router that is on the same network as the desitination IP

**_Note:_** The address `0.0.0.0` is for any destination address

## Example

---

# Static & Dynamic Routing
There are 2 types of routing:

## Static Routing
**Each router must be configured & adjusterd mannually by the admin**

This type is good for small non-redundant networks. And its often used in conjunction with dynamic routing protocol for configuring a default route.

## Dynamic Routing
**Protocols that span and build a routing table**

This table is dynamic, i.e. it keeps updating the pathes. _(so if theres a node down, it builds an alternate path)_

## Static Vs Dynamic
Static routing is troublesome when theres many IPs. And if theres a router down, the whole network will go down too, unlike dynamic routing.

# Default Gateways
**A default gateway is a device that routes traffic from the LAN to devices on remote networks.**

If a host sends a packet to a device outside its network IP, the packet is forwarded to the default gateway. However it doesnt get involved if the device being sent to is inside the IP network.

# Address Resolution Protocol (ARP)
**The ARP role is the association between IP to MAC address**

- A reminder of the MAC address: **[FACT CHECK THIS PLZ]**
	It is used in the **Network Layer** _(Layer 3)_. And its represented in hexadecimal with 48bits _(e.g. IA-2F-BB-76-09-AD)_
	- `Funtion:` it is used **locally** to get a frame from one interface to another physically connected interface.

# ARP Table
It cotains:
- IP address
- MAC address 
- Time to live _(time to keep it in the ARP table before deleting it)_
- 