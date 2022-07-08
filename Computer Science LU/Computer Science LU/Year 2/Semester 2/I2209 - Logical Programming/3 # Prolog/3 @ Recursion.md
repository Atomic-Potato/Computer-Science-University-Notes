# Example 1 (Eating)
```c
isDigesting(X, Y):- justAte(X,Y).
isDigesting(X, Y):- justAte(X,Z), isDigesting(Z,Y).

justAte(mosquito, blood(john)).
justAte(frog, mosquito).
justAte(stork, frog).
```
![[Pasted image 20220623161833.png | 300]]
```c
?- isDigesting(stork, mosquito).
yes
```

Another example
```c
p:- p.
```
```c
?- p.
ERROR: out of memory
```

# Example 2 (Descendant)
```c
child(anna, bridget).
child(bridget, caroline).
child(caroline, donna).
child(donna, emily).

descend(X,Y):- child(X, Y).
descend(X,Y):- child(X, Z), descend(Z,Y).
```
```c
?- descend(anna, donna).
yes
```

# Example 3 (Successor)
Suppose we use the following way to write numerals
- 0 is a numeral
- if X is a numeral, the so is succ(X)
```c
numeral(0).
numeral(succ(X)):- numeral(X).
```
```c
?- numeral(succ(succ(succ(0)))).
yes
?- numeral(X).
X=succ(0);
X=succ(succ(0));
X=succ(succ(succ(0)))
....
```

# Example 4 (Addition)
im not sure how
![[Pasted image 20220623164133.png | 400]]
