# `fseek()` and `ftell()`
```c
int fseek(FILE *stream, long int offset, int whence);
long int ftell(FILE *stream);
```
**`fseek` function sets the file position indicator**
- for a binary stream,
	- the new position, measured in characters from the beginning of the file,
	- is obtained by adding offset to the position specified by whence.
- 3 macros in stdio.h:
	- whence = SEEK_SET -> position is the beginning of the file
	-  whence = SEEK_CUR -> position is the current file position
	-  whence = SEEK_END -> position is the end of the file
- returns nonzero only for a request that cannot be satisfied 

**`ftell` obtains the current value of the file position indicator**
- for a binary stream,
	- the value is the number of characters from the beginning of the file;
- for a text stream,
	- unspecified information,
	- usable by the `fseek` function for returning the file position indicator for the stream to its position at the time of the `ftell` call;
- returns current value of file position indicator if success

# `fflush()`
```c
int fflush(FILE *stream);
```
**`fflush` causes any unwritten data for that stream to be deferred to the host environment to be written to the file; If stream is a null pointer, `fflush` performs this flushing action on all streams**

# `rewind()`
```c
void rewind(FILE *stream);
```
sets the file position indicator to the beginning of the file.

# `feof()`
```c
int feof(FILE *stream);
```
 tests the end-of-file indicator and returns nonzero iff the end-of-file indicator is set for strem, otherwise 0
 