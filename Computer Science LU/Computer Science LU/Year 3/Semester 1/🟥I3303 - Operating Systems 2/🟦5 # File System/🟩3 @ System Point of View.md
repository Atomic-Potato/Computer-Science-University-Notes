In the system POV we will see:
- How does the FS allocate blocks on disk
- How does the FS implement files

# Allocation Techniques
There are several techniques to decompose and store files on disk:
- [[#Contiguous Allocation]]: one contiguous group of disk blocks are used
- [[#Linked Allocation]]: multiple disk blocks are used, linked together
- [[#Linked Allocation With Indices]]: multiple disk blocks used, with their addresses recorded in an index
- [[#Multi-level Indexed files: UNIX I-nodes]]: multiple disks, with direct or indirect pointers to each block

## Contiguous Allocation
In this technique files stored on consecutive blocks on disk:
![[Pasted image 20230305151221.png|600]]

**Advantages:**
- Simple
- Easy to implement
- Fast (minimum number of seek) 
  
**Disadvantages:**
- Fragmentation
	- Internal fragmentation: when a file doesn’t take a full block
	- External fragmentation: when size of file is decreased _(by removing data)_
	 - Solution: compaction
- If the size of a file increases & there is no free continuous space, I need to move the whole file -> overhead moving/copying -> **performance decrease**

## Linked Allocation
In this technique, files are not stored in a continuous way. The blocks are dispersed in a certain way. 

Linked lists are used for the OS to know the block of a given file.
Blocks of the same file are linked together with a linked list.
![[Pasted image 20230305151239.png|600]]
The address of the first block is stored on a row in the directory. This first block has a space in its data that points to the next block.

**Advantages:**
- No external fragmentation
- No problem if the size of a file grows

**Disadvantages:**
- Slow access _(sequential access)_
- Reliability _(If one pointer is lost, we lose access)_
- Size of block is reduced _(part of the size is taken for the pointer to next block)_
- If I want to read data from block n, I need to traverse all n-1 blocks to reach n

## Linked Allocation With Indices
_Also known as linked list with file allocation table (FAT) on WINDOWS_

This is the same as [[#Linked Allocation]] but instead of having to go through each block on the disk which takes a long ass time, we just loop over the **File Allocation Table** which just contains the indices of the linked list
![[Pasted image 20230305154915.png|400]]

**==NOTE:==** The FAT contains the indices of all files on the disk. Theres not an FAT  for each file.

_More explanation: https://youtu.be/V2Gxqv3bJCk_

**Advantages:**
- Faster access since there is no seeking inside disk, but rather the FAT is inside the memory so I only need to search the FAT table to reach the block.
- No loss for pointer memory since it is part of the Operating System

Disadvantages
- The entire table must be inside the memory all the time
- Suppose I have hard drive 20GB with 1KB block size  I need 20 million entries in FAT. Suppose each entry is 4B, then I need 224 B loaded in memory _(thats a big boy)_

## Multi-level Indexed files: UNIX I-nodes
We associate for each file a structure called `i-node`. This structure contains all meta-data about the file _(characteristics of the file)_ + the addresses on disk of the data blocks of the file.

**Fields contained inside the i-node:**
-  At first it contains meta-data related to the file _(size of file, number of blocks, reference count, last modified, mode/permissions…)_
- The next part has 13 entries _(depending on the version)_:
	- `0 to 9, direct pointer:` Contains direct addresses of the first till 10th block
	  ![[Pasted image 20230305172757.png|400]]
	- `10, single indirect pointer:` Starts when size(file) > 10 blocks. It points to a `map block` **with x amount of entries**. The map block contains address of the block
	  ![[Pasted image 20230305172319.png|500]]
	- `11, double indirect pointer:` Starts if the 10th map block is full. 
		- Points to map block. 
		- Each map block entry points to another map block _(MB2)_.
		- MB2 contains address of the block
		  ![[Pasted image 20230305172609.png|600]]|
	- `12, triple indirect pointer:` Starts when all 11 map blocks are full
		- Points to map block 1 _(MB1)_
		- Each MB1 entry points to MB2
		- Each MB2 entry points to MB3
		- MB3 entries contain address of block
		![[Pasted image 20230305180905.png|700]]

**==NOTE:==** The size of a map block is always the same size of a data block.

When the file is opened/created, the correspondent i-node is loaded into memory in another structure called memory i-node [[INSERT LINK]]

In UNIX, a single file can have multiple names in different directories. This is because a file is related to its i-node and not to its name.
Directory table now contains the file name & i-node number.

**Advantages:**
- Only the i-node for the file being processed is loaded into memory
- Large files can be sequentially or randomly accessed

**Disadvantages:**
- Blocks may still be scattered around the disk, resulting in many seek operations _(small disadvantage)_

# Directory implementation
In general, the directory is a file. Its content is not ordinary data. Instead, it contains information about files & subfolders in this directory.

Before a file can be accessed, the file must be opened. The FS uses the path name provided by the user to open a file.
The directory contains the information needed to find the disk blocks of a given file. The directory is also an array of entries, each related to a single subfolder/file in it.

## In Windows
An entry contains:
![[Pasted image 20230305182330.png|400]]

_For example:_
```c
fd = open("C:/user/tmp/toto.txt",…);
```
- Folders: _C, user, tmp_
- File: _toto.txt_

When the OS gets to the _"tmp"_ folder, it looks at its table, finds the _"toto.txt"_ file & gets the @ of its 1st block & the number of entry in the FAT _(if it is linked list)_

## In UNIX
An entry contains: `Filename (14Bytes), I-node # (2Bytes)`

**A directory itself is a file, which means it has its own I-node**
When the OS is loading, the content of the root directory is loaded into memory
![[Pasted image 20230305182524.png|600]]

### _Example_
Suppose we want to access the following file: _"/usr/ast/inbox"_

1. To access the file inbox, the FS needs to open its I-node and load it into memory.
2. To open the I-node, we should have its number
3. The I-node # is stored in the directory that contains the file inbox -> ast folder

**Steps: _(refer to the image below while following the steps)_**
1. In root directory, the I-node # of usr is 6 _(root table above)_ -> fetch from disk the I-node # 6 & load it in memory in a table called I-node memory _[[INSERT LINK]]_
2. I want to read the content of the directory usr -> read the data blocks of the I-node. Suppose block 0 _(direct block)_ in the usr I-node points to 132.
3. Fetch & load block 132 in disk. The data of this block is the array of entries of the usr folder. _(contains the I-node # & filename of each subfolder/file in it)_
4. The FS searches this block & suppose it finds the folder ast with I-node # 26
5. Fetch & Load I-node # 26  Read the data block 0 _(suppose it points to 400)_ -> fetch & load the block 400 from disk
6. Block 400 contains the entries of the ast folder. Suppose I find the file inbox with I-node # 60. -> found the I-node #
7. Fetch & Load the I-node 60 ino memory -> I can access the inbox file

![[Pasted image 20230305182607.png]]

# File System Implementation UNIX
The **physical formatting** of the disk is [[🟩1 @ File System#Hard Drive Format|heads, cylinders, sectors]]
![[Pasted image 20230305191528.png|600]]

The **logical formatting** divides the disk into **partitions**. A disk can be divided up to 1 or more partitions to hold multiple operating systems with their own file system. _(i think it may have been actually 4)_

In general, a disk is divided into:
- `MBR: master boot record` _(Sector 0)_ Used to boot the computer
  The end of MBR contains the partition table. It contains the information about the partitions in the disk
- `Disk partitions` _(can be many)_ It is part of a hard drive designed to hold FS. A partition is made up of a contiguous set of cylinders. _**Only one partition is active at a time.**_

![[Pasted image 20230305192056.png|600]]

## Structure of a Partition
When the computer is booted, the BIOS reads in the MBR and executes it
>`BIOS (Basic Input Output System):` software stored in the ROM designed by the hardware manufacturer

The MBR locates the active partition, reads the first block from the active partition _(boot block)_ & executes it

Each partition has the following structure:
![[Pasted image 20230305192248.png|500]]
The program stored in the `boot block` is executed and it loads the OS contained in that partition.

The `superblock` contains all the key parameters about the file system and it is loaded into memory when the computer is booted.

Superblock contains all key parameters about FS and is loaded into memory when the computer is booted. It contains:
![[Pasted image 20230305192406.png|600]]
_(The superblock is updated in case of any changes & saved to disk periodically)_

`I-nodes` start from block `2` to the `number(i-nodes)+1` 
Data blocks starts from `number(i-ndoes)+2` to the `nb(data blocks)-1`

# Opening a File
