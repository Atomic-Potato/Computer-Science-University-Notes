# Loops
Basically branches and jumps combined:
```py
li $t1 0 #index
While: beq $t1 $t0 Break #Condition
	#instructions
	j While #Loop again
Break: #Stop
```
