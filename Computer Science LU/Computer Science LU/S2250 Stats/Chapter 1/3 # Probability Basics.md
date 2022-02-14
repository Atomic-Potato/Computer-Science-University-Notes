# Probability axioms
A probability is an application `P : S --> [0, 1]` satisfying the following axioms:
- P(empty) = 0  `[EMPTY = impossible event]`
- P(S) = 1 `[S = certain event]`
- For every family of sets `A1, A2, A3, ...` of mutually exclusive events: `P(A1 U A2 U A3 ...) = sum(P(Ai)) = P(A1) + P(A2) + P(A3)...`
<label class="ob-comment" title="" style="">  <input type="checkbox"> <span style=""> Mutually exclusive is where Ai intersect Aj = empty where i != j </span> Note</label>

The Probability formula:
$$P = \frac{frequency}{numberOfWays}$$

*For better understanding*
https://byjus.com/probability-formulas/

# Basic rules of probability
Let A and B be two events of sample space S
- union rule: P(A U B) = P(A) + P(B) - P(A inter B)
- intersection rule: $P(A\cap B) = P(A)*P(B)-P(A\cup B)$ `im not sure about this one`
- complement rule: $P(\overline{A}) = 1 - P(A)$

**Inclusion-exclusion formula**
![[the inclusion exclusion formula.jpg | 500]]