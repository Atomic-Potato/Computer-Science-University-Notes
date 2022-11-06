# Intro
`Propositional logic` is rather limited in its expressive power. *(E.g., ”For every x, x > 0” is true if x is a positive integer. Cannot be expressed in propositional logic)*

To deal with that we have `Predicates` and `Quantifiers`:
- A `predicate`  is a property about some objects or a relationship among objects represented by variables ^predicate
- A `Quantifier` tell how many objects has a certain property ^quantifier

# Predicate logic vocabulary
- `Constants` (a, b, c, 5, socrates, ...) ^constants
- `Functors or Functions` (f , g, h, +/2, mother/1, ...) ^functorsOrFunctions
- `Predicate symbols` (P, Q, R, Mother/1, < /2, ...) ^predicateSymbols
- `Variables` (x, y, z, x 1 , x 2 , ...) ^variables
- `Logical Connectives` (¬, ∧, ∨, →, ↔) ^logicalConnectives
- `Quantifiers` (∀, ∃) ^quantifiers
- `Parenthesis`

*Example: A = {volvo; owner/1; owns/2; happy/1}*

# Terms
Let A be a `vocabulary`.
A `term` in a is:
- Every constant in A is a term;
- Every variable is a term;
- If f /n is a functor in A and t 1 , ..., t n are terms over A then f (t 1 , ..., t n ) is a term

A `term` that contains no variables is called a `ground term` ^groundTerm

# Well-Formed Formula
Let A be a `vocabulary`.
The set of all `formulas` over A is the least set such that:
- If p/n is a predicate symbol in A and t 1 , ..., t n are terms then p(t 1 , ..., t n ) is an `atomic formula` ^atomicFormula
- If F and G are formulas, then ¬F, (F ∧ G), (F ∨ G), (F → G) and (F ↔ G) are formulas
- If F is a formula and x a variable, then ∀x F and ∃x F are formulas.

# Bound and free variables
An occurrence of x in a formula is said to be `free` iff the occurrence does not follow immediately after a `quantifier`, or in a formula immediately after `∀x or ∃x`, otherwise, the variable is `bound` (A variable in a wff is said to be `bound` if it is quantified). 

A formula that does not contain any [[🟩1 @ Predicate Logic#Bound and free variables|free]] occurrences of variables is said to be `closed`. ^closed

The effect/`scope` of a quantifier, is indicated by square brackets `[ ]`, If there are no square brackets, then the scope is understood to be the smallest `wff` following the quantification. ^scope

# Universal & Existential Closure
- Assume that **{x 1 ,...,x n }** are the only `free` occurrences of variables in a formula F. The `universal` closure **∀F of F** is the closed formula **∀x 1 ...∀x n F**.
- The `existential` closure ∃F is defined similarly.

# Substitution and Instantiation
The `substitution` operation consists of replacing some free `variables` of a formula **F** by `terms`.
Let **F** be a formula where **x 1 ,...,x n** are `free` variables and `σ` the `substitution` **{x 1 /t 1 ,...,x n /t n }.**
$F_σ$ is the formula obtained by replacing all the free occurrence of $x_i$ by $t_i .$

A substitution `instantiates` a variable **x** if it **replaces x by a term that does not contain any variable.**

# Interpretations
Let A be a vocabulary. An `interpretation` I of A consists of:
- A non-empty set D (often written |I|) of objects (the domain of I)
- A function that maps:
	- Every constant c in A on an element $\color{cyan} c_I$ in D
	- Every functor f /n in A on a function $\color{cyan} f_I$ : $D^n$ → D
	- Every predicate symbol p/n in A on a relation $\color{cyan} p_I ⊆ D n$

*Example: (what... ?)*
![[Pasted image 20220616190005.png | 450]]

# Interpretation VS Valuation
- An `interpretation` defines how to interpret constants, functors and predicates symbols but it **does not say what a variable denotes.**
- A `valuation` is a function from variables to objects in the domain of an interpretation.

# The interpretation of terms
Let I be an interpretation of a vocabulary A and σ be a valuation. The interpretation $\color{cyan} σ_I (t)$ of the term t is an object in t’s domain:
- If t is a constant c then $\color{cyan} σ_I (t) = c_I$
- If t is a variable x then $\color{cyan} σ_I (t) = σ(x)$
- If t is a term f (t 1 ,...,t n ) then $\color{cyan} σ_I (t) = f_I (σ_I (t_1 ),...,σ_I (t_n ))$.

*Example:*
![[Pasted image 20220616193849.png | 450]]

# The interpretation of formulas
The meaning of a formula is a truth-value` ”true” or ”false”.`
Given an interpretation I and a valuation σ we write:
![[Pasted image 20220616194536.png | 500]]
Reminder: [[🟩1 @ Propositional Logic#Tautology and logical Consequence |Tautology]]


*Example:*
![[Pasted image 20220616194629.png | 400]]

# Models & Consistency
 
Let F be a [[🟩1 @ Predicate Logic#^closed |closed]] formula, P be a set of [[🟩1 @ Predicate Logic#^closed |closed]] formulas.
- An interpretation I is a `model` of F iff **I |= F**
- An interpretation I is a `model` of P iff **I is a model of every formula in P**

F (resp. P) is `consistent` iff F (resp. P) **have at least one model.** (Otherwise F/P is `inconsistent`)

F is `valid` iff **for all interpretation I we have I |= F**

# Logical Consequence
Reminder: [[🟩1 @ Propositional Logic#Tautology and logical Consequence | Logical Consequence]]

F is a `Logical consequence` of P (P |= F) iff F is true in all of P’s models (Mod(P) ⊆ Mod(F))

- **Theorem:** P |= F iff P ∧ ¬F is `inconsistent` **`IMPORTANT`**

# Logical Equivalence
Let F, G, ∀xH(x) be formulas. F and G are logically equivalent (F ≡ G) iff I |= σ F exactly when I |= σ G.
![[Pasted image 20220616200657.png | 500]]

# Prenex normal form (PNF)
- $\large Q_1x_1 \space Q_2 x_2 ... Q_n x_n \space M(x_1 x_2 ...x_n )$
	- [[🟩1 @ Predicate Logic#^quantifier|The qunatifier part:]] $\large Q_1x_1 \space Q_2 x_2 ... Q_n x_n$ Prefix($Q_ix_i = ∀x_i \space or \space ∃x_i$)
	- $M(x_1 x_2 ...x_n )$: Mantissa ([[🟩1 @ Predicate Logic#Well-Formed Formula|wff]] without quantifier)
*Example:*
*∀x∃y(p(x,y) → (q(x) ∨ r(y)))*

## Pair of equivalents wff
![[Pasted image 20220620171320.png | 500]]

## Converting to a pnf formula **`(IMPORTANT)`**
- replace `A ↔ B` by `(A → B) ∧ (B → A)`
- replace `A → B` by `¬A ∨ B`
- Negation:
	- `¬¬F` by `F`
	- `¬∀xF(x)` by `∃x¬F(x)`
	- `¬∃xF(x)` by `∀x¬F(x)`

Apply all the other rules (rename if necessary)

# Skolem form (sf)
First we take a formula in [[🟩1 @ Predicate Logic#Prenex normal form PNF |PNF]] and we apply the following algorithm
- Let $\large Q_m$ be the 1st ∃ (the + to left)
	- if theres no ∀ before $\large Q_m$ ⇒ replace $\large x_m$ in Mantissa by a constant symbol not yet used (a,b,...)
	- else ⇒ choose a function symbol not yet used (f ,g,...) and replace $\large x_m$ in Mantissa by $\large f (x_1 ,x_2 ,...,x_{m−1} )$
	_So for example if we have: for all X for all Y there is Z, we replace Z in the formula by f(X,Y)_
- Repeat till the elimination of all ∃
- Eliminate ∀ (that becomes implicit)

# Clausal form
- Clause = disjunction of literals
- Literal = [[🟩1 @ Predicate Logic#^atomicFormula|atom]] or negation of an atom
- Clausal form = set (conjunction) of clauses
- Proposition
If, before transformation, F = F 1 ∧ F 2 ∧ ... ∧ F n Then the clausal form $\large S_F = S_F1 ∪ S_F2 ∪ ... ∪ S_Fn$

## `Proving validity with clausal from`
Skolem maintain the inconsistency
F valid ⇔ ¬F inconsistent ⇔ pnf (¬F) inconsistent ⇔ sf (¬F) ⇔ clausal form (¬F) inconsistent

# Translate English to WFFs
Transcribing English sentences into `wffs` is sometimes non-trivial task. We just give a few examples:
- E stands for even and O stands for odd.
- **”Some integers are even and some are odd”** can be translated as `∃xE(x) ∧ ∃yO(y)`
- **”No integer is even”** `∀x¬E(x)`
- **”If an integer is not even, then it is odd”** `∀x[¬E(x) → O(x)]`
- We assume that the universe is the set of integers. However, if we do not assume that, then we need to narrow it down using ∧, →, and I (predicate for integer).
*E.g.: ∃x[I(x) ∧ E(x)] ∧ ∃y[I(y) ∧ O(y)] ∀x[I(x) → ¬E(x)]*