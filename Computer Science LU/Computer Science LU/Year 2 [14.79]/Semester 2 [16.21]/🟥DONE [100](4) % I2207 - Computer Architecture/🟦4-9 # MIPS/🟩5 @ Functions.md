# Procedure / Function
- `Procedure:` a bloc of instructions that performs a specific task
- `Function:` is a procedure that returns a value

Calling a function involves two participants:
- `Caller:` calls the function. It sets up arguments to the function, and then jumps to the function.
- `Callee:` the function itself

## Function definition (by convention):
1. `header`
	Function Name: Label
	Input (up to 4 arguments or parameters) : in \$a0-\$a3
2. `body`
	A bloc of instructions that define what the function does
3. `footer`
	Output (up to 2 values): in $v0, $v1
	Jump back to the caller

## Calling a function
The caller uses the operation **`jal (jump-and-link)`** to call the function *(callee)*.
Syntax:
```py
jal Label #Label is the name of the function
```
`jal` saves the return address **(the address of the next instruction)** in `$ra`, before jumping to the function.

To jump back to the caller, the callee(function) has to **jump to the address that was stored in `$ra` using the operation `jr`**.
Syntax
```c
jr register
```

--- 
# Nested functions
The problem with nesting functions is that `jal` **overwrites** the return address stored in `$ra` by the calling function

In **C language**: Local variables in `f(int a, int b) and g (int a, int b)` are different. 

But in **MIPS** Temporary registers `$t0-$t9 and $s0-$s7` are shared between functions (as global variables). The callee may overwrite some registers that the caller still needs them.

## Sharing temporary registers between functions
To solve this problem, we share the backup and restore task between the caller and the callee.

There's two types of registers (by convention):
- `Caller-saved` (12 registers): \$v0-\$v1, \$t0-\$t9
- `Callee-saved` (12 registers): \$a0-\$a3, \$s0-\$s7

The caller saves and restores any caller-saved registers that it cares about.
The callee saves and restores any callee-saved registers that it uses.

## Where to save registers contents?
A `stack` is a part of the **RAM**. In MIPS, the stack **grows downward in terms of memory addresses.**
The address of the top element is stored in `$sp` (stack-pointer register).
![[Pasted image 20220708182935.png]]

### Stack operations
- `Push`
```py
$sp <- $sp -4 # Allocate memory. Decrement stack pointer by 4
sw $t1, ($sp) # Store
```

- `Pop`
```c
lw $t1, ($sp) # Load
$sp <- $sp +4 # Free memory. Increment stack pointer by 4
```

`Note that you cant use it as an array, because it will, as stated above, free the memroy`
