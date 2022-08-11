# Control Predicates
- `X;Y` means X or Y
- `(X->Y)` means if X then try Y otherwise fail
- `(X->Y;Z)` if X, then try Y, else try Z
- `not X` (sometimes written `\+X` or `not(X)`) Succeed only when X fails
- `True` Succeed once, but fail when backtracked into
- `repeat` Always succeed, even when backtracked into.
- `Fail` Never succeed.
- `!` (Pronounced "cut".) Acts like true, but cannot be backtracked past, and prevents any other clauses of
the predicate it occurs in from being tried.
- `abort` Return immediately to the top-level Prolog prompt.

# If-Then-Else
`(A->B;C)` equivalent to `if` A then try B `else` try C

*Example:*
max(X,Y,Z) :- ( X =< Y -> Z = Y; Z = X ).

# Input/Output

## Output
- `write/1` predicate: writes a single term to the terminal. _For example: write(a), or write(‘Into the chopaah !’)_
- `writeln/1` predicate: Same but goes on a new line at the end
- `nl/0` predicate: display a new line
- `tab(X)` predicate: Writes an X number of spaces to the terminal.

## Input
- `read/1`: read(X) reads a term from the keyboard and instantiates variable X to the value of the read term.
	The term to be read has to be followed by a dot “.” and a white space character (such as an enter or space).

---

# Towers of Hanoi
![[Pasted image 20220811140722.png | 300]]
In this game we have to move the discs on the left stick to the right stick, however we cannot put a larger disc on a smaller disc.

The solution is as follows:
```prolog
hanoi(N) :- move(N, left, right, center).

move(0, _, _, _) :- !.

move(N, A, B, C) :-
	M is N-1,
	move(M, A, C, B),
	inform(A, B),
	move(M, C, B, A).
	
inform(X, Y) :-
	write('move a disc from the '),
	write(X),
	write(' pole to the '),
	write(Y),
	write(' pole'),
	nl.
```

## `hanoi(N)`
```prolog
hanoi(N) :- move(N, left, right, center).
```
If prolog finds that it needs to prove `hanoi(3)`, it will now try to prove:
```prolog
move(3, left, right, center).
```
which reads something like: _"move 3 discs from the left pole to the right pole, using the center pole to hold things temporarily."_

## `inform(X,Y)`
This is actually used for side effects that generate output (it can always be satisfied).
```prolog
?- inform(left,center).
move a disc from the left pole to the center pole
Yes
?- inform(right,left).
move a disc from the right pole to the left pole
Yes
?- inform(north,south).
move a disc from the north pole to the south pole
Yes
```

## `move(0, _, _, _):-!.`
Move 0 discs from any pole to any pole using any pole is true and should stop any backtracking.  Whatever the poles are, this rule is true, the only restriction is the number of discs (0). Sort of like the stopping condition in a recursive function.

## `move(N, A, B, C) :-` 
To move N discs from A to B:
- first move the top N-1 discs from A to C
- then move the bottom disc from A to B
- then move the N-1 discs from C to B

--- 
# Extra predicates
## `between/3`
```prolog
between(Low, High, Value)
```
Generates values between high and low or checks if `Value` is between high and low

## Collecting solutions
### `findall/3`
```prolog
?-findall(Objects,GoalOrCondition,List).
```
`finall` puts all the possible Objects that satisfy the Goal inside a List.
This predicate:
- always succeeds
- The goal G might be a compound goal
- Unifies L with empty list if G cannot be satisfied

*Example:*
![[Pasted image 20220811153624.png | 450]]

### `bagof/3`
```prolog
?- bagof(O,G,L).
```
Pretty much the same as `findall` but produces multiple lists for each case 

*Example:*
![[Pasted image 20220811154032.png | 450]]

If we dont want to generate a list for a specific case we use `^` 
![[Pasted image 20220811154300.png | 450]]

**Combining the Lists into a single list of lists**
![[Pasted image 20220811154603.png | 450]]

### `setof/3`
```prolog
?- setof(O,G,L).
```
Same as `bagof` but sorts the list and removes duplicates

*Example:*
![[Pasted image 20220811154816.png | 450]]