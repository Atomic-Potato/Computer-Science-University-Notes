**Used to verify the inconsistency(a clause is false) of a set of clauses.**
S is `inconsistent` iff *the empty clause `[]` is a logical consequence of S*.

**`Reslution Rule:`** $\color{cyan}  \{A ∨ X,B ∨ ¬X\} ⊢ A ∨ B$

$\color{cyan} s_1 ∈ S$ and $\color{cyan} s_2 ∈ S$ and `l` is a literal. If$\color{cyan}  l ∈ s_1$and $\color{cyan} ¬l ∈ s_2$ , then the clause $\color{cyan} R = (s_1 \ {l}) ∨ (s_2 \ {¬l})$ is a `logical consequence` of the normal form of `S`

**r** is called the `resolvant` of $s_1$ and $s_2$

# Algorithm
While `[] doesnt belong to S`,
- choose $l, s_1 ,s_2$ such that $l ∈ s_1$ and $¬l ∈ s_2$ ;
- calculate the `resolvant` clause r;
- replace S with S ∪ {r}.

To prove that C is a logical consequence of {H 1 , ..., H n }, we apply the resolution principle to {H 1 , ..., H n , ¬C}.

# Example
![[Pasted image 20220616150520.png]]
