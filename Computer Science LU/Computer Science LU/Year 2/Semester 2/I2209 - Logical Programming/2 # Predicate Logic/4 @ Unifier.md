# Definition of Unifier and Most General Unifier
A `substitution σ` is a `unifier` of the set W of expression {E 1 ,E 2 ,...,E n } iff $E_1σ = E_2σ = ... = E_nσ$ (W is said to be unifiable)
A unifier is said to be `MGU most general unifier` if all other unifiers can be found by [[2 @ Substitutions and Instances#Composition of substitutions|composition]] using sigma ^mostGeneralUnifierMGU

Now in the following we will discover how to find an `MGU`:

# Discordance Set
The discordance set is a non empty set of expressions obtained by localizing the first position from the left for which all expressions don’t have the same symbol and while extracting in each expression, the sub-expression that begins in that position.

*Example*
![[Pasted image 20220620203715.png]]

# Unification Algorithm
The unification algorithm calculates a mgu for a set of expressions. Let W be a finite set to unify.
- `Step 1` K = 0; $W_k$ = W; $σ_k$ = ∅
- `Step 2` If $W_k$ is a singleton then $σ_k$ is a mgu of W
	Otherwise find the discordance set $D_k \space of \space W_k$ ;
- `Step 3` If there exists elements $\large V_k \space and \space t_k \space of \space D_k$ such that:
	- $V_k$ is a variable
	- $t_k$ is a [[1 @ Predicate Logic#Terms|term]] that doesn’t contain $V_k$
	Then go to to `Step 4`; Otherwise W is non unifiable
	**`BIG FAT NOTE: if you get a variable(Capital) and a constant(Small letter) then you substitute the variable with the constant, if you get a variable and a variable then it doesnt matter`**
- `Step 4` $\large σ_{k+1} = \{V_k /t_k \} ◦ σ_k$
	$\large W_{k+1} = W_{k\{V_k /t_k \}}$
- `Step 5` k = k + 1; Go to `Step 2`

if W is a non empty finite unifiable set then the algorithm always stops at `Step 2` and $σ_k$ is the `mgu`.

*Example:*
![[Pasted image 20220620205425.png | 600]]