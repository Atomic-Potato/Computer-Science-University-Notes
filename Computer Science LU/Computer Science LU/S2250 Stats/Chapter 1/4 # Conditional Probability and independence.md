# Conditional Probability
Let A and B be two events with P(B) > 0. The conditional probability of A given B, denoted by P(A|B), is defined by:
![[conditional probability formula.jpg | 300]]

**Property**
Let *B* be an event with *P(B > 0)* (means B is certain). The conditional probability *P(.|B)* is itself a probability.
The rules of probability thus apply to conditional probability.
For example
$P(\overline{A}|C) = 1 - P(A|C)$

**Multiplication Rule**
**``P(A inter B) = P(A|B) x P(B) = P(B|A) x P(A)``**
Generalized:
**``P(A1 inter A2 .. inter An) = P(A1) x P(A2|A1) x P(A3|A1 inter A2) ... x P(An|A1 inter ... An-1)``**

# Independence
Two events A and B are independent if and only if:
![[independence of 2 events.jpg | 300]]

if n events A1, ... An are mutually independent then:
![[prob of mutually indepenent events.jpg | 300]]

**Properties**
if A and B are independent then so are:
![[independence prop.jpg | 150]]

![[Notation.jpg]]

# Other stuff
$P(A\cap\overline{B}) = P(A) - P(A\cap B)$
