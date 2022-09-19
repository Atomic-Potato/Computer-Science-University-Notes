MIPS is a load and store architecture that allows all operands to be register except for load ans store operations.
![[Pasted image 20220616113358.png]]
![[Pasted image 20220628184054.png]]
The above registers hold integer values only.

A MIPS program is composed of 2 parts: data and instructions

# Data
in the data part we store the variables
```mips
.data
	label: .typeInitialization
```
Example:
```mips
.data
	x: .word 3 #word is integer
	y: .word
	t: .asciiz "potato" #asciiz is string
```

# Instructions
A place to write instructions
```mips
.text
	#instructions
```

There's three types of instructions: ***R-type, I-type, J-type***

## R-type (Register type)
- `3 registers:`
	```mips
	add $t2, $t1, $t0
	div $t2, $t1, $t0 #divide
	```
i think it preforms the operation on `t1` and `t0` and then stores the result in `t2`

- `2 registers:`
	```mips
	move $t0, $t1
	div $t1, $t0    # since these registers only store integeres
					# the quotient is in the register LO(low)
					# and the remainder is in the register HI(high)
	```

- `1 register`
	```mips
	mflo $t2 # move the quotient from LO to t2
	mfhi $t3 # move the remainder from HI to t3
	```

## I-type (Immediate type)
- `load / store:`
	![[Pasted image 20220616114840.png]]
	- **lw:** load word : load whats in `x` into `$t0`
	- **sw:** store word : store whats in `$t0` into `x`
	- **la:** load address : put the address of `x` in `$t0`
	- **lb:** load byte: same as `lw` but for bytes / characters
	- **sb:** store byte: same as `sw` but for bytes / characters
- `immediate value:`
	Theres two types of operands:
	- **2 registers, 1 immediate value**
	```mips
	addi $t0, $t0, 1 #incrementation (idk how yet)
	```
	- **1 register, 1 immediate value**
	```mips
	li $t0, 1 #intializtion (same)
	```

### Branch: conditional opcode
- **Operands**
	- `2 registers, 1 label`
	```mips
	Beq $t0,$t1, Next # branch if equal
	Bne $t0,$t1, Next # branch if not equal
	Bgt $t0,$t1, Next # branch if greater than
	Blt $t0,$t1, Next # branch if lower than
	```
	- `1 register, 1 value, 1 label`
	```mips
	Beq $t0, 10, Next #if t0 == 10
	```
	- `1 register, 1 label`
	```mips
	Beqz $t0, Next #branch if $t0 contains 0	
	```

If the condition is true, the code reading will jump the label "Next" wherever you put it in the code
*Just note that you can name the label whatever you want*

## J-type (jump type)

- `j End:` jumps to the label End (note that the ':' is part of the syntax)
- `jal Min:` (used in functions) copies the address of the next instruction into the register `$ra` (return address) and then jumps to Min.
- `jr $ra:` jumps to the address in `$ra`


# If Else statements 
Syntax:
```python
branch_opcode operands (includes Label)
	#else instructions
label:
	#if instructions
```

Example:
```py
beq $t0,$t1, Next
	add $t2, $t0,$t1
	j End #because it will execute Next: if we dont do that
Next:
	sub $t2, $t0, $t1
End:
```



# Printing data
![[Pasted image 20220616115738.png]]

# Reading integers and ending the program
![[Pasted image 20220616131614.png | 300]]
