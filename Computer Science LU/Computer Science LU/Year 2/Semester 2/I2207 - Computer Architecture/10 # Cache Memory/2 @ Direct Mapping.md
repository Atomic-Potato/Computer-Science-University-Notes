In `direct mapping` **the data of a memory address is stored in only one location in the cache.**

Throughout this note, we will work with the following example: 
- Given a cache of 8 bytes divided into lines of 4 bytes each -> 2 lines
	![[Pasted image 20220714162943.png]]
- A RAM of 16 bytes **must be divided** into lines of 4 bytes each -> 4 lines
![[Pasted image 20220714162958.png]]

**The size of a `single memory address:`**
Cell size: 1 byte
Number of cells in the RAM: 16/1 = 16
*Memory address:* $\large log_2(16) = 4 \space bits$

# Tag, Index & Offset
![[Pasted image 20220714163826.png]]

- `Offset` is how many bits are needed to locate the position **(from the left)** of a byte within a line
$$\color{pink}\large size(offset) = log_2(line\_length)$$
- `Index` is how many bits are needed to determine which line is a byte located at
$$\color{pink}\large size(index) = log_2(num\_of\_lines\_in\_the\_cache)$$
- `Tag` is for when we have multiple addresses of the same `index` and `offset` _(like the address 7 and 15)_
$$\color{pink} \large size(tag) = size(memory\_ address) - size(offset) - size(index)$$
## Validity bit
When starting the computer, the cache is empty *(bits of tags and bits of cells are set to 0.)*
So to avoid returning 0 even tho the ram contains data, we use a `valid bit` where  **1 says the cache line (CL) contains data** and **0 it doesnt**
 ![[Pasted image 20220714164717.png]]

## Modifying data & _dirty_ bit
There are tow ways of modifying the data:
- **Write-through cache:** data is updated in cache and memory at the same time
- **Write-back cache:** data is updated in cache only.

### Write-back cache:
We need an extra bit: `dirty bit (d)` where **1 means data got modified** and **0 means it didnt**

---

# Pseudo-algorithm (Address accessing)
Consider a cache of `n` lines and the address: 
![[Pasted image 20220714165254.png | 150]]

- `Reset:`
For each address, set the `validity bit` to 0
![[Pasted image 20220714165431.png]]
- `Check:` if the address exists **cache**
if the validity of the current index is zero then we got a `cache miss`
if the tag of the current index != to tag of the address then `cache miss`
otherwise `Cache Hit`
![[Pasted image 20220714170018.png]]
- `Get:`
Do `Check` first, then load the byte at the position offset
- `Set:`
Do `Check` first, put `1` in the `dirty bit` , Modify the byte at the position offset.

## Transfer of data in response to a cache miss
1. Determine the RAM line $\large RL_i$ to be moved
	![[Pasted image 20220714170323.png]]
The address of the first byte in $RL_i = i*line\_length$ 
2. Determine the Cache line $CL_j$ to be replaced
![[Pasted image 20220714170850.png]]
3. Once `i` and `j` are determined, preform the following:
	- if $d_j =1$ move $CL_j$ to the corresponding RAM line $RL_k$ where 
	![[Pasted image 20220714171229.png]]
	Otherwise simply move $RL_i$ to $CL_j$
	- $v_j = 1$  |  $d_j = 0$ | $t_j = tag$

--- 

The disadvantage of `direct mapping` that some cache lines may not be used