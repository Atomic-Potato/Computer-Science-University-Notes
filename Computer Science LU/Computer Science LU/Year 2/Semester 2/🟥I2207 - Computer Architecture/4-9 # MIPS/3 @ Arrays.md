# Static
- `Declaration`
```py
.data
	T: .word 0, 1, 0, 1 #Allocate 4 integers
	T: .space 16 #Allocate 16 bytes (remember that the size of each integer is 4 bytes)
```

- `Access`
```py
.text
	li $t0 0 #storing the address of the first int in $t0
	sw $t1 T($t0) #accessing the first integer and storing it in $t1
	
	addi $t0 $t0 4 #incrementing the address index
	sw $T1 T($t0) #storing the second integer
```

# Dynamic
- `Declaration`
```py
.text
	li $v0 9 # we use 9 to say we want to create a dynamic array
	li $a0 16 # $a0 must contain the number of bytes to be allocated
	Syscall # $v0 contains the address of the first byte allocated
```
- `Access`

T is replaced by the address 0
0(\$t0) equivalent to(\$t0) : address in \$t0

```py
sw $t1, ($v0) # store the first integer, $v0 can be replaced by $t0 
addi $v0,$v0, 4
sw $t1, ($v0) # store the second integer
```
