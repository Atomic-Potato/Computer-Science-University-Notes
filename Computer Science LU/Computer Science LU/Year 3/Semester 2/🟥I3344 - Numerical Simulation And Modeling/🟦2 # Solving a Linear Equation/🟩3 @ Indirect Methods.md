I aint gonna even bother show how we got these methods, all im just gonna show how to use them

# Jacobi
Ax = B

![[Pasted image 20230621192643.png]]
Ax = B 
=> (Q-P)x = B 
=> Qx -Px = B
=> Dx + (L+U)x = B
![[Pasted image 20230621192955.png]]

## Condition
The coefficient matrix must be diagonally dominant, that is:
![[Pasted image 20230621193048.png]]
![[Pasted image 20230621193102.png]]


## How to use it
![[Pasted image 20230621193152.png]]

### First way
![[Pasted image 20230621193237.png]]

### Second way
![[Pasted image 20230621193306.png]]



# Gauss Seidel
This is an improvement over [[#Jacobi]]

## Condition
To use it, the coefficient matrix has to be [[#Condition|diagonally dominant]]

**if not** then it has to be:
- Symmetric, that is it equals its transpose
- Positive definite
  ![[Pasted image 20230621193644.png]]
  ![[Pasted image 20230621193653.png]]

## Usage
![[Pasted image 20230621193858.png]]

### First way 
![[Pasted image 20230621193915.png]]

### Second way
![[Pasted image 20230621193939.png]]