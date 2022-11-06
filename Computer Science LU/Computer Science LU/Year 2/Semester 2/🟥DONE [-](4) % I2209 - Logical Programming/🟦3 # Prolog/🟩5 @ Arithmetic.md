# Arithmetic equivalents in prolog
Normal
```prolog
2 + 3 = 5
3 x 4 = 12
5 – 3 = 2
3 – 5 = -2
4 : 2 = 2 %division
%1 is the remainder when 7 is divided by 2
```
Prolog
```prolog
?- 5 is 2+3.
?- 12 is 3∗4.
?- 2 is 5-3.
?- -2 is 3-5.
?- 2 is 4/2.
?- 1 is mod(7,2).
```
It is important to know that +, -, / and ∗ do not carry out any arithmetic

**Note:**
```prolog
?- X is 3 + 2.
X = 5
yes
?- 3 + 2 is X.
ERROR: is/2: Arguments are not sufficiently instantiated
```

- Friendly Notation:
	For example: `3+2` is the same as `+(3,2)` and so on for the others

# Comparison equivalents in prolog
Normal
```prolog
x < y
x ≤ y
x = y
x ≠ y
x ≥ y
x > y
```

Prolog
```prolog
X < Y
X =< Y
X =:= Y  % equal
X =\= Y  % not equal
X >= Y
X > Y
```

# Predicates
## Length of a list & `Accumulators`
- First method:
	Base case is the list is empty. Otherwise we remove the head and we call the function again. And as we backtrack we add 1 to N
	```prolog
	len([],0).
	len([_|L],N):- len(L,X), N is X + 1.
	
	%Calling the predicate
	?- len([a,b,c,d,e,[a,x],t],X).
	X=7
	yes
	```
- Second method: `(Acuumulators)` and **acclen/3**
	This predicate has 3 arguments: (List, Accumulator, Container for length)
	- Add 1 to the accumulator as we go down the list, when the list is empty, put it as the length
	```prolog
	acclen([],Acc,Length):- Length = Acc.
	
	acclen([_|L],OldAcc,Length):- NewAcc is OldAcc + 1, acclen(L,NewAcc,Length).
	
	%We can clean up the arguments like so
	length(List,Length):- acclen(List,0,Length).
	
	%And then just simply call the length method
	?-length([a,b,c], X).
	X=3
	yes
	```

The **acclen/3** is `tail-recursive` and **len/2** is not which is more efficient, because:
- In tail recursive predicates the results is fully calculated once we reach the base clause
- In recursive predicates that are not tail recursive, there are still goals on the stack when we reach the base clause

## accMax/3
**Finds the maximum inside a list**
The arguments are: (The list, Accumulator, Max)
How it works: *(The Acc starts as the first head)*
- If the head is greater than the Acc, then the head is the new Acc and we remove the head
- If it is less or equal, then we just simply remove the head
- When the list is empty, then Max is the Accumulator
```prolog
accMax([H|T],A,Max):- H > A, accMax(T,H,Max).

accMax([H|T],A,Max):- H =< A, accMax(T,A,Max).

accMax([],A,A).

%Cleaned up
max([H|T],Max):- accMax(T,H,Max).
```
*Example:*
```Prolog
?- max([1,0,5,4], Max).
Max=5
yes
```