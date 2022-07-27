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