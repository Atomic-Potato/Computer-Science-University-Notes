`fopen()` to open files
`freopen()` to reopen files duh
if you use reopen on `stdout` then for example if you use printf for example, the output wont be written on the console, it will be written in the file reopened
`fclose()` to close files duh

# Opening Files
```c
#include <stdio.h>
FILE *fopen(const char *filename, const char *mode);
FILE *freopen(const char *filename, const char *mode, FILE *stream);
```
**Modes:**
![[Pasted image 20220209231453.png | 600]]
- opened with update mode "… + …"
	- both input and output may be performed
	- output may NOT be directly followed by input without a call to `fflush()` or to file positioning function `(fseek, fsetpos, or rewind)`
	- input may NOT be directly followed by output without a call to a file positioning function, unless the input operation encounters end-of-file.
	- opening (or creating) a text file with update mode may instead open (or create) a binary stream in some implementations
- `fopen():`
	- The function returns a pointer to the object controlling the stream or a null pointer if open fails
- `freopen():`
	- opens the file whose name is the string pointed to by filename and associates the stream pointed to by stream with it.
	- returns a value stream or a null if fails

# Closing files
```c
int fclose(FILE *stream);
```
- returns zero if succeeded or EOF if theres an error

