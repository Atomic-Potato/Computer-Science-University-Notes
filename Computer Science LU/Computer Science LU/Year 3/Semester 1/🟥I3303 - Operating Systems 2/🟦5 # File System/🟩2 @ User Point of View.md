_Next [[🟩3 @ System Point of View]]_
_Previous [[🟩1 @ File System]]_

---

The point of view of a user, is how the user speaks to a file.

# File Naming & Extension
File name format:
```c
<name>.<extension>
```
When a process creates a file, it gives it a name. 
Each file has an extension.

# File Types 
![[Pasted image 20230305140922.png|600]]

# File Access
- `Sequential:` read/written in sequential order _(No jumping)_
- `Random:` data accessed in any order. The data to be accessed is specified using a key, record number, or file offset. _(Seek)_

# File Attributes
![[Pasted image 20230305141510.png|600]]

# File Operations
![[Pasted image 20230305141533.png|600]]

# Directories
Directories _(folders)_ are files themselves _(in UNIX)_. They contain entries about files information. Each directory entry includes: 
- name of file 
- file attributes, 
- location 
- [[🟩1 @ File System#Hard Drive Format|disk location]] _(block #)_

## Directory Systems
There are 2 types of directory systems:
- **Single level directory:**
	![[Pasted image 20230305141859.png|300]]
- **Multi-level directory system:**
	![[Pasted image 20230305141943.png|400]]

## Path to file
In Windows: 
```c
C:\folder\folder\folder\...\file
```
In Unix: 
```c
\folder\folder\folder\...\file
```

# I/O System Calls

## Open
Opening an existing file
```c
int open(char* fname, int flags, mode_t Mode); // Returns a file descriptor

// Flags: 
//       - O-RDONLY (read only)
//       - O-WRONLY (write only)
//       - O-RDWR (read write)
//       - O-APPEND (append)
//       - O-EXCL (exclusive)
//       - O-CREAT (create the file if not present)

// Mode (permissions):
//     user group owners (rwx rwx rwx)
```

## Create
Create a file
```c
int create(char* fname, mode_t Mode)
```

## Close
```c
int close(int fileDescriptor) // Returns: -1 if failure, else 0
```

## Read
```c
int read(int desc, void* buffer, int nb) // Returns number of bytes read
// read from "desc" to "buffer", "nb" bytes
```

## Write
```c
int write(int desc, void* buffer, int nb) // Returns number of bytes written
// write from "buffer" to "desc", "nb" bytes
```

---

_Next [[🟩3 @ System Point of View]]_
_Previous [[🟩1 @ File System]]_