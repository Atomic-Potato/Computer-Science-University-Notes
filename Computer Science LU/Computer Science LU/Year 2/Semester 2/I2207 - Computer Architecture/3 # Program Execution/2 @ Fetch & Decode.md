# Fetch
Consider the 1-address machine with 3 operations: load, add and store.

The address of the next instruction to be fetched is in PC.
$$MAR<--PC$$
- The CU request to read data from the Memory
- The CU sends the address of the data to the memory
- The memory sends the data to the Memory Data Register
- The MDR puts the instruction in the Instruction Register
![[Pasted image 20220613210813.png]]

# Decode
The address to the next instruction gets sent to the PC:
$$PC <-- PC + 1$$
Then the instruction is split into operation code and operand
![[Pasted image 20220613211836.png]]

