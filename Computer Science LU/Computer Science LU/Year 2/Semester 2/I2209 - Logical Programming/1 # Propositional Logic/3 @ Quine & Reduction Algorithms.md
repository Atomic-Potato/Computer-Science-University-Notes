# Semantic Trees
Given a finite set of propositions, noted $\color{cyan} P = \{p 1 ,...,p n ,...\}$, a `semantic tree` is a binary tree
respecting the following conditions:
- Each arc is labeled by a literal (positive or negative) issued from P
- Literals labeling two arcs issued from the same node are opposed
- No branch has more than one occurrence of each literal
- No branch has a pair of opposed literals
  ![[Pasted image 20220519173103.png | 200]]

## Properties
- If P is finite, any semantic tree is then finite.
- If P is infinite, then there exists finite and infinite semantic trees. An infinite binary tree has at least one infinite branch.
- To each node N of a semantic tree correspond a partial interpretation (function I N associating a truth value to some elements in P). The partial interpretation I N assign the value T (F) to proposition p if an arc of the path connecting N to the root is labeled by p (¬p); it is not defined for p if neither p nor ¬p appear on that path.
- A finite semantic tree is complete if each leaf corresponds to a total interpretation (defined everywhere).
- An infinite semantic tree is complete if each branch issued from the root establish a total interpretation.

## Is the formula A `consistent` or satisfiable?
- Let’s consider the complete semantic tree composed of all propositions (finite) in A. For each leaf, we evaluate A according to corresponding interpretation.
- **`The formula is consistent if for at least one leaf, the value obtained is true.`**

# Quine Algorithm (for optimization)
If all possible extensions of a partial interpretation attribute the same truth value to the formula tested, then there is no need to construct the sub-graph issued from the node corresponding to this partial interpretation

**Steps:** _(With an example)_
`[((p ∧ q) → r) ∧ (p → q)] → (p → r)`
- Order the set `{p, q, r}`
- First consider interpretations that **make `p` true** (a.k.a Replace p with true in the formula and reduce it). Thus partially interpreted, the formula becomes 
	`[(q → r) ∧ q] → r`
	- Now let `q` be true, and reduce, the resulting formula is a tautology
	- Now let `q` be false, and reduce, the resulting formula is a tautology
- Now make `p` false and repeat the steps of when p was true, which leads to a tautology

And so **each path of a semantic tree leads to a tautology**, thus the formula is `valid`.

# Reduction Algorithm (for optimization)
Prove by `contradiction` the validity of a formula.
`Advantageous when the formula has numerous implications.`
$$[(p ∧ q) → r] → [p → (q → r)]$$
- Suppose that an interpretation I assign the value F to this formula. From the truth table of the implication, a
conditional is false if and only if the second part is false and the first part is true. we deduce that:
$$I((p ∧ q) → r) = T, \space I(p → (q → r)) = F$$
- The same rule, applied to the first line, establish I; we obtain:
$$I(p) = T, I(q) = T, I(r) = F$$
⇒ contradiction with I((p ∧ q) → r) = T. This contradiction proves the validity of the formula.

# Normal Forms
- **Clauses and Conjunctive Normal Form**
	- A `clause` is the disjunction of a finite number of literals, i.e. a formula of type (l 1 ∨ l 2 ... ∨ l n ) ^clause
	- The `empty clause` is the **only inconsistent** clause (F of [])
	- Every formula A has a conjunctive normal form that is logically equivalent to A

- **Cube and Disjunctive Normal Form**
	- A `cube` is the conjunction of a finite number of literals, i.e. a formula of type (l 1 ∧ l 2 ... ∧ l n )
	- Every formula A has a disjunctive normal form that is logically equivalent to A

## Normalization Algorithm
- Replace X ↔ Y by (X → Y) ∧ (Y → X)
- Replace X → Y by ¬X ∨ Y
- Apply De Morgan’s Theorem: Replace
¬(X ∧ Y) by ¬X ∨ ¬Y and
¬(X ∨ Y) by ¬X ∧ ¬Y
- Replace ¬¬X by X
- Apply the distributivity rules: Replace
X ∨ (Y ∧ Z) by (X ∨ Y) ∧ (X ∨ Z) and
X ∧ (Y ∨ Z) by (X ∧ Y) ∨ (X ∧ Z)

## Davis and Putnam Algorithm
We use this algorithm to tell if a set of [[3 @ Quine & Reduction Algorithms#^clause|caluses]] is consistent or inconsistent
`Usually we do this when we want to prove a valid formula so we prove that its negation is inconsistent and thus the original is consistent`
- if S = ∅, then S is consistent
- if S = {F}, then S is inconsistent
- Else:
	- select a proposition **p in S**
	- calculate $\color{cyan}S_p$ **(clauses that contain p)**, $\color{cyan}S_{¬p}$ **(clauses that contain non p)** and $\color{cyan}S^{′′} = S \textbackslash \{S_p ∪ S_{¬p})$
	- obtain $\color{cyan}S^′_p$ whose clauses are those of $\color{cyan}S_p$ without the literal p
	- obtain $\color{cyan}S^′_{¬p}$ whose clauses are those of $\color{cyan}S_{¬p}$ without the literal ¬p
	- Then, the set S is inconsistent iff sets $\color{cyan}(S^′_p ∪ S^{′′})$ and $\color{cyan}(S^′_{¬p} ∪ S^{′′})$ are inconsistent

- Select p in priority in each following cases:
	- S contains one of clauses with literal p or ¬p
	- Only one of literals p and ¬p appears in S

*Example*
S = {p ∨ q, p ∨ r, ¬q ∨ ¬r, ¬p}
Then:
- $S_p = \{p ∨ q, p ∨ r\}$
- $S_{¬p} = \{¬p\}$ 
- $S'_p = \{ q , r \}$
- $S'_{¬p} = \{F\}$

T = {q, r, ¬q ∨ ¬r}
Then:
If we repeat the steps above we get
U = {r, !r} *`note that when you remove the (!r)  when picking (r) you get F and not empty because (!r = !r or F) but if we remove a clause that contains (r) when picking (r) we get "empty" because we are removing the whole clause and not a part of the clause`*
Repeat steps, and you get only F thus S is inconsistent `if you got "empty" then it is consistent`

**Faster way** (Ch1 session 2, end of video)
![[Pasted image 20220519181831.png | 300]]


Quick way to do it:
- you convert the equation into a disjunctive set
- pick an interpretation that is on its own
	- if its a negative you find the clauses that contain the same interpretation and delete them, if its the positive you just delete the positive from the clause
	- same if its positive but in the opposite
- do while there is single interpretations, once theres none you prove the inconsistency

`Note that in this way usually when you reach a place when the S will be consistent use the regular way`
