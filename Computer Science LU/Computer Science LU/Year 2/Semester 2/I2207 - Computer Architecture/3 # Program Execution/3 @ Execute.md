The address of the operand is put in the Memory Address Register
$$MAR <-- IR \space Operand$$
# Case 1: Opcode = Load
- CU asks memory to read data
- CU sends the address of the dat inside the MAR to the Memory
- The memory sends the data back to the Memory Data Register
- This data is then put inside the accumulator
![[Pasted image 20220613212341.png | 400]]

# Case 2: Opcode = Add
- The value of the accumulator is put inside the first variable AX
- repeat the first 3 steps in the first case
- The data of the MDR is put in the second variable BX
- CU tells the Arithmetic and Logic Unit to add AX and BX
- Then the ALU puts the result in the accumulator
![[Pasted image 20220613212556.png]]

# Case 3: Opcode = Store
- CU asks the Memory to write dat
- CU sends the address inside the MAR where to to store the data to the Memory
- The accumulator puts its data inside the MDR
- CU sends the data inside the MDR to the memory
![[Pasted image 20220613212911.png]]