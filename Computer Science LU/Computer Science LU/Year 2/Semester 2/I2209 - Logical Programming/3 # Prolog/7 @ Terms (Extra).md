# Comparision
- **\==/2** Checks if 2 variables are equal
	*Examples:*
	```prolog
	 ?- a==a.
	yes
	?- a==b.
	no
	?- a=='a'. %Done for convenience
	yes
	?- a==X.
	X = _443
	no
	```
- **\\\==/2** Checks if 2 variables are not equal

**`Notes:`** 
- you can compare arithmetic equations such as `+(x,y)` and `>(x,y)` _(e.g. +(x,y) \== <(x,y))_
- Lists can be comparable terms as well
	Example
	```prolog
	?- [a,b,c,d] == [a,b|[c,d]].
	```
## Reminder of all comparison predicates
![[Pasted image 20220722172219.png | 400]]

# Checking the type of a term
- **atom/1** (Reminder [[1 @ Predicate Logic#^atomicFormula|Atomic Formula]])
- **integer/1**
- **float/1**
- **number/1** (Integer or float)
- **atomic/1** (constant)
- **var/1** (un-instantiated variable)
- **nonvar/1** (anything other than an un-instantiated)
- **is_list/1**

*Example:*
```prolog
?-X=a, atom(X)
X=a
yes
```