# Format 1
**`A machine with a single type of instruction`**
![[Pasted image 20220613152702.png | 600]]
*Subtract the value stored in location 2 from that in location 1and then store the result in location 0. If the result is not zero then get the next instruction from location 102, otherwise get it from location 101.*
- Disadvantage: long instruction
![[Pasted image 20220613152828.png | 250]]

# Format 2
**`Three address machine: not all instructions need to change the order ofinstruction execution.`**
We need a register PC (Program Counter) to store the address of the next instruction.

So we split the previous instruction into two types:
- **ALU instruction**
![[Pasted image 20220613153040.png]]
- **Control Instruction**
![[Pasted image 20220613153102.png]]

*[JNZ: Jump Not Zero]*
![[Pasted image 20220613153141.png | 400]]
- Advantage: Reduce memory.
- Disadvantage: Two instructions to be executed but such operations are rare.

# Format 3
**`Two address machine: define a Mov operation (copy only).`**
It is useful in case of a=b.

- **ALU instruction**
![[Pasted image 20220613153331.png]]
- **Control instruction**
![[Pasted image 20220613153352.png]]

![[Pasted image 20220613153435.png | 400]]

# Format 4
**`One address machine:`**
- Use the register AC (accumulator).
- Define the operations load and store (Copy only).

- **ALU  instruction**
![[Pasted image 20220613153639.png]]
- **Control instruction**
![[Pasted image 20220613153700.png]]

![[Pasted image 20220613153759.png | 400]]

# Format 5
**`Zero address or stack machine: use Push and Pop operations.`**
![[Pasted image 20220613153905.png]]

Push [1]: move M[1] to the top of stack.
Pop [0]: move the top of stack to M[0].
Sub: pop the two top numbers from the stack, sub the numbers, and push the result into the stack.

*By M[x] we mean the value at the memory address x*

![[Pasted image 20220613154101.png | 400]]

# Format 6
**`Load/Store machine:`** (currently used format)
- Only load and store operations can access memory
- All other operations use registers as operands.