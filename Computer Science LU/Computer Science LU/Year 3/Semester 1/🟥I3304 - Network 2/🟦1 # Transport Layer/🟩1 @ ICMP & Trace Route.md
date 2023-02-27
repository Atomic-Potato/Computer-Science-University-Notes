_Next [[🟩2 @ Transport Layer Services]]_

---

# ICMP
Stands for ` Internet Control Message Protocol`. It is used by [network devices](https://en.wikipedia.org/wiki/Network_device "Network device"), including [routers](https://en.wikipedia.org/wiki/Router_(computing) "Router (computing)"), to send error messages and operational information indicating success or failure when communicating with another [IP address](https://en.wikipedia.org/wiki/IP_address "IP address").
Basically it is a debugging tool to check if the connection is working.

ICMP messages are carried inside IP datagrams:
![[Pasted image 20230222150921.png]]

The following are the codes sent in the ICMP and what they mean / what the ICMP is checking
![[Pasted image 20230222151036.png|400]]

# Trace Route #traceroute
In this section we will discuss how to **trace the path between a host and a router/host.**

To do this, the source/host sends a series of UDP _(User Datagram protocol, its like those segment thingies)_ segments to the destination host. Fist has `TTL = 1`. second has `TTL = 2`, and so on.
_(TTL: Time to live (TTL) refers to the amount of time or “hops” that a packet is set to exist inside a network before being discarded by a router.)_

When nth datagram arrives to nth router, then:
- The router discards the datagram.
- The router sends to the source an ICMP message _(of type 11 and code 0)_. 
- The datagram sent from the sauce includes router IP address. 
- Traceroute does a [[🟩3 @ Domain Name System (DNS)|DNS]] lookup  to find the name of the router _(if it has it)_ 

When the ICMP message arrives, the source calculates the RTT. Traceroute repeats this process 3 times to ge the average RTT.
_(Round-trip time (RTT) is the duration in milliseconds it takes for a network request to go from a starting point to a destination and back again to the starting point.)_

This process may fail if the ICMP message returns _"port unreachable (type 3, code 3)"_, _(Maybe it doesn’t want to identify its identity)_

## Example
![[Pasted image 20230222152753.png]]
Router 1 decrements the TTL, TTL becomes 0 ->
![[Pasted image 20230222152812.png]]
 Source saves the IP of Router 1, and then resends the packet with TTL=2:
 ![[Pasted image 20230222152825.png]]
 Router 2 decrements the TTL, TTL becomes = 0 ->
 ![[Pasted image 20230222152841.png]]

Source saves the IP of router 2, and then resends the packet with TTL=3 -> Router 3 will detect a TTL = 0 -> sends an ICMP TTL expired packet  Source saves IP of Router 3

Source sends the packet again with TTL = 4 -> reaches the destination
The Trace Route would be:
- Source: 192.168.10.1
- Router 1: 192.168.13.4
- Router 2: 192.168.15.9
- Router 3: 192.168.29.10
- Destination: 192.168.50.11

---
_Next [[🟩2 @ Transport Layer Services]]_
