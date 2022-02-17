# Definitions
**`Distance`** is the distance between a u-v geodesic path (which also should be the shortest path between u-v)
`Note: d(u,v) <= d(u, w) + d(w,v)`

**`Eccentricity e(v)`** is the max distance you can go from the vertex `v` 
**`Eccentric vertex`** is the last vertex reached by `e(v)`
**`Mutually eccentric`** is when 2 vertices are eccentric to each other

**`radius`** rad(G) = min (e(v))
**`center`** is the set which contains all vertices that are equal to rad(G), denoted `C(G) = [v, u, ...]`

**`diameter`** dia(G) = max (e(v))
**`periphery`** is the set which contains all vertices that are equal to dia(G), denoted `P(G) = [v, u, ...]`

**`antipodal / diamteral`** are the distances that are equal to dia(G)

**`radial path`** is the geodesic path joining a central vertex to one of its eccentricities
**`diametral path`** is the geodesic path joining a diameteral pair of vertices

**The centroid of a tree**
**`Weight of branch`** is the max amount of vertices of a branch of a selected vertex
Example of branches:
![[branch weights in trees.jpg | 500]]

**`centroid`** is the vertex with the minimum weight 


# Theorem
- If u and v are adjacent in a connected graph  then  |e(u) - e(v)| <= 1

**Trees**
- we either have 1 or 2 center vertices
- rad(G) <= dia(G) <= 2 x rad(G)
- if c(T) = 1 then dia(T) = 2 x rad(T)
- if c(T) = 2 then dia(T) = 2 x rad(T) - 1

**Self-complementary graphs (G is isomorphic to bar(G))**
- dia(G) >= 3 then dia(bar(G)) <= 3
# Properties 
In paths we have:
- eccentric vertices = end vertices
- Pair of antipodals are end vertices
- P(G)  = end vertices
- every diameteral path should pass by the central vertices 