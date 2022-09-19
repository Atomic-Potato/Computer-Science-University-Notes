# Unification
Two [[1 @ SWI Prolog#Prolog Syntax|terms]] `unify` if they are the same term or if they contain variables that can be uniformly instantiated with terms in such a way that the resulting terms are equal.
*Example:*
![[Pasted image 20220623141931.png | 400]]
![[Pasted image 20220623141947.png | 400]]

# Instantiations
When Prolog `unifies` two terms, it performs all the necessary `instantiations` so that the terms are equal afterwards.
- If T1 is a `variable` and T2 is any type of `term`, the T1 and T2 unify, and T1 is `instantiated` to T2 (and vice versa)
- If T1 and T2 are complex terms then they `unify` if:
	- They have the same functor and [[1 @ SWI Prolog#Arity|arity]]
	- All their corresponding arguments unify
	- the variable instantiations are compatible.
```c
?- mia = mia.
yes
?- mia = vincent.
no
?- mia = X.
X = mia
yes
?- X=mia, X=vincent.
no
//Atfer working through the first goal, Prolog has instantiated X with mia
//so that it cannot unify it with vincent anymore
//hence the second goal fails
?- k(s(g), Y) = k(X, t(k)).
X=s(g)
Y=t(k)
yes
```

# Infinite terms
Prolog does not use a standard unification algorithm.
Consider the following query:
```c
?- father(X) = X.
```
Do these terms unify or not?
```c
//X = father(father(father(father(father(father(father(father(father(.....
X = father(father(father(...)))
yes
```

A standard unification algorithm carries out an occurs check. If it is asked to unify a variable with another term it checks whether the variable occurs in the term
```c
?- unify_with_occurs_check(father(X), X).
no
```

# Programming with unification
```c
vertical(line(point(X,Y), point(X,Z))).
horizontal(line(point(X,Y), point(Z,Y))).
```
```c
?- horizontal(line(point(2,3), point(1,Y))).
Y = 1;
no
?- vertical(line(point(1,1), point(1,3))).
yes
```

# Proof Search
Now we will learn how Prolog searches a knowledge base to see if a query is satisfied (proof search)
This one is better shown in examples:
![[Pasted image 20220623154827.png | 500]]
![[Pasted image 20220623155500.png | 500]]
![[Pasted image 20220623155515.png | 500]]
