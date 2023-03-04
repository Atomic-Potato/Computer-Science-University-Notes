Storing the page table in memory _(RAM)_ slows down the CPU performance. 
At the simplest case we need 2 memory references for each access:
1. CPU goes to the page table in RAM 2 get the frame number 
2. CPU goes to the frame number in the RAM

To increase speed we have 2 solutions:
1. The partial solution using TLB
2. The total solution using inverted page table

# TLB
For single level page table, there are 2 memory references at each memory access.

The rule of 90/10: Most programs tend to make a large number of references to a small number of pages _(for example looping over an array)_. Then why not cache these pages _(we wont talk about dis)_ or cache the entries of these pages in the page table.

TLB is a small device for mapping virtual addresses to physical addresses without going all the way to the page table _(its an associative memory)_.
This device is inside the MMU in the CPU and consists of a small number of entries _(max 64)_, each containing info about one page.
![[Screenshot_5.png|800]]

## Translation
The hardware checks to see if the virtual page is in TLB by comparing it to all entries simultaneously _(in parallel)_
_Recent accesses are in the TLB_
![[Screenshot_6.png]]
Entries of TLB are not indexed like in paging table. And the size of an entry of a TLB is a bit bigger than of a paging table.

## Visual representation of using TLB
First the CPU checks if the page number is in the TLB:
- if so get the frame number and go to the memory
- if not go find it in the pages table:
	- If its in the page table, update the TLB and get the frame and go to the memory
	- Else, load the page from disk, put it in the page table, update TLB and go to memory
	![[Screenshot_7.png]]

Same process but represented in a different diagram: [[Fetching pages from TLB (Diagram)]] **_(MAKE SURE YOU HAVE EXCALIDRAW PLUGIN INSTALLED)_**

# Inverted Page Table
The idea of this method is to make a single global page table related to the physical memory and not related to the process itself. 

The inverted paging table includes an extra field that is **the process id**
![[Pasted image 20230303180014.png]]

To translate from logical address to physical, first we decompose the logical address as usual:
![[Pasted image 20230303180126.png|300]]
And we already have the process id, no need to include it in the address.
Now the MMU makes a search in the inverted paging table.

There are 2 kinds of searching algorithms:
- `Linear:` row by row
- `Non linear:` using a hashing page table

## Linear search
Search row by row until it finds the matching couple _(page number, process id)_.
If its not found then we get a **page fault**, load the page from the disk and update the correspondent frame entry in the page table.

## Non Linear search
In a nutshell, you shove _(page number, process id)_ in a hash function, you get a key which can be used as an index in the page table.

Theres a chance that collisions might happen _(different value might produce the same hash key)_.
It can be solved using a linked list table to store them in an array/hash table.