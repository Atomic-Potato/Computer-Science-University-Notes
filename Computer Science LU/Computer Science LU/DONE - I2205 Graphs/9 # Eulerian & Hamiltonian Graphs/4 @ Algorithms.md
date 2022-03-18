// CHECKING IF THE GRAPH IS EULERIAN

// 0: NOT EU 1: SEMI-EU 2: EU
// all what we have to do is check the number of odd degrees
// if its not connected or the number of odd degrees is greater than 2 then its not eu
// if the odd degrees are either 2 or 1 then we have an eu-path / semi-eu
// if theres no odd degrees then its eu
![[EulerianGraphCheck.cpp]]

# Fleury's Algorithm
// FINDING AN EULERIAN CYCLE FROM A GIVEN VERTEX

// What we do is for each edge for this vertex we check if removing it disconnects the graph
// if not we label this edge and add at to the cycle edge list and move on to the next end of the edge
// otherwise we check other edge for this vertex
![[Pasted image 20220130113423.png | 700]]
![[FleuryAlgorithm.cpp]]

# Heirholzer's Algorithm 
![[Pasted image 20220130115237.png | 700]]