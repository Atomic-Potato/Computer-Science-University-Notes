# INPUT
## `fread`
```c
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
```
The `fread` function reads, into the array pointed to by `ptr`, up to `nmemb` elements whose size is specified by `size`, from the stream pointed to by `stream`.
The file position indicator for the stream (if defined) is advanced by the number of characters successfully read.
The `fread` function returns the number of elements successfully read, which may be less than `nmemb` if a read error or end-of-file is encountered.

# OUTPUT
## `fwrite`
```c
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
```
The `fwrite` function writes, from the array pointed to by `ptr`, up to `nmemb` elements whose size is specified by `size` to the stream pointed to by `stream`.
The file position indicator for the stream (if defined) is advanced by the number of characters successfully written.
The function returns the number of elements successfully written, which will be less than `nmemb` only if a write error is encountered.