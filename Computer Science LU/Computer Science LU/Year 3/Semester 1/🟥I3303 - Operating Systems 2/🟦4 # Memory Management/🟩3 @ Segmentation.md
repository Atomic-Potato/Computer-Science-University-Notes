User's view of memory is not the same as the actual memory:
![[Pasted image 20230304105019.png|600]]
Here they are paged and somewhat scrambled. Therefore if multiple processes need to use some library, then its imported to their address space and paged, and so we have duplication / waste of space.

In segmentation each of _stack, heap, data, and code_ have a separate address space or **segments**.
Unlike pages, segments can be of different sizes.

It is similar to dynamic partitioning, the difference is that the segments do not need to be contiguous. It also eliminates internal fragmentation but suffers from external fragmentation.

# Segment Address
In paging, the virtual address is of the form: `(page number, offset)` _(which gives us the physical address)_
In segmentation, the virtual address is of the from: `(segment number, offset)`.

In each segment, the address starts with 0, i.e. each entity is simulated as if its a single program. Because of this changing the size of 1 procedure, does not require changing the starting address of any other procedure - a great time saver.
![[Pasted image 20230304110322.png|600]]

## Segment Table
The segment table keeps record of the segments as done by the paging table. It keeps record of:
- `Segment number`
- `Base:` The base/starting address of the segment
- `Length:` The length of the segment

If the address is `n+m bits`, where:
- `n` is the segment number. We use it to find the starting physical address by looking up in the segment table
- `m` is the offset

**Then the desired physical address is the sum of the starting physical address and the offset.**

![[Pasted image 20230304111344.png|700]]
Say the user wants the **data c**.
1. It fetches the base address _(1,2)_
2. The offset must be between 0 and the limit of that segment _(02 + 2 = 4 < 6 + 2 = 8)_
3. Get the data with the new physical address _(1, 04)_

# Segmentation VS Paging
![[Pasted image 20230304171518.png]]

Other important things about segments:
- **Segments allow sharing between processes** _(like sharing libraries)_. The library can be put in a segment and shared by multiple processes, avoiding the need to put the library in each process’s address space.
- **The user can put protection on each property/segment.** A function segment can be set to execute but not read or write.

# Segmentation With Paging
Since segmentation and paging deal with different things. Then why not use both?
- Paged segments
- Paging for memory allocation
- Segmentation for maintaining protection information at a coarse granularity
- Segmentation and paging in combination for translation

To do this:
1. The process is divided into segments
2. Each segment is divided into pages
3. `Logical address` becomes _**(segment #, page #, offset)**_
4. `Physical address` becomes _**(frame # * size(page)) + offset**_

![[Pasted image 20230304171952.png|500]]

# Important Exercise
**Keep in mind that we are going from segment table -> page table of one of the segments -> the frame a page is pointing to in the page table**
![[Pasted image 20230305091034.png]]
![[Pasted image 20230305091044.png]]
