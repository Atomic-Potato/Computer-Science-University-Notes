_Next [[🟩3 @ Static Routing]]_
_Previous [[🟩1 @ Routers]]_

---


Routers use `static routes` and `dynamic routing` protocols to learn about remote networks and build their routing tables.
Then they use these tables to determine the best path to send packets. 

# Routing Table
A routing table helps routers to make efficient routing decisions to forward a packet.

This table contains:
- Destination network address
- subnet mask
- gateway
- Interface _(usually ethernet interfaces)_

_For example:_
![[Pasted image 20230222101246.png|600]]
R2's routing table is 1 hop from network _192.168.1.0/24_ and _192.168.4.0/24_. And directly connected to network _192.168.2.0/24_ and _192.168.3.0/24_

## Remote networks routing entries
![[Pasted image 20230225103055.png|700]]

## Directly connected routing table entries
![[Pasted image 20230225103325.png|700]]

## How does it work
1. Computer sends a packet to a router
2. router receives packet & analyzes according to the routing table, to determine the most efficient path to send the packet
3. Routers keep on routing the packet
4. Packet reaches a router that is on the same network as the destination IP

**_Note:_** The address `0.0.0.0` is for any destination address, i.e. broadcast i think.

---

# Static & Dynamic Routing
A router can learn about remote networks in one of two ways:

## [[🟩3 @ Static Routing|Static Routing]]
**Each router must be configured & adjusted manually by the admin**

This type is good for small non-redundant networks. And its often used in conjunction with dynamic routing protocol for configuring a default route.

## [[🟩4 @ Dynamic Routing Algorithms|Dynamic Routing]]
**Protocols that span and build a routing table**

This table is dynamic, i.e. it keeps updating the paths. _(so if theres a node down, it builds an alternate path)_

## Static Vs Dynamic
Static routing is troublesome when theres many IPs. And if theres a router down, the whole network will go down too, unlike dynamic routing.

# Default Gateways
**A default gateway is a device that routes traffic from the LAN to devices on remote networks.**

If a host sends a packet to a device outside its network IP, the packet is forwarded to the default gateway. However it doesnt get involved if the device being sent to is inside the IP network.

# Address Resolution Protocol (ARP)
**The ARP role is the association between `IP` to `MAC` address**

_Difference between IP and MAC addresses:_
![[Pasted image 20230221222442.png]]

The ARP protocol is responsible for finding the device that we are sending a packet to. 
To do this it looks we get the public `IP address` of the device we're sending a packet to on the network. And then it looks into the routing table to see if it knows the `MAC address` for this `IP address`:
- if so it sends the package to that `IP address.` 
- If not it **broadcasts a message on the network** asking which device this `IP address` belongs to, and then the device with that IP responds with its `MAC address` which gets added to the routing table.

That was how it would work on a local network, but the process is the same on a global network, where this protocol is applied on each router.

**_Note:_** Difference between local and global IP addresses:
![[Pasted image 20230221222411.png]]


## ARP Table
It contains:
- IP address
- MAC address 
- Time to live _(time to keep it in the ARP table before deleting it)_
![[Pasted image 20230222103243.png]]

Each IP node (host, or router) on LAN has an ARP table.

To see the ARP table of your network, use `arp -a` command in cmd.

## When is ARP used
1) **Host sends a packet to another host on same network:**  target IP is the destination address of the IP packet
2) **Host sends a packet  to another host on  different network:**  must pass through a router; target IP is the IP address of the router
3) **Router sends a packet to router:**  Target IP address is the IP address of the appropriate router found in the routing table
4) **Router sends a packet to host on same network:**  Target IP address is the destination address in the IP packet

# Routing Example
- PC1 sends a packet to PC2
  ![[Pasted image 20230222103652.png]]
  ![[Pasted image 20230222103729.png]]

- R1 forwards the packet to R2
  ![[Pasted image 20230222104006.png]]
  ![[Pasted image 20230222104026.png]]
  
  
- R2 forwards the packet to R3
  ![[Pasted image 20230222104144.png]]
  ![[Pasted image 20230222104039.png]]
  
- R3 forwards the packet to PC2
  ![[Pasted image 20230222104222.png]]
  ![[Pasted image 20230222104057.png]]

# Path Determination

## Routing Decisions
![[Pasted image 20230225100632.png|700]]

## Best Path
Best path is selected by a routing protocol based on the value or metric it uses to determine the distance to reach a network.
==**Note:** A metric is the value used to measure the distance to a given network. Best path to a network is the path with the lowest metric.==

Dynamic routing protocols use their own rules and metrics to build and update routing tables, which are:
- [[Routing Information Protocol (RIP)]]: Hop count
- [[Open Shortest Path First (OSPF):]] Cost based on cumulative bandwidth from source to destination
- [[Enhanced Interior Gateway Routing Protocol (EIGRP)]]: Bandwidth, delay, load, reliability

## Load Balancing
When a router has two or more paths to a destination with equal cost metrics, then the router forwards the packets using both paths equally.
![[Pasted image 20230225102431.png|300]]

## Administrative Distance
When multiple paths to the same destination are available in its routing
table, the router uses the route with the **lowest Administrative Distance
_(AD)_** _(A static route with an AD of 1 is more reliable than an EIGRP-discovered route
with an AD of 90.)_
![[Pasted image 20230225102632.png|600]]

---
_Next [[🟩3 @ Static Routing]]_
_Previous [[🟩1 @ Routers]]_