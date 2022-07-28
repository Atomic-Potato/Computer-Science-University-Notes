A bad design is when theres:
- Repetition of information.
- Inability to represent certain information.

A good design is when we:
- Avoid redundant data
- Ensure that relationships among attributes are represented
- Facilitate the checking of updates for violation of database integrity constraints
# What is normalization

In general `normalization` is when a relational schema is:
- tested over example databases to evaluate its quality and correctness
- results are analyzed and corrections to schema are made
- corrections may be translated back to conceptual model to keep the conceptual description of data consistent

`Normalization` process **“decomposes”** the relational schemes to **remove redundancy** and **remove anomalies**

# Decomposition
Example on decomposition:
Consider this relation
![[Pasted image 20220726190301.png | 300]]

When decomposed we get these 2 tables:
![[Pasted image 20220726190428.png | 300]]
![[Pasted image 20220726190538.png | 150]]

This decomposition is useful so we dont loose information that rely on eachother when adjusting the first table and reduce storage space and redundancy.

Say for example we remove all the tuples with rating 5 in the main table, and then we add one tuple with rating 5 again, then we dont actually know what is the hourly wage of a rating five. But then in the last table we see that a rating 5 takes an hourly wage of 7.

## Decomposition properties
To avoid having problems when decomposing we use:
- The `lossless-join` property, which states that after decomposing, applying the **natural join** operation results in the originally decomposed relation
- The `dependency-preserving` property, which enforces a constraint on the original table

# Functional Dependencies
- `Existence dependencies:` The existence of B depends on A
- `Functional dependence:` he value of B depends on the value of A
	*Example:*
	- Student-Name is functionally dependent on Student-Id
	- Given the Student-Id, I can tell you the Student-Name

A `functional dependency` is a generalization of the notion of a `key`.

**Notation:**
Consider the following relation R = (A,B,C,D) and x = A,B,C and y = C,D and $\large \color{pink} x \rightarrow y$  (x determines y).

**Properties:**
- Whenever any two tuples t1 and t2 of R agree on the attributes x, they also agree on the attributes y.
	That is: $\large \color{pink} t_1[x] = t_2[x] \implies t_1[y] = t_2[y]$ 
-  `K` is a **super key** for relation schema R if and only if $\large \color{pink} K \rightarrow R$ **(make sure that K contains the least amount of attributes possible)**

If a relation **r is legal under a set F** of functional dependencies, we say that **r satisfies F** `(F |= r).`

# Closure of a set of FDs
The set of all functional dependencies logically implied by F is the closure of F
We denote the closure of F by  $\large \color{red}F^+$

We can find all of $F^+$ by applying  **`Armstrong’s Axioms`**:
- If $\large \beta \subset \alpha$ then $\large \alpha \rightarrow \beta$ `(reflexivity)` 
- If $\large \alpha \rightarrow \beta$ then $\large \sigma\alpha \rightarrow \sigma\beta$ `(augmentation)`
- If $\large \alpha \rightarrow \beta$ and $\large \beta \rightarrow \sigma$ then $\large \alpha \rightarrow \sigma$ `(transitivity)`

We can further simplify computation of $\large \color{red} F^+$ by using the following additional rules:
- If $\large \alpha \rightarrow \beta$ and $\large \alpha \rightarrow \sigma$ then $\large \alpha \rightarrow \beta\sigma$ `(union)`
- If $\large \alpha \rightarrow \beta\sigma$ then $\large \alpha \rightarrow \beta$ and $\large \alpha \rightarrow \sigma$ `(decomposition)`
- If $\large \alpha \rightarrow \beta$ and $\large \sigma\beta \rightarrow \theta$ then $\large \alpha\sigma \rightarrow \theta$ `(pseudo transitivity)`
(These rules can be inferred from Armstrong’s axioms.)

# Closure of Attribute Sets
The closure of `x` under `F` ( denoted by $\large \color{cyan}x^+$ )  is the s**et of attributes that are functionally determined by `x` under `F`**:
$$\large \color{cyan} \alpha \rightarrow \beta \space is \space in \space F^+ \iff \beta \subset \alpha^+$$
- **The algorithm to build the set of attributes $\large \alpha^+$:**
	![[Pasted image 20220728172821.png | 300]]
	- First it starts with itself
	- Then for each dependency in F, if the key belongs to the set of attributes
	- Then we add the attributes that depend on the key to the set


- **Checking if a set is minimal:**
	Take *R = (A,B,C,D,G,H,I)*
	And the set $\large AG^+$ (call it x) where x = R
	- First we check if AG -> R
	- Then if A -> R (A+ = R) if not then we cant give up A
	- Then if G -> R (G+ = R) if not then we cant give up G
	**If we cannot give up any attribute from the set then its minimal**

## Minimal Keys
Any attribute which **does not appear in the right member of a non trivial `FD`** of F, must be a good key candidate of R

*Example:*
>ADD = (street, city, zipcode),
>F = {  zipcode -> city,
>street, city -> zipcode }

(`street`, city) and (zipcode, `street`) are minimal keys

**`Important:`** 
If the set of the attributes of R which do not appear in right member of a non trivial FD of F is a key, then R possess an unique minimal key formed of the set of these attributes
==In other words, if an *attribute doesnt show in any FD*, and *the closure set of this attribute is R*, then **this attribute is a unique minimal key** for this relation,==

---
# Canonical Cover $F_c$
A canonical or minimal cover for a set F of functional dependencies FDs is a set $\large \color{cyan} F_c$ where:
- Every dependency in `Fc` is of the form `X->A`, **where A is a single attribute**.
- The closure $\large \color{cyan} F^+$ is equal to the closure $\large \color{cyan} F_c^+$ .

## Algorithm
- `Put the FDs in standard from:` Obtain a collection F c of equivalent FDs with a single attribute on the right side (using the decomposition axiom of Armstrong).
- `Minimize the left side of each FD:` For each FD in F c , check each attribute in the left side to see if it can be deleted while preserving equivalence to F + .
- `Delete redundant FDs:` Check each remaining FD in F c to see if it can be deleted while preserving equivalence to F + .

### _Or what i got from the course is by removing the `Extraneous` attributes_
Attribute A is `extraneous` if A is remove, then the set of functional dependencies implied by F doesn’t change.
The tow forms that dont affect F are:
- A`B` --> C & A --> C. Then `B` is extraneous
- A --> `B`C & A --> `B`. Then `B` is extraneous

**Note that this can be indirect!** like in this example: 
_A->B & B->C & A->CD_
By transitivity A->C and so A->CD becomes A->D
Or
_A->B & B->C & AC->D_
By transitivity A->D because A->C and so C->D and A->D thus we get A->C->D <=> A->D

*Example:*
![[Pasted image 20220728223514.png | 200]]
becomes:
![[Pasted image 20220728223529.png | 150]]
