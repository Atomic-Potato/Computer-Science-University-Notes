# Definitions
**`Definition 1 (Group)`**
Let G be non empty set and ∗ is a binary operation defined on G. We say that (G,∗) is group if:
- ∗ is associative, that is, for every x,y,z ∈ G,` (x ∗ y) ∗ z = x ∗ (y ∗ z).`
-  G has neutral element e with respect to ∗, that is, for every x ∈ G, `x ∗ e = e ∗ x = x.`
- Each element in x ∈ G is invertible, that is there exists y ∈ G such that `x ∗ y = y ∗ x = e.`
The element y is denoted by $x^{-1}$ .

In addition, if ∗ is commutative then we say that (G,∗) is abelian group.

**`Definition 2 (Subgroup)`**
Let (G,∗) is group and H is a non empty set. We say that H is subgroup of G if H is a group containing in G. In fact the word subgroup means: subset and group at the same time.
### Reminders
`Abelian group:` An abelian group, also called a commutative group, is a group in which the result of applying the group operation to two group elements does not depend on the order in which they are written. That is, the group operation is commutative.

`Determinant of a matrix:`
![[Pasted image 20220121141317.png | 500]]
Properties:
- X is invertible iff det(X) != 0
- det(xyz) = det(x)det(y)det(z)

`Bijection, injection and surjection:`
![[Injection surjection bijection 1.JPG.jpg | 750]]
![[Injection surjection bijection visual.JPG.jpg |300]]

# Propositions
**`Prop 1 (Group)`**
Let (G,∗) be a group of neutral element e then,
- The element e is unique.
- The inverse element y of any element x ∈ G is also unique.
- For every x,y ∈ G, the inverse of x ∗ y is $y^{-1}$ ∗ $x^{-1}$ .

It is advised if you cant prove a group then you prove its a subgroup of one of the groups taken in the course. 
For example 2Z is a group since its a subgroup of Z

**`Prop 2 (Subgroup)`**
Let (G,∗) is group and H is a non empty subset of G. The following statements are equivalent:
- H is subgroup of G.
- ==(Used for proving)== For every a,b ∈ H, we have: a ∗ b ∈ H and $a^{-1}$ ∈ H.

**Corollary 1**
If H is subgroup of G then, G and H have the same neutral element.

**`Prop 3 IMPORTANT (Subgroup)`**
H is subgroup of (Z,+), if and only if, H = dZ where d is the smallest positive integer in H.