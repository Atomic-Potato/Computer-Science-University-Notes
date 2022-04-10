# Intro
## Command Line Structure
![[Pasted image 20220129144646.png | 600]]
The `command prompt` is automatic, it specifies which type of shell we are using, the `%` means we're using the shell written in the C language.

You dont have to remember what commands do as well, you can just insert the following command
```C
man [command]
```
which will print out the manual of that command.

## Some Basic Commands
- Actually useful:
	- `man` - find and display system manual pages
	- `cat` - displays the content of a file
	- `ls` - lists files in current directory 
	- `date` - displays date and time
	- `who` - displays who is on the system
	- `clear` - clears the terminal screen
	- `wc` counts words`[-w]` lines`[-l]` and characters`[-m]`
	- `head -n "max_line" file` catches the lines from first line to the line we decide
	- `tail -n "max_line" file` same as above but from the bottom, not that the indexing starts from 1 
- Not so used:
	- `passwd`  - Changes password
	- `less` - show contents of file
	- `logout` - logouts from system
	- `script` - make record of a terminal session
	- `uname -a` - prints current OS details (version etc.)

### What does the command `man` contain
![[Pasted image 20220129145331.png | 400]]

Syntax of `man`
```C
man [options] [-S section-number] [command-name]
```

# The UNIX File System
## File system layout
![[Pasted image 20220129153106.png | 500]]
`bin` Essential command binaries
`boot` Static files of the boot loader
`dev` Device files
`etc` Host-specific system configuration
`lib` Essential shared libraries and kernel modules
`media` Mount point for removable media
`mnt` Mount point for temporary file systems
`opt` Add-on application software packages
`proc` data on running system
`root` home directory for system administrator
`sbin` Essential system binaries
`srv` Data for services provided by this system
`tmp` Temporary files
`usr` Secondary hierarchy
`var` Variable data

## Directory Terminology 
-  Root Directory: `/`
top-most directory in any UNIX file structure
-  Home Directory: `~`
directory owned by a user
default location when user logs in
-  Current Directory: `.`
default location for working with files
-  Parent Directory: `..`
directory immediately above the current directory

A path that starts from the `root` folder is called an `Absolute Pathname` otherwise if it starts from another folder its called `Relative Pathname`

## File System Commands Categories (with examples)
- `Provide information`
	- pwd (gives the full pathname of the current working directory)
	- ls
- `Change view`
	- cd
- `Change`
	- mkdir
	- rmdir

## List Directory Content
Syntax:
```C
ls options pathname
```
If pathname wasnt included then `ls` will be applied to the current directory
`ls` Options:
![[Pasted image 20220129155329.png | 400]]

### Useful directory options
- `ls -Alst | less`
	-  `-A` include hidden files
		-  “dot files” start with .
		-  `-A` lists all except . and ..
		-  `-a` lists all including . and ..
	-  `-l` long format
	-  `-s` show size of each file in blocks
		-  1K blocks on some systems
		-  1/2 K blocks on other systems
	- `-t` in reverse time sequence (most recent first)
	- piping into `less` prevents running off end of screen

### reading `ls` output
![[Pasted image 20220129155721.png | 600]]

## PERMISSIONS: TERMINOLOGY
-  `user`
	- any one who has account on the system
	- recognized via a number called “user id”
- `super user`
	- “root” user, also known as system administrator
	- has user id “0”
	- has the maximum set of privileges in the system, i.e.
	no restrictions apply to what “root” can do
- `group`
	- users are organized into groups
	- user can belong to multiple groups

## Security Levels
-  `System security`
	- controlled by the super user
-  `Directory and file`
	- controlled by the user who owns them

## Access Permission Types
`r` read 
`w` write
`x` execute
`-` permission denied
![[Pasted image 20220129160232.png | 400]]

## Categories of users
![[Pasted image 20220129160310.png | 400]]
in the `ls` the first bit is split into 3 parts to indicated how can each user category work with the file/folder
note that the first character could be either `d` or `-` meaning its either a `directory` or a `file`

## The `chmod` Command
which i think stands for change moderation, just changes `r,w,x` permission for user categories
**Syntax:**
```C
chmod [options] [modes] [file-or-directory]
```
`options` have only one `-R: recursive` and i dont really know what it does

**`modes:`**
**Syntax**
```
WhoOperatorPermissions
```
- `who:`
	- `u` for user
	- `g` for group
	- `o` for other
	- `a` i cant really remember
- `Operator:`
	- `=` sets in the wanted permissions no matter what the current ones are
	- `+` adds in the permission
	- `-` removes the permission
- `Permissions:` r,w,x

Example  
```C
chmod u=rwx,g+w,o-w memo.doc
```

### Changing perms (Octal method)
![[Pasted image 20220129161328.png | 500]]
just add in the octal value for each user and put the result, you can set 0 to remove all permissions 

## File Name Expansion
Wildcard characters allow to select files that satisfy a particular name pattern
![[Pasted image 20220129161537.png | 500]]

## Creating a new Directory
Syntax
```c
mkdir [-p] directory-list
```
`directory-list:` the new folder path
`-p` if any folders in the path are not created, they will be created
note that on folder creation, the current execution path will not change

Avoid the following characters when creating a name for a folder or a file
![[Pasted image 20220130150246.png | 250]]

## Changing Directory
Syntax
```cd
cd [-option] path-name
```

## Remove Directories
Syntax
```C
rmdir path-name //if folder is empty
rm -r path-name //if folder is not empty
```

## Copying Files
Syntax
```C
cp [-options] source destination
// you can have multiple sources
```
The options
- `-i` if “target” exists, the command `cp` prompts for confirmation before overwriting `-i` is not the default, but should be you can make `-i` the default
- `-p` preserve permissions and modification times `-p` is not the default, but should be you can make `-p` the default
- `-r` recursively copy files and subdirectories

## Moving Files
Syntax:
```C
mv sauce destination
//you can also rename files as well if you set the file name in the destination to something different
//you can have multiple sauces
```

## Deleting file
Syntax
```C
rm [-options] file-sauce
```
- `-f` force remove regardless of permissions
- `-i` prompt for confirmation before removing
- `-r` removes everything under the indicated directory

## Linking files
 There are two types of links
 - soft link or symbolic links, just like shortcuts in windows
 - hard link is like a shortcut but if deleted / edited, the original file will also be deleted / edited

Syntax
```C
ln -s file link-file //for soft link
ln shared-file link-name //for hard link
```
Other options are:
- `-i` interactive
- `-f` force

Note that the long listing (ls -l) of a soft link does not accurately reflect its associated permissions.
To view the permissions of the file or directory that the symbolic link references, use the -L option of the ls command.

![[Pasted image 20220130153947.png | 400]]
![[Pasted image 20220130154135.png | 400]]
## Finding Files
```C
find pathname-list -name expression
```
“find” recursively descends through pathname-list and applies expression to every file