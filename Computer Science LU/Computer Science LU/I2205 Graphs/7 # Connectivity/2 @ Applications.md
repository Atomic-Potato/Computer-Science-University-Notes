 # F-Graphs definitions
 an F-Graph is defined by:
 - C(G) >= 2
 - for all x and y belong to C(G), d(x,y) = rad(G)

`jth central distance set N_j:` where 0<=j<=rad(G)
N_j(G) = {x; d(x, C(G)) = j}

# F-Graphs Theorems
- if the radius >= 2 and j = lowerbound(radius/2) then N_j(G) is not empty
- any diameteral path has a subgraph of length at least diameter  - radius
- for k >= 2 there exists an F-graph with radius r having k centeral vertices

# Network Reliability
The models of network reliability:
- `Edge failure model` where the vertices are immune to failure and the edges have a probability `q` of failure
- `Vertex failure model` same as above but with vertices and with probability `p`
- `Edge-neighbor connectivity model` is if an edge fails then its adjacent vertices fail as well

# Reminders
- $Pr(A_1\cap A_2 \cap ..) = Pr(A_1)*P(A_2)...$ if the events are independent 
- $Pr(A\cup B) = Pr(A)+Pr(B)-Pr(A\cap B)$
