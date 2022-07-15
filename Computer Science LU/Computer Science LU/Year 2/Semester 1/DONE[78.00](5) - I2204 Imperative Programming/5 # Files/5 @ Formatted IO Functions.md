# INPUT
## `scanf` family
```c
int fscanf(FILE *stream, const char *format, ...);
int scanf(const char *format, ...);
int sscanf(const char *s, const char *format, ...);
```

### `scanf`
`fscanf` reads input from stream under control of format that specifies the admissible sequences and how they are to be converted for assignment, using subsequent arguments as pointers to the objects to receive converted
input. Returns the number of input items assigned

`scanf` is equivalent to `fscanf` with argument stdin

### `sscanf`
[My explanation: like fprintf but scanning from a string]
`sscanf` is equivalent to `fscanf`,  except that the argument s specifies a string from which the input is to be obtained, rather than from a stream reaching the end of the string is equivalent to encountering the end-of-file for the `fscanf` function

# OUTPUT
## `printf` family
```c
int fprintf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int sprintf(char *s, const char *format);
```

### `fprintf`
The `fprintf`  function is used to write multiple things into a file. For example
```c
fprintf(fileName, "i %d like %c potatoes, %s", 69, 'c', "Potato");
```
The `fprintf` function returns the number of characters transmitted

## `printf`
The `printf` function is equivalent to  `fprintf` with the argument `stdout` interposed before the arguments to `printf`.  It returns the number of characters transmitted.

### `sprintf`
The `sprintf` function is equivalent to `fprintf`, except that the argument `s` specifies an array into which the generated input is to be written, rather than to a stream.
A null character is written at the end of the characters written;
The function returns the number of characters written in the array, not counting the terminating null character.