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
- None of not key attributes depends on a part of a key (elementary functional dependency)
	*Example:*
	R=(A,B,C,D)
	Key = {A,B} -> R
	and we have B->C and so R is not in normal form _(i think thats the right way to say it)_

## `BCNF`
if for all functional dependencies in `F+` of the form  X->Y , where X belongs to R and  Y belongs to R, at least one of the following holds:
- a->b is trivial (i.e. b belongs to a, or a is b)
- a is [[! Important Definitions & Notes !#^superKey|super key]] for R

## `3NF`
It is basically BCNF but it helps us decompose any relation with an extra condition
- a->b is trivial (i.e. b belongs to a, or a is b) **(BCNF)**
- a is super-key for R **(BCNF)**
- **Each** attribute A in `b-a` (*example:* AB->BC => BC-AB = B, but most of the times its just b) is contained in  [[! Important Definitions & Notes !#^candidateKey |candidate key]] for R.

# Decomposition
## `BCNF` decomposition
![[Pasted image 20220830180151.png | 150]]

>If a relation is not in BCNF we decompose it with the following steps:
>- For every FD that is not in BCNF, make 2 relations
>	- First relation contains the attributes in the FD that is not in BCNF (calll it X) and the FDs that contain attributes from the attributes of X only. Which makes this relation automatically in BCNF.
>	- Second Relation contains the attributes of all FDs that are **not in the First Relation**
>	- Repeat same steps for the second relation if its not in BCNF

(However this decomposition is not always successful, because sometimes the decomposition will fail to preserve some FD when [[🟩2 @ Formal Languages#Natural Join|naturally joint]] back)
*Example of a non preserving relation decomposition:*
![[Pasted image 20220830182131.png | 200]]
Where JK->L cannot be preserved no matter how we decompose it

*Example on this decomposition:*
![[Pasted image 20220830181746.png | 500]]



## `3NF` decomposition
This decomposition solves the problem of BCNF decomposition
![[Pasted image 20220830182250.png | 250]]

>- Get the  [[🟩1 @ Normaliztion Process#Canonical Cover F_c|canonical cover]] $F_c$ of F
>- Turn each each `FD` in $F_c$ into a relation with the attributes of the FD
>- At the end if none of the schemas/relations contains a candidate key for R then make a relation containing the attributes of the candidate key (which is $R_{n+1}$)

*Example:*
![[Pasted image 20220830182728.png | 500]]