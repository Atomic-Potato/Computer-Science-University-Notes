# Type of streams
## Text streams
- ordered sequence of characters composed into lines,
- each line consisting of zero or more characters plus a terminating new-line character
- data read in from a text stream will necessarily compare equal to the data that were earlier written out to that stream only if
	- the data consist only of printable characters and the control characters horizontal tab and new-line,
	- no new-line character is immediately preceded by space characters, and
	-  the last character is a new-line character
## Binary stream
- ordered sequence of characters (=bytes) that can transparently record internal data
- data read in from a binary stream shall compare equal to the data that were earlier written out to that stream under the same implementation
- may, however, have an implementation- defined number of null characters appended to the end of the stream

# File Pointers
`<stdio.h>` contains a definition for a type `FILE` that is used to define the pointer type to point to an opened file

# Standard streams
`stdin` input buffering [by default: keyboard]
`stdout & strerr` output [by default: screen]
