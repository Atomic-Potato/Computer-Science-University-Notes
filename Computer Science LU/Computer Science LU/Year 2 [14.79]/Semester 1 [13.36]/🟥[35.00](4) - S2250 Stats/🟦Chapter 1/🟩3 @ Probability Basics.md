# Probability axioms
A probability is an application `P : S --> [0, 1]` satisfying the following axioms:
- P(empty) = 0  `[EMPTY = impossible event]`
- P(S) = 1 `[S = certain event]`
- For every family of sets `A1, A2, A3, ...` of  [[🟩1 @ Sample Space and Events#Mutually exclusive events| mutually exclusive]] events: `P(A1 U A2 U A3 ...) = sum(P(Ai)) = P(A1) + P(A2) + P(A3)...`

The Probability formula:
$$P = \frac{frequency}{numberOfWays}$$
Frequency = number of favorable outcomes
numOfWays = total frequency 

*For better understanding*
https://byjus.com/probability-formulas/

# Basic rules of probability
Let A and B be two events of sample space S
- union rule: P(A U B) = P(A) + P(B) - P(A $\cap$ B)
- intersection rule: $P(A\cap B) = P(A)*P(B)-P(A\cup B)$ 
- complement rule: $P(\overline{A}) = 1 - P(A)$

**Inclusion-exclusion formula**
![[the inclusion exclusion formula.jpg | 500]]