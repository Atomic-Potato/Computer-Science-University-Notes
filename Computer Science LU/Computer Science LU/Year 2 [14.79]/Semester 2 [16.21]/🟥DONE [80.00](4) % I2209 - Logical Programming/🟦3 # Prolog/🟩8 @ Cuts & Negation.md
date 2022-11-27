# Cut
The predicate **!/0** (aka cut) lets us control backtracking. Cut **always** succeeds 
Example:
```prolog
p(x):- b(X),c(X),!,d(X),e(X).
```
- Cut free
	![[Pasted image 20220722174601.png | 400]]
- With cut:
	![[Pasted image 20220722180438.png | 400]]

**`Note:`** even if you put the cut in the middle of a condition, it continues to check the rest of the condition

## max/3 with cut
This function succeeds if the third argument is the max of the first tow
```prolog
max(X,Y,Y):- X =< Y.
max(X,Y,X):- X>Y.
```
But it can be optimized since we cant ask for more solutions other than one.
Done by adding a cut after the first condition, if it succeeds then theres no need to check the second choice
This kind of cut is called `Green Cut` because it doesnt change the meaning of the predicate when added ^greenCut

This gives us an issue tho:
```prolog
?- max(200,300,200).
yes
```

So we cut the other branch when the first condition is satisfied and unify Y with Z
**`Note that the if statement conditions keep going while its conditions are true, the cut included, the cut just stops from going on next`**
```prolog
max(X,Y,Z):- X =< Y, !, Y=Z.
max(X,Y,X).
```