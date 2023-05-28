# Opening, Closing, Creation & Deletion
- `Touch("filename")` If file doesn’t exist, create it. Else, change date of modification
- `Unlink("filename/path")` Deletes a file
- `Fopen("path", "r/w/a")`: open a file in read/write/append. And returns file pointer resource or returns false
- `Fclose("filePointer")`: closes file. Returns true or false

# Reading
- `Fgets("filePointer")`: reads line by line
- `Feof("filePointer")`: returns true if EOF
- `Fread("filePointer", "length-in-bytes")`: read length of bytes
- `Fgetc("filePointer")`: read character by character

# Writing
- `fwrite("filePointer", "string")`: writes  string to file
- `fwrite("filePointer", "string", "length")`: write  length size of  string  to file

# Misc.
- `readfile("filePath")`: Reads a whole file & writes it to the output buffer. No need to open the file first. And it returns the number of successfully read bytes
- `File("path")`: reads the whole file & returns the content in an array

# Other
![[Pasted image 20230128143007.png|700]]