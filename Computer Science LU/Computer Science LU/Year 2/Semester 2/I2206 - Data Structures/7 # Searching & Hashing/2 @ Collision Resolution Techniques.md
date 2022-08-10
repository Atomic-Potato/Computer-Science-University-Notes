The process of finding an alternate when collision occurs location is called `collision resolution`.

There is a number of collision resolution techniques, and the most popular ones are:
- `Direct Chaining:` (An array of linked list application)
	-  Separate chaining
	- Coalesced hashing
- `Open Addressing:` (Array based implementation)
	- Linear probing (linear search)
	- Quadratic probing (non linear search)
	- Double hashing (use two hash functions)

---
# Open Addressing
In `open addressing`, all keys will be stored in the hash table itself, the approach is also known as `closed hashing`. 
This procedure is based on `probing`. A `collision` is resolved by `probing`.

## Linear probing (Linear Search)
In this method, each step between probes is **fixed to 1**.

**Steps:**
- Search the hash table sequentially starting from the original hash location.
- If a location is occupied, check next location.
- Wrap around from the last table location to the first table location if necessary.

(Im still what is the rehashing used for)
`The rehashing function` : **rehash(key) = (n+1) % table size**

The **problem** with this method is that table items tend to cluster together in the hash table.

## Quadratic probing (non linear search)
In this method, the interval between probes increases proportional to the hash value.

**Steps:**
- Start from the original hash `location i`. If location occupied, check locations $\large \color{orange} i+1^2, i+2^2,...$
- Wrap around from the last table location to the first table location if necessary.

`The rehashing function` : **rehash(key) = (n+k^2) % table size**

(Clustering problem is eliminated)

## Double hashing (use two hash functions)
In this method, the interval between probes is computed by another hash function.
The second hash function `h2` should be: $\large \color{orange}h2(key)\ne0$  and $\large \color{orange}h2 \ne h1$

**Steps:**
- First probe the location `h1(key)`.
- If the location is occupied, probe the location `h1(key)+h2(key)`, `h1(key)+2\*h2(key)`, …

(Double hashing reduces clustering in a better way)

--- 

# Direct Chaining
## Separate Chaining
Collision resolution by chaining combines linked representation with hash table.
When 2 or more records hash to the same location, these records are constituted into a singly-linked list called a chain.
![[Pasted image 20220802151314.png | 550]]

## Coalesced hashing
Say we have collision between **key1** and **key2** but hashing key1 does not give the same hashing of key2, so key1 is stored in the place of key2.
And so 
- we place key2 in its spot 
- and give a link to key1 (usually `-1` marks that theres no links, and `-2` is an empty cell)

```c
typedef struct
{
	element data;
	int link;
} cell;

int empty(cell T[], int i)
{
	return (T[i].link == -2);
}
```

### Coalesced hashing - `LISCH`
**Method:**
1. `i = h(k)`
2. Search the chain starting at `position i`.
3. If `k` is not found store it at the table end pointer and also append it to the end of the collision chain.

*Example:*
h (k ) = k mod 5
sequence: 1, 5, 21, 10, 15
![[Pasted image 20220802152335.png]]

### Coalesced hashing - `EISCH`
**Method:**
1. `i = h(k)`
2. Search the chain starting at `position i`.
3. If `k` is not found store it at the table end pointer and also append it just behind the first element of the collision chain.

*Example:*
h (k ) = k mod 5
sequence: 1, 5, 21, 10, 15
![[Pasted image 20220802152827.png]]

--- 

# Comparison of Collision Resolution Techniques
## Linear Probing vs. Double Hashing
The choice between linear probing and double hashing depends on:
- the cost of computing the hash function and on
- the load factor of the table.

Both use few probes but double hashing take more time because it hashes to compare two hash functions for long keys.

## Open Addressing vs. Separate Chaining
Take into account the memory usage.
- `Separate chaining` uses extra memory for links.
- `Open addressing` needs extra memory implicitly within the table to terminate the probe sequence.

Open-addressed hash tables cannot be used if the data does not have unique keys.
An alternative is to use separate chained hash tables.

## Open Addressing methods
![[Pasted image 20220802153247.png | 600]]
