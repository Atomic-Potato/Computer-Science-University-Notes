I aint gonna even bother show how we got these methods, all im just gonna show how to use them

# Jacobi
Ax = B

![[Pasted image 20230621192643.png]]
Ax = B 
=> (Q-P)x = B 
=> Qx -Px = B
=> Dx + (L+U)x = B

## Convergence Condition
The coefficient matrix must be diagonally dominant, that is:
![[Pasted image 20230621193048.png]]
![[Pasted image 20230621193102.png]]

**OR**

![[Pasted image 20230708170131.png]]

> To calculate the infinity norm:
> 1. For each row of the matrix, sum the absolute values of the elements in that row.
> 2. Identify the row with the largest sum.
> 3. The infinity norm of the matrix is equal to the maximum sum obtained in step 2.


## How to use it
![[Pasted image 20230621193152.png]]

### First way
![[Pasted image 20230621193237.png]]

### Second way
![[Pasted image 20230621193306.png]]

## Another way to explain it
https://youtu.be/VH0TZlkZPRo
![[Pasted image 20230708171349.png]]
![[Pasted image 20230708171423.png]]
![[Pasted image 20230708171436.png]]


# Gauss Seidel
This is an improvement over [[#Jacobi]]

## Convergence Condition
for this method to be convergent, the coefficient matrix has to be [[#Condition|diagonally dominant]]

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