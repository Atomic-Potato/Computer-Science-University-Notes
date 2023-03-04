User's view of memeory is not the same as the actual memory:
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
The segment table keeps record of the segments as done by the paging table.

If the address is `n+m bits`, where:
- `n` is the segment number. We use it to find the starting physical address by looking up in the segment table
- `m` is the offset

**Then the desired physical address is the sum of the starting physical address and the offset.**

![[Pasted image 20230304111344.png|700]]
Say the user wants the **data c**. Then he 