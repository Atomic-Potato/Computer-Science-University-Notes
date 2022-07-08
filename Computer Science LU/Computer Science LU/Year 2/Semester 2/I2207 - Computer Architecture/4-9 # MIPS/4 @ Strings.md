# Static declaration
```py
.data
	StringName: .asciiz « Text »
```
A string is terminated by the null character `‘\0’`. The null character has the position 0 in the ASCII table.

- Manipulating a string:
	- `Load a byte:` **lb $t0, T(address)** # Set the lower 8 bits of $t0 to the byte loaded. The remaining bits are set to 0.
	- `Store a byte:` **sb $t0, T(address)** # Store the lower 8 bits of $t0 in T.

2nd way:
```py
.data
	StringName: .space NumberOfBytes
```

## Reading a string
- Method 1:
\$v0 <- 8
\$a0 <- address of the String
\$a1 <- Number of characters to read syscall

- Method 2:
Use a loop including:
$v0 <- 12 # Read a character
syscall # $v0 contains the entered character

## Printing a string
- Method 1:
\$v0 <- 4
\$a0 <- @ String
syscall

- Method 2:
Use a loop including:
\$v0 <- 11 # print a character
\$a0 <- character
syscall 

--- 
# Dynamic Declaration
- Syntax:
	\$v0 <- 9
	\$a0 <- Number of bytes `Just like an array`
	Syscall