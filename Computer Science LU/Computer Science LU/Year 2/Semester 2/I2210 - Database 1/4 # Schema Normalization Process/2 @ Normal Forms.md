Given a relation schema, we need to decide whether it is a good design or whether we need to **decompose** it into smaller relations.
![[Pasted image 20220728223732.png | 150]]

We have several `normal forms (NF)` to find the quality and decompose a relation:
- `1NF`
- `2NF`
- `3NF`
- `Boyce-Codd NF (BCNF)`
Every relation in `BCNF` is also in `3NF`, every relation in `3NF` is also in `2NF`, and every relation `2NF` is in `1NF`.

# Normalization using Functional Dependencies
When we decompose a relation schema R with a set of functional dependencies F into R1 and R2 we want:
-  `Lossless-join decomposition`: At least one of the following dependencies is in `F+` :
	- $\large R_1 \cap R_2 \rightarrow R_1$
	- $\large R_1 \cap R_2 \rightarrow R_2$
	The attributes with which you can join R1 and R2 is **either a key of R1 or R2**
- `Dependency preservation:` Let `Fi` be the set of dependencies in `F+` that include only attributes in `Ri` . Test to see if:
	- $\large F_{R1} \cup F_{R2} = F^+$
	**Note:** a dependency  `X -> Y` in F+ is in $F_{R1}$ only if all attributes in X and Y are in R1.

# Normal Forms
## `1NF`
A relation is in `1NF` if every attribute **contains only atomic values**, that is, not lists or sets. _(Atomic values are values of an attribute that are tuples)_

## `2NF`
A relation is in second normal form if and only if:
- It is in first normal schema
- None of not key attributes depends on a part of the key (elementary functional dependency)
	*Example:*
	R=(A,B,C,D)
	Key = {A,B} -> R
	and we have B->C and so R is not in normal form _(i think thats the right way to say it)_

## `BCNF`
if for all functional dependencies in `F+` of the form  X->Y , where X belongs to R and  Y belongs to R, at least one of the following holds:
- X->Y is trivial (i.e. Y belongs to X)
- X is super-key for R

