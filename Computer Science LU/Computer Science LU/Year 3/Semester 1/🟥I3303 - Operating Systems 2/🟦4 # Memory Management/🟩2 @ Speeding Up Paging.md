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

## Visual representation of using TLB
First the CPU checks if the page number is in the TLB:
- if so get the frame number and go to the memory
- if not go find it in the pages table:
	- If its in the page table, update the TLB and get the frame and go to the memory
	- Else, load the page from disk, put it in the page table, update TLB and go to memory
	![[Screenshot_7.png]]

Same process but represented in a different diagram: [[Fetching pages from TLB (Diagaram)]] **_(MAKE SURE YOU HAVE EXCALIDRAW PLUGIN INSTALLED)_**

# Inverted Page Table
The idea of this method is to make a single global page table related to the physical memory and not related to the process itself. 

