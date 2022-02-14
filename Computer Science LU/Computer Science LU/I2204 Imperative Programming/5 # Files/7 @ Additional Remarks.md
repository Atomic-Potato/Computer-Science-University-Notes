# Sequential and random access file handling 
## The C stdio `fseek`, `ftell` and `rewind` Functions for use with Files
`rewind()` – return the file pointer to the beginning;

`fseek()` – position the file pointer;
Parameters:
- `FILE * f` – the file pointer;
- `long offset` – the position offset;
- `int origin `– the point from which the offset is applied. Which can be one of the three values:
	-  `SEEK_SET` – from the start;
	- `SEEK_CUR` – from the current position;
	- `SEEK_END` – from the end of the file.

`ftell()` – return the current offset of the file pointer.

`positioning the file pointer is absolute. In other words, if fseek is used to position the pointer in a read/write file, then writing will overwrite existing data, permanently.`

# The `while(!feof(f))` loop
Inside `!feof` loop, one should always check whether the input function succeeded or failed before further processing
![[Pasted image 20220210105647.png]]