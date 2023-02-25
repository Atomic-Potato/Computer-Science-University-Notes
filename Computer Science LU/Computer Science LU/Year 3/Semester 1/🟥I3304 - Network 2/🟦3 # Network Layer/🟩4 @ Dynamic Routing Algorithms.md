_Next [[🟩5 @ Dynamic Routing Protocols]]_
_Previous [[🟩3 @ Static Routing]]_

---

Dynamic Routing Advantages and Disadvantages:
![[Pasted image 20230225120337.png|700]]

[[🟩3 @ Static Routing|Static Routing]] Advantages and Disadvantages:
![[Pasted image 20230225120409.png|700]]

# Dynamic Routing Protocols Components
- `Data Structures:`  Routing protocols typically use tables or databases for its operations. _(This information is kept in RAM)_
- `Routing protocol messages:` Routing protocols use various types of messages to discover neighboring routers, exchange routing information, and other tasks to learn and maintain accurate information about the network.
- `Algorithm:` Routing protocols use algorithms for facilitating routing information for best path determination.

## Protocol Operation
- The router sends and receives routing messages on its interfaces.
- The router shares routing messages and routing information with other routers that are using the same routing protocol.
- Routers exchange routing information to learn about remote networks.
- When a router detects a topology change the routing protocol can advertise this change to other routers.

# Dynamic Routing Algorithms
## Graph abstraction:
![[Pasted image 20230225123955.png|700]]

## Routing algorithms classification
- **Global or decentralized information?:**
	- `Global:` all routers have complete topology and link cost info. These are **Link state** algorithms
	- `Decentralized:` a router knows physically-connected neighbors and link costs to neighbors. They use san iterative process of computation and exchanging info with neighbors. These are **Distance vector** algorithms
- **Static or dynamic?:**
	- `Static:` routes change slowly overtime
	- `Dynamic:` routes change more quickly. There are periodic updates, and updates in response to link cost changes.

## Link-State Algorithms: Dijkstra
This algorithm computes least cost paths from one node _(“source”)_ to all other nodes. _(Gives forwarding table for that node)_

It is iterative: after k iterations, know least cost path to k destinations.

### Notation
- $\large \color{pink} c_{x,y}$ : direct link cost from node x to y; = ∞ if not direct neighbors
- $\large \color{pink}D(v)$: current estimate of cost of least-cost-path from source to destination v
- $\large \color{pink}p(v)$: predecessor node along path from source to v
- $\large \color{pink}N'$: set of nodes whose least-cost-path definitively known

### Algorithm
```cs
Initialization:
	N' = {u} // compute least cost path from u to all other nodes 
	for all nodes v
		// u initially knows direct-path-cost only 
		// to direct neighbors
		// but may not be minimum cost!
		if v adjacent to u   
			then D(v) = c u,v 
		else D(v) = ∞

Loop:
	find w not in N' such that D(w) is a minimum
	add w to N'
	update D(v) for all v adjacent to w and not in N' :
		D(v) = min ( D(v), D(w) + c(w,v) )
	// new least-path-cost to v is either 
	// old least-cost-path to v
	// or known least-cost-path to w plus direct-cost from w to v
until all nodes are in N'
```

#### Example
![[Pasted image 20230225130116.png]]

resulting least-cost-path tree from u: 
![[Pasted image 20230225130602.png]]

resulting forwarding table in u:
![[Pasted image 20230225130627.png]]

--- 

## Distance Vector Algorithms: Bellman-Ford
Based on Bellman-Ford (BF) equation:
$\large \color{pink}D_{x}(y)$: estimate of the least cost path from x to y. _(v is the x's neighbor)_
$$\large \color{pink} D_{x}(y) = min_{v}\{c_{x,v}+D_{v}(y)\}$$ 
Keep in mind that x:
- knows the cost to each neighbor v
- maintains its neighbors distance vector.

_Bellman-Ford Example:_
Suppose that u’s neighboring nodes, x,v,w, know that for destination z:
![[Pasted image 20230225133632.png]]
Bellman-Ford equation says:
![[Pasted image 20230225133702.png]]

### Basic Idea
From time-to-time, each node sends its own distance vector estimate to neighbors.
When x receives a new distance vector estimate from any neighbor, it updates its own distance vector using the bellman ford equation equation.

_Visual representation of the above stated:_
![[Pasted image 20230225134035.png | 300]]

The properties of these algorithms: 
- `Iterative, Asynchronous:` each local iteration caused by:
	- local link cost change
	- distance vector update message from neighbor
- `Distributed, Self-stopping:`  each node notifies neighbors only when its distance vector changes
	- Neighbors then notify their neighbors, only if necessary
	- No notification received, no actions taken!

### Algorithm
```cs
Initialization: 
	for all destinations y in N: 
		if y is neighbor of x:
			D_x(y) = c(x,y)
		else
			D_x(y) = infinity
			 
	for each neighbor w: 
		D_w(y) = ? for all destinations y in N 
		
	for each neighbor w: 
		send distance vector D_x = [D_x(y): y in N] to w 

Loop forever: 
	wait:
		until I see a link cost change to some neighbor w 
		OR
		until I receive a distance vector from some neighbor w 
		
	for each y in N: 
		D_x(y) = min_v{c(x,v) + D_v(y)} 
		
	if Dx(y) changed for any destination y: 
		send distance vector D_x = [D_x(y): y in N] to all neighbors 
```

### Example
![[Pasted image 20230225135233.png]]

---

_Next [[🟩5 @ Dynamic Routing Protocols]]_
_Previous [[🟩3 @ Static Routing]]_