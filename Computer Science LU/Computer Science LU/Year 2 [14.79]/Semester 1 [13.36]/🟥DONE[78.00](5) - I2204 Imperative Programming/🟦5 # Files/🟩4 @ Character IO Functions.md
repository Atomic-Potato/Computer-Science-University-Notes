# INPUT
## `fgetc()`
```c
int fgetc(FILE *stream);
```
obtains the next character (if present) as an unsigned char converted to an int, and advances the associated file position indicator.
if stream is at end-of-file, returns EOF

## `fgets()`
```c
char *fgets(char *s, int n, FILE *stream);
```
copies at most `n-1` characters into s and returns s
a null character is written immediately after the last character read into the array.
returns `NULL` if failed
## `getc()`
```c
int getc(FILE *stream);
```
The `getc` function is equivalent to `fgetc`, except that it may be implemented as a macro.
The `getc` function returns the next character from the input stream pointed to by stream.

## `getchar()`
```c
int getchar(void);
```
 `getchar` is equivalent to `getc` with argument stdin.
 
 ## `gets()`
 ```c
char *gets(char *s); 
```
 `gets` is equivalent to `fgets` with argument stdin.


# OUTPUT
## `fputc()` writes a character into the file 
```c
int fputc(int c, FILE *stream);
```
`fputc` writes the character specified by c (converted to an unsigned char)  at the position indicated by the associated file position indicator,

If the file cannot support positioning requests, or if the stream is opened with append mode, the character is appended to the output stream.

returns the character written 

## `fputs()` writes a complete string into the file
```c
int fputs(const char *s, FILE *stream);
```
`fputs` writes the string pointed to by s The terminating null character is not written.

## `putc()`
```c
int putc(int c, FILE *stream);
```
`putc` is equivalent to `fputc` except that if it is implemented as a macro

## `putchar()`
```c
int putchar(int c);
```
`putchar` is equivalent to `putc` with the second argument `stdout`.

## `puts()`
```c
int puts(const char *s);
```
`puts` writes the string pointed to by s and appends a new-line character to the output.
The terminating null character is not written