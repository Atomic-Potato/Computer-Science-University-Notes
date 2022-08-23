![[Pasted image 20220613205811.png]]

# Machine Cycle
A machine has tow cycles (i think thats what you call it):
- `Instruction time:` Fetch, Decode
- `Execution time:` Execute

![[Pasted image 20220613210205.png | 400]]

# Instruction execution
Several types of registers are used to execute an instruction:

- `Program Counter (PC):` contains the address of the next instruction to be executed. ^PC

- `Memory Address Register (MAR):` contains the address to be read or written. (Passed on by the PC) / When the CPU needs to send an address to the memory, it gets placed in the MAR ^MAR
- `Memory Data Register (MDR):` contains both instructions and data / When the memory wants to return a value to the CPU or vice versa, it is placed in the MDR  ^MDR
- `Instruction Register (IR): `contains the current instruction being executed. ^IR
- `ALU Input/Output registers:` AX, BX (data) AC (accumulator) ^ALUio

*Example*
Suppose we want to execute the **Add\[0]\[1]** operation
![[Pasted image 20220821180832.png | 150]]

**Steps:**
1. PC <- 100
2. MAR <- PC 
   _(So this means MAR needs to go fetch whats in address 100 and place it in the MDR)_
3. MDR <- Add\[0]\[1] 
   _(But we cant really keep it here because we still need to fetch whats in addresses 0 and 1)_
4. IR <- Add\[0]\[1] 
   _(So its placed in here instead, and the CPU needs to execute the instruction)_
5. MAR <- 0
6. MDR <- 5
   _(This now gets sent to the arithmetic and logic unit)_
7. MAR <- 1
8. MDR <- 7
9. MAR <- 0 
   _(Since the Add needs to store the result in 0)_
10. MDR <- 12