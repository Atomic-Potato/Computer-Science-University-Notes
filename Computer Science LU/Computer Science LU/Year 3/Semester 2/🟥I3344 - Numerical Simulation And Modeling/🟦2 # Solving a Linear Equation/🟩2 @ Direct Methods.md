# Gauss Elimination
The idea of Gauss Elimination Method is to convert a linear System of
equations with a number of unknown variables to an augmented matrix
by putting the coefficients of unknowns in the 1st side of A* And the
solutions in the another side.

![[Pasted image 20230621183547.png]]


## Row operations
We apply row operations on the augmented matrix so we can get an upper matrix on the left side *(including the diagonal)*

We are only allowed to do the following operations on each row tho:
![[Pasted image 20230621183955.png]]

> The **pivot row** is the top most row that we dont touch, however we will learn later how to choose a pivot row to use it in our advantage


## Partial Pivoting
it is common to choose as the pivot row the row in which x1 has the largest (in absolute value) coefficient.
*(This is mainly to handle round-off error while dealing with large matrices.)*

![[Pasted image 20230621184304.png]]


> Example:
> ![[Pasted image 20230621184654.png|600]]
> ![[Pasted image 20230621184737.png|600]]



# Gauss-Jordan
The Gauss-Jordan method is a variation of Gauss elimination.
The major difference is that when an unknown is eliminated in the Gauss-Jordan method, it is eliminated from all other equations rather than just the subsequent ones.

**All rows are normalized by dividing them by their pivot elements**
The elimination step results in an identity matrix rather than a triangular matrix

It is not necessary to employ back substitution to obtain the solution.

## Example
![[Pasted image 20230621191313.png]]
![[Pasted image 20230621191410.png]]
![[Pasted image 20230621191422.png]]

# LU Decomposition
![[Pasted image 20230621191937.png]]

## Decomposition
First step is to factorize/decompose the matrix **into lower and upper part**
![[Pasted image 20230621191745.png]]
Now simply work your way down to figure out what is each coefficient in the lower and upper parts
![[Pasted image 20230621191901.png]]

## Substitution
![[Pasted image 20230621192030.png]]

## Conditions
This method cannot be applied however tho.
**An invertible matrix A has an LU decomposition provided that all its leading sub-matrices have non-zero determinants.**

> Example
> ![[Pasted image 20230621192429.png]]

