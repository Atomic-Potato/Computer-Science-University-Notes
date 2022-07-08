We will discover here how to assign a code to a tree and how to draw a tree from that code
# Prüfer codes
In Prufer code the number of vertices equals `n-2`

### Algorithm 1 (Getting Prufer Code)
Note: $a_n$ for Pufer and $b_n$ for Sister
When constructing the Prufer code we have a Sister code constructed simultaneously to contain the order of vertices with one edge
- Create an array of booleans where each `index = a vertex` and set all of them to `true`
- Create a `priority queue` and put all the end vertices inside of it ==(Remember that this queue will be reversed so fix it)==
- Choose `b1`, which is the end vertex with the smallest label, and the end of the edge will be `a1`
- then set  b1 in the array of booleans to `False` (delete it)
- Decrement the `degree of a1`
- if the degree of `a1 = 1` add it to the priority queue
- Repeat process until theres only `2 vertices` left

### Algorithm 1 (Getting Sister Code)
- add k+2 at the end of the prufer code where k is the number of vertices in the code
- `b1` is the smallest vertex not in `(a1,...,an)`
- delete `a1` from prufer code / bool array 
- repeat
- Once done you can map a1 to b1 as an edge up to an bn
Remember that once you add b to the list of sisters you cant add again 

### Cayley's theorem 
if we have n vertices in a tree we can label them in
$$n^{n-2}$$
ways.

### Binary addressing of a tree
`Hamming distance`
consider 2 binary vectors, example:
(1, 0, 1, 0)
(1, 1, 0, 0)
The hamming distance is the number of times where an element from a vector is different from the element in the second vector with the same index. in that example we have 2:
(1, `0`, `1`, 0)
(1, `1`, `0`, 0)

`Binary addresiing` is giving each vertex in a labeled graph a binary number, these graphs are called `hamming graphs`
We store these addresses in tuples of size `n`

**Theorem**
a tree `T` of order n => tuples of size `n-1` (also called (n-1)-Tuples)

**A way to do binary addressing**
tbh i cant really bother, its not the most important thing, its in the last bit of the tile video