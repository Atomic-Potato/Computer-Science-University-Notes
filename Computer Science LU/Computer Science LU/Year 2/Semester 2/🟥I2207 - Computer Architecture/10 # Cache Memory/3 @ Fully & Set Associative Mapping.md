_Previous:_ [[2 @ Direct Mapping]]

---

# Fully Associative Mapping
In this type of mapping **a RAM line can be moved to any cache line** and the filed **index is removed**

Instead the memory address is decomposed into 2 fields:
- `offset:` $\large \color{pink} size(offset) = log_2(LineLength)$
- `tag:` $\large \color{pink} size(tag) = size(MemoryAddress) - size(offset)$
## Pseudo-algorithm
![[Pasted image 20220727201035.png | 400]]
(The first line in **Check** means loop over all the lines of the cache)
**In case of a `cache miss`** 
-  Determine the RAM line $\large RL_i$ to be moved where **`i` = tag**
-  Determine the Cache line $\large CL_j$ to be replaced
	Use replacement algorithm: `First In First Out (FIFO)` or `Least Frequently Used (LFU).`
	In case of **LFU** each cache line must have an indicator: `Number Of Hits (NH).` _(At the beginning all NHs must be 0)_
	And at each `cache hit` increase the NH by 1 for that line.
	Now To determine `j`, select the cache line with the **lowest NH**.
- if $d_j = 1$ (dirty bit)  move $\large CL_J$ to the corresponding RAM line $\large RL_k$ where $\large k = t_j$ (tag of $CL_j$)
	$v_j = 1$
	$d_j = 1$
	$t_j = tag$
	$NH_j = 1$

**The disadvantage of this mapping is that its time consuming.**

---

# Set Associative Mapping
In this type of mapping **a RAM line can be moved to a set of lines,**  and **a cache is divided into sets of same size.**

*Examples:*
2-way associative: a set contains 2 lines
4-way associative: a set contains 4 lines
Etc…

(1-way is just direct mapping and n-way is just fully associative mapping)

The address is decomposed into 3 fields:
- `offset:` $\large \color{pink} size(offset) = log_2(LineLength)$
- `set:` $\large \color{pink} size(set) = log_2(NumberOfSets)$
- `tag:` $\large \color{pink} size(tag) = size(MemoryAddress) - size(offset) - size(set)$

The set field in address determines the corresponding set Sp where p[0, q-1] where q is the number of sets
Consider Sp and apply the fully associative algorithm.

**`NOTE:`** in case of a cache miss in this mapping (after moving the dirty bit, if there was any)
- In order to determine the RL we use **both** the `tag` and the `set` bits 
- And to get the CL we just multiply the number of sets by the number of lines in each set + the number of the line with the tag to be moved (starting from 0)
- And then move from RL to CL 
## Replacement algorithm
We have three algorithms we can use:
- `FIFO`
- `LFU`
- `Clock`

### Using Clock Algorithm
The couple `(r, d)` is used, where `r` is the **referenced (accessed) bit** and `d` is the **dirty(modified) bit** .

The `r-bit` is **set to 0 periodically** (each 1ms for example).
The `d-bit` is important to **distinguish between two lines having the same r-value**, since a modified cache line must be transferred back to the RAM.

And so we get four choices:
- (0, 0): best to replace
- (0, 1): second choice
- (1, 0): third choice
- (1, 1): fourth choice 

## Locality
The performance of cache relies on the concept of locality.

There are 2 main types of locality:
- `Spatial:` Where the data and its neighbors are being accessed in small amount amount of time
- `Temporal:` When data is being accessed multiple times

*Example:*
```c
for (i=0; i<N; i++)
	for (j=0; j<M; j++)
		x[i] = x[i] + a[i][j];
```
- Variables:
	-  x[i]: spatial and temporal locality.
	- a[i][j]: spatial locality.
- Instructions:
	- Consecutive instructions: spatial locality.
	- Loop (beq, j for, etc.): temporal locality.

---
_Previous:_ [[2 @ Direct Mapping]]