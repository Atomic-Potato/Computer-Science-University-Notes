In the system POV we will see:
- How does the FS allocate blocks on disk
- How does the FS implement files

# Allocation Techniques
There are several techniques to decompose and store files on disk:
- [[#Contiguous Allocation]]: one contiguous group of disk blocks are used
- [[#Linked Allocation]]: multiple disk blocks are used, linked together
- [[#Linked Allocation With Indices]]: multiple disk blocks used, with their addresses recorded in an index
- [[#UNIX I-Node]]: multiple disks, with direct or indirect pointers to each block

## Contiguous Allocation

## Linked Allocation

## Linked Allocation With Indices

## UNIX I-Node