# Intro
A `proposition` is a statement or sentence that is either **true** or **false**
- An `atomic proposition` cannot be further subdivided
- A `compound proposition` can be subdivided

The set of logic connectives
![[Pasted image 20220519143509.png | 400]]

**Rules to obtain a well formed formula:**
- Any atomic or elementary proposition is a wff
- True (T) and False (F) are wff
-  If A is a wff, then (A) is a wff
-  If A and B are wffs, then ¬A, A ∧ B, A ∨ B, A → B, ↔ B are wffs.

To eliminate parentheses as much as possible we give operators a strength:
![[Pasted image 20220519143752.png | 200]]

The truth values of a formula and its constituents can be represented by a table, called a `truth table`
![[Pasted image 20220519143950.png | 400]]

An `interpretation` is a function that associates to each proposition p a truth value. ^interpretation

An `interpretation` that makes a formula `true` is a `model` of that formula. ^model

A `literal` is an elementary proposition or the `negation` of a proposition; literals p and ¬p are opposes.

Two formulas A and B are `logically equivalent` (written A ∼ B), if and only if, they have `identical truth values` for each possible substitution of formulas for their variables.

For the formula $\color{cyan} A → B$, the formula $\color{cyan} B → A$ is called its `converse`, the formula $\color{cyan} ¬A → ¬B$ is its `inverse`, and the formula $\color{cyan} ¬B → ¬A$ is its `contrapositive`
- Converse ~ Inverse
- Contrapositive ~ Original Formula

# **Most common ways to say A -> B:**
- If A, then B
- A implies B
- A, therefore B
- A only if B
- B follows from A
- B whenever A
- B if A
- A is a sufficient condition for B
- B is a necessary condition for A

# **All connectors can be expressed using ¬ and →**
- (A ∨ B) ≡ (¬A → B),
- (A ∧ B) ≡ ¬(A → ¬B),
- (A ↔ B) ≡ ((A → B) ∧ (B → A))

(We read ≡ as a definition symbol)

Any other connector can be defined using these five connectors:
- Exclusive disjunction of A and B
$$(A ∧ ¬B) ∨ (¬A ∧ B)$$
- If A then B else C
$$(A → B) ∧ (¬A → C)$$

# **Consistent and valid formula**
- A formula is `consistent`, if it has a **model**
*Ex: (p ∧ q) and (p ∨ q) are consistent (true if p and q are true)*
- A non consistent formula is called `inconsistent` or a contradiction.
*Ex: (p ∧ ¬p) is inconsistent*
- A formula is `valid` if it is **always true**, independently from truth values assigned to its propositions
*Ex: (p ∨ ¬p), (p → p) and (¬¬p ≡ p)*

Some properties:
- The negation of a valid formula is inconsistent
- The negation of a consistent formula is invalid
- A contingent formula is neither valid, nor inconsistent
- A formula that has k different propositions has 2 K interpretations
- Using these 2 k interpretations, we can immediately determine if the formula is consistent, valid, contingent, invalid, or inconsistent
- The formula (f ) is valid
- Formulas (p ∧ q) and (p → (q → r)) are contingents

# Tautology and logical Consequence
- A `tautology` is a valid formula of propositional calculus ^tautology

$$Notation: \space |= A$$*Example: p ∨ ¬p is always true regardless of the truth value of the proposition p*

- A `contradiction` is a formula that is always false

- A formula A is a `logical Consequence` of a set of formulas E if any interpretation that makes true all formulas in E makes A true
$$Notation: \space E ⊢ A$$
*Example: B ⊢ A ⇔|= (B → A)*

### Properties
![[Pasted image 20220519170515.png | 500]]
![[Pasted image 20220519170538.png | 350]]
