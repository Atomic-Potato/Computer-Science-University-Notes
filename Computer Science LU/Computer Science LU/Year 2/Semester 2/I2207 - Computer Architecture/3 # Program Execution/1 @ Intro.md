![[Pasted image 20220613205811.png]]

# Machine Cycle
A machine has tow cycles (i think thats what you call it):
- `Instruction time:` Fetch, Decode
- `Execution time:` Execute

![[Pasted image 20220613210205.png | 400]]

# Instruction execution
Several types of registers are used to execute an instruction:
- `Program Counter (PC):` contains the address of the next instruction to be executed.
- `Memory Address Register (MAR):` contains the address to be read or written. (Passed on by the PC)
- `Memory Data Register (MDR):` contains both instructions and data.
- `Instruction Register (IR): `contains the current instruction being executed.
- `ALU Input/Output registers:` AX, BX (data) AC (accumulator)