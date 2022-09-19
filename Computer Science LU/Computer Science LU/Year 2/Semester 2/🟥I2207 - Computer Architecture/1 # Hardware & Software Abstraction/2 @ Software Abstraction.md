Passage from a high-level language to a lower level language understood by
the machine via several intermediate languages is what we will talk about in here.

# Layers Architecture
![[Pasted image 20220605193517.png | 400]]
**Ax** and **Bx** are two registers (small memories)
**Sub, Add, Mul,** … are mnemonics (functions)

# Von Neuman Machine
![[Pasted image 20220605193622.png]]
`Arithmetic and Logic Unit (ALU)`: preforms computation (+,-,\*,/,…)
`Register`: a small memory that usually holds 32 or 64 bits (32-bit or 64-bit CPU).

## Buses
`Buses` are used to transfer data between input devices, memory, and CPU.

Three types of bus exist:
- Control bus (unidirectional)
![[Pasted image 20220605193839.png]]
- Address bus (unidirectional)
![[Pasted image 20220605193839.png]]
- Data bus (bidirectional)
![[Pasted image 20220605193839.png]]

The control unit sends orders (read/write) via the control bus
The control unit sends addresses via the address bus
CPU and Memory exchange data (information) via the data bus