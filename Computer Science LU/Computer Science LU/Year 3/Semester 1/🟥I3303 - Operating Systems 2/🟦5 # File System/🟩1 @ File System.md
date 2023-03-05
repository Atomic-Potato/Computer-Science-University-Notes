The file system is a module in OS responsible for storing & retrieval of data on secondary storage system.

The advantages of FS:
- Managing file structuring, naming, accessing, using, protecting, & implementing
- Sharing of data: Multiple processes that access the same data
- Protection of data
- Long-term storage in units called files

# Hard Drive Format
A hard drive is basically a bunch of disks _(Heads)_ stacked on top of eachother.
![[Pasted image 20230305134950.png|300]]

Each disk is made out of **cylinders/tracks**. And its also composed of sectors. _(best shown in the image)_
![[Pasted image 20230305135155.png|300]]

Now i think data is stored in a sector, so now if we want to get the address of some data we use the format:
$$\color{green}\large (Head, Cylinder, Sector)$$

In the **memory**, read/write is made in **bytes**.
In the **disk**, access is made in **sector/block**

# Views
There are 2 views of working with data:
- [[🟩2 @ User Point of View|User view]]:  user speaks to files _(a set of bytes/data)_
- [[🟩3 @ System Point of View|System view]]: system speaks to collection of disk blocks containing files

# FS Job
The FS job is to translate **file descriptor and offset** to which disk block to access.

## File
A file is a unit of storage. Files are managed by the FS.

The following actions on files are managed by the FS:
- Structured
- Named
- Accessed
- Used
- Protected
- Implemented

## Time to get data from disk
Approximate time to get data = 
$$ \color{cyan} seek \space time (ms) + rotational \space delay(ms) + bytes/disk \space bandwidth$$
