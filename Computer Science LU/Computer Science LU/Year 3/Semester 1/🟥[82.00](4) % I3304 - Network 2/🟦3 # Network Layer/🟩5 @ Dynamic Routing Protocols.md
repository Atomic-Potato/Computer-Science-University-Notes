_Next [[🟩6 @ NAT & IPv6]]_
_Previous [[🟩4 @ Dynamic Routing Algorithms]]_

---

# Autonomous Systems
Obviously we cant have routing tables for all of the routers in the world for each router. Thats why we aggregate routers into regions known `as Autonomous Systems (AS)` _(a.k.a. “domains”)_

Each AS consists of a group of routers that are under the same administrative control, and  is identified by its globally unique `Autonomous System Number (ASN)`.
_(An ISP can own one or more AS)_

## Inter & Intra AS
- `Intra-AS:`
	  Intra-AS routing, also known as interior routing, is the routing protocol used within a single autonomous system. This means that all routers within the same AS use the same routing protocol to exchange routing information and make routing decisions.
	- Routing within same AS 
	- All routers in AS must **run the same intra-domain protocol**
	- Routers in different AS can run different intra-domain routing protocols
	- Theres a gateway router at the _“edge”_ of its own AS, it has link(s) to router(s) in other AS’es
- `Inter-AS:`
	  Inter-AS routing, also known as exterior routing, is the routing protocol used between autonomous systems.
	- Routing among AS’es
	- Gateways perform inter-domain routing _(as well as intra-domain routing)_

## Intra-AS routing: Routing within an AS
Most common intra-AS routing protocols:
- [[🟩5 @ Dynamic Routing Protocols#Routing Information Protocol (RIP)|RIP: Routing Information Protocol]]: classic DV: DVs exchanged every 30 secs 
- [[EIGRP: Enhanced Interior Gateway Routing Protocol]]: DV based
- [[🟩5 @ Dynamic Routing Protocols#Open Shortest Path First (OSPF)|OSPF: Open Shortest Path First]]: link-state routing.

### Routing Information Protocol (RIP)
RIP uses a distance vector algorithm:
- **Distance metric:** # hops _(max = 15 hops)_, each link has cost 1
- DVs exchanged with neighbors every 30 sec in response message _(aka advertisement)_
- Each advertisement: list of up to 25 destination subnets _(in IP addressing sense)_

#### Link failure & recovery
If no advertisement heard after 180 sec, then the neighbor/link is declared dead:
- Routes via neighbor invalidated
- New advertisements sent to neighbors
- Neighbors in turn send out new advertisements _(if tables changed)_
- Link failure info quickly propagates to entire net
- Poison reverse used to prevent ping-pong loops _(infinite distance = 16 hops)_

---

### Open Shortest Path First (OSPF)
OSPF is a [[🟩4 @ Dynamic Routing Algorithms#Link-State Algorithms: Dijkstra|link-state protocol]] that uses flooding of link-state information and a Dijkstra’s least-cost path algorithm.

Each router has an Link-state database _(LSDB)_ which stores advertisements from other routers, now each router floods OSPF link-state advertisements to all other routers in entire AS.
Now each router has full topology, and so it uses Dijkstra’s algorithm to compute forwarding table
_(all OSPF messages are authenticated to prevent malicious intrusion)_

#### OSPF Hierarchy
OSPF has a 2-level hierarchy:  `area` and `backbone`.
_(Link-state advertisements flooded only in area, or backbone)_
![[Pasted image 20230225155758.png|800]]
We do multiple areas to reduce the time taken to make a topology.

Things to note:
- There are area boundary routers that allow communication from the area to the backbone
- Areas cannot communicate with eachother directly, they have to route data through the backbone and then to the other area

_Visual explanation: https://youtu.be/OD3nGIoBQME_

---

# Routing among ISPs: BGP
The `Boreder Gateway Protocol (BGP)` basically handles forwarding to destinations outside the AS.

In BGP, packets are not routed to a specific destination address, but instead to `CIDR`ized prefixes, with **each prefix representing a subnet or a collection of subnets.**
_For example:_ A destination may take the form 138.16.68/22, which for this example includes 1,024 IP addresses.

**A router’s forwarding table will have entries of the form `(x, I)`**, where:
- `x` is a prefix _(such as 138.16.68/22)_
- `I` is an interface number for one of the router’s interfaces.

BGP provides each AS a means to:
- Obtain subnet reachability information from neighboring ASes _(The role of external BGP)_
- Propagate reachability information to all AS-internal routers _(The role of internal BGP)_
-  Determine the _“best”_ routes to the prefixes.

## External & Internal BGP (eBGP & iBGP) connections
![[Pasted image 20230225162238.png|700]]
The main difference between `eBGP` and `iBGP` is in how they are used within an autonomous system (AS) or between autonomous systems:
- `eBGP:`
	1.  Used for routing information exchange between different autonomous systems. It is used to exchange routing information between routers in different ASs, and is typically used by Internet Service Providers (ISPs) to exchange routing information between their networks.
	2. Updates are sent between routers in different ASs, and are typically subject to routing policies that govern how traffic is routed between the ASs.
- `iBGP:`
	1. Used for routing information exchange within a single autonomous system. It is used to exchange routing information between routers within the same AS, and is typically used by large enterprise networks to exchange routing information between their routers.
	2. Updates are sent between routers within the same AS, and are typically not subject to routing policies, as they are intended to be used for internal routing within the AS.


## BGP Basics
`BGP session:` two BGP routers _(“peers”)_ exchange BGP messages over semi-permanent [[🟩5 @ Transmission Control Protocol (TCP)|TCP]] connection _(port 179)_.  Advertising paths to different destination network prefixes _(BGP is a “path vector” protocol)_

_Example:_
When AS3 gateway 3a advertises path AS3,X to AS2 gateway 2c, AS3 promises to AS2 it will forward datagrams towards X
![[Pasted image 20230225162546.png|700]]

## Path attributes and policies
**BGP advertised route is composed of: prefix + attributes** 
- `Prefix:` destination being advertised
- `Attributes:`
	-  `AS-PATH:` list of ASes through which prefix advertisement has passed
	- `NEXT-HOP:` indicates specific internal-AS router to next-hop AS _(the IP address of the router interface that begins the AS-PATH.)_

Gateway receiving route advertisement uses **import policy** to accept/decline path _(e.g., never route through AS NameOfAS)_.
AS policy also determines whether to advertise path to other neighboring ASes.

## Path Advertisement
![[Pasted image 20230225165005.png]]
1. AS2 router 2c receives path advertisement AS3,X _(via eBGP)_ from AS3 router 3a
2. based on AS2 policy, AS2 router 2c accepts path AS3,X, propagates _(via iBGP)_ to all AS2 routers
3. based on AS2 policy, AS2 router 2a advertises _(via eBGP)_ path AS2, AS3, X to AS1 router 1c

![[Pasted image 20230225165244.png]]
Gateway router may learn about multiple paths to destination:
- AS1 gateway router 1c learns path AS2,AS3,X from 2a
- AS1 gateway router 1c learns path AS3,X from 3a
- based on policy, AS1 gateway router 1c chooses path AS3,X and advertises path within AS1 via iBGP

![[Pasted image 20230225165607.png]]
![[Pasted image 20230225165619.png]]

### Hot Potato Routing **(HELL YEAH)**
In hot potato routing, routers forward traffic to the next router in the path that is closest to the traffic's destination network or exit point. This approach is based on the idea that it is better to forward traffic to the next hop as quickly as possible, even if it means sending the traffic in the opposite direction from its ultimate destination.

_The name "hot potato" comes from the idea of passing a hot potato to the next person as quickly as possible, without holding onto it for too long._

![[Pasted image 20230225170713.png]]
Router 2d learns (via iBGP) it can route to X via 2a or 2c

`Hot Potato Routing:` choose local gateway that has the least intra-domain cost _(e.g., 2d chooses 2a, even though more AS hops to X)_: don’t worry about inter-domain cost!

## Messages
The following are BGP messages exchanged between peers over TCP connection:
- `OPEN:` opens TCP connection to remote BGP peer and authenticates sending BGP peer
- `UPDATE:` advertises new path _(or withdraws old)_
- `KEEPALIVE:` keeps connection alive in absence of `UPDATES`; also `ACKs` `OPEN` request
- `NOTIFICATION:` reports errors in previous message. Also used to close connection

## Achieving policy via advertisements
ISP only wants to route traffic to/from its customer networks  _(does not want to carry transit traffic between other ISPs – a typical “real world” policy)_


![[Pasted image 20230225170913.png]]
- A,B,C are provider networks
- x,w,y are customer _(of provider networks)_
- x is dual-homed: attached to two networks
- policy to enforce: x does not want to route from B to C via x. So x will not advertise to B a route to C.

![[Pasted image 20230225171224.png]]
- A advertises path Aw to B and to C
- B chooses not to advertise BAw to C! B gets no _“revenue”_ for routing CBAw, since none of C, A, w are B’s customers
- C does not learn about CBAw path
- C will route CAw (not using B) to get to w

## Route Selection
Router may learn about more than one route to destination AS, selects route based on:
- Local preference value attribute: policy decision
- Shortest AS-PATH
- Closest NEXT-HOP router: hot potato routing
- Additional criteria

---

# Why different Intra-, Inter-AS routing ?

There are 3 reasons:
- `Policy:`
	- `Inter-AS:` admin wants control over how its traffic routed, who routes through its network
	- `Intra-AS:` single admin, so policy less of an issue
- `Scale:` Hierarchical routing saves table size and reduces update traffic
- `Performance:`
	- `Intra-AS:` can focus on performance
	- `Inter-AS:` policy dominates over performance

---
_Next [[🟩6 @ NAT & IPv6]]_
_Previous [[🟩4 @ Dynamic Routing Algorithms]]_
