`Logical reasoning` is the process of drawing conclusions from premises using `rules of inference`

# Reasoning with Propositions
- The basic inference rule is `modus ponens`. It states that if both A → B and A hold, then B can be concluded, and it is written as
$$\large \frac{A, A → B}{∴ B}$$
A and A → B are `premises` and B is the `conclusion` drawn from premises.

- `modus tollens`
$$\large \frac{¬B, A → B}{∴ ¬A}$$
- `Conjunctive Simplification`
$$\large \frac{A ∧ B}{∴ A}$$
- `Conjunctive Addition`
$$\large \frac{A, B}{∴ A ∧ B}$$
- `Rule of contradiction`

Where c is a contradiction
- `Disjunctive Addition`
$$\large \frac{A}{∴ A ∨ B}$$
- `Disjunctive Syllogism`
$$\large \frac{A ∨ B, ¬B}{∴ A}$$
- `Hypothetical Syllogism`
$$\large \frac{A → B, B → C}{∴ A → C}$$
- `Dilemma` proof by division into cases
$$\large \frac{A ∨ B, A → C, B → C}{∴ C}$$
# Deduction problem and Deduction principle
**I WILL TRY TO UNDERSTAND THIS ONCE WE SOLVE EXERCISES**

- `Deduction problem`: Establish if a formula C is a logical consequence of a set E of formulas
$$\large \{H 1 ,...,H n \} |= C ⇐⇒|= \{H 1 ,...,H n \} → C$$
A Set E is semantically `consistent` if all its elements have a `common model`; if not, it is inconsistent. A set of
formulas is then assimilated, from a semantic point of view to the conjunction of its elements

- `Deduction principle`: C is a logical consequence of a finite set E iff $\color{cyan} E ∪ \{¬C\}$ is inconsistent
E is inconsistent iff F (false) is a logical consequence, or if each formula is a logical consequence
$$\large \{H 1 ,...,H n \} ⊢ C ⇐⇒ \{H 1 ,...,Hn,¬C\} ⊢ F$$

# Uniform Substitution
A and B are `logical consequence` one from the other (logically equivalent) iff the formula `(A ↔ B) is a tautology`.

- `Substitution` means uniform substitution of formulas for variables. F(H 1 ,...,H n ) means: substitute H i for each occurrence of P i in F(P 1 ,...,P n ).
*Example: if F(p,q) is p → (q → p) then F(¬p ∨ r,¬p) is ¬p ∨ r → (¬p → ¬p ∨ r)*

- Rule of `uniform substitution`: if X is a tautology, p a proposition and A a formula, then the statement obtained by replacing p by A in X is a tautology
