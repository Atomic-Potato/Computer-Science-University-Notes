# Fetch
Consider the 1-address machine with 3 operations: load, add and store.

The address of the next instruction to be fetched is in [[1 @ Program Execution Intro#^PC|PC]].
$$MAR \leftarrow PC$$
- The CU (Control Unit) request to read data from the Memory
- The CU sends the address of the data to the memory
- The memory sends the data to the Memory Data Register [[1 @ Program Execution Intro#^MDR|MDR]]
- The MDR puts the instruction in the Instruction Register [[1 @ Program Execution Intro#^IR|IR]]
![[Pasted image 20220613210813.png]]

# Decode
The address to the next instruction gets sent to the PC:
$$PC \leftarrow PC + 1$$
Then the instruction is split into operation code and operand
![[Pasted image 20220613211836.png]]

