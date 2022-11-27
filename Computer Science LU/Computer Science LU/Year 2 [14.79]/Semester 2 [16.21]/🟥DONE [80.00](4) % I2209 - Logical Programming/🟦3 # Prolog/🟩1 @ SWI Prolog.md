# Basic idea of prolog
- Describe the situation
- ask a question
- `Prolog` logically deduces new facts about the described situation
- And the `Prolog` gives us its deductions back as answers

# Describing the situation
## Knowledge Base 1
```c
woman(mia).
woman(jody).
woman(yolanda).
playsAirGuitar(jody).
party.
```
Basically we declared that *"mia, jody and yolanda"* are `women` and *"jody"* is `playing air guitar` and theres a `party`.

Now we can ask `Prolog` questions
```c
?- woman(mia).
yes
?- playsAirGuitar(jody).
yes
?- playsAirGuitar(mia).
no
?- tattoed(jody).
ERROR: predicated tattoed/1 not defined.
?- party.
yes
?- rockConcert.
no
```
*Is mia a woman?* Then `Prolog` checks the situation we described to find if mia is a woman and returns `yes`
*is jody playing guitar?*
*is mia playing guitar?*

## Knowledge Base 2 (Facts &  Rules)
```c
happy(yolanda).
listens2music(mia).
listens2music(yolanda):- happy(yolanda).
```
The first 2 lines are `facts` and the last line is a `rule`.
At line 3 what we are saying is: *yolanda is listening to music `if ( :- )` yolanda is happy*
```c
  listens2music(yolanda):- happy(yolanda).
//{		   head         }  {    body     }
```

## Clauses & Predicates
A `Clause` is basically one of the lines and its end is marked by a full stop `"."` ^clause
A `predicate` is idk
![[Pasted image 20220623124452.png | 500]]

## Knowledge Base 3 (Expressing Conjunction & Disjunction)
```c
playsAirGuitar(vincent):- listen2music(vincent), happy(vincent).
//                              the comma here ^ expresses the AND/conjuction in Prolog
playsAirGuitar(butch):- happy(butch); listens2music(butch).
//                    the semicolon ^ expresses the OR/disjunction
// we can also do it this way (this is the more preferable way)
playsAirGuitar(butch):- happy(butch).
playsAirGuitar(butch):- listens2music(butch).
```

## Knowledge Base 4 (Prolog and Logic)
We can now see how `Prolog` is related to `Logic`
- Operators:
	- Implication: `:-`
	- Conjunction: `,`
	- Disjunction: `;`

### Prolog Variables
```c
woman(mia).
woman(jody).
woman(yolanda).

loves(vincent, mia).
loves(marsellus, mia).
```
```c
?- woman(X) //give me all the possible solutions for X
X = mia; //first we get mia, now if we type a semicolon " ; " then it will give us the second possible solution
X = jody; //same
X = yolanda; //same
no //no solutions left

?- loves(marsellus, X), woman(X). //give us all the possible solutions for X in woman(X) and this X should love marsellus
X = mia
yes
```

## Knowledge Base 5
```c
loves(vincent, mia).
loves(marsellus, mia).

jealous(X, Y):- loves(X, Z), loves(Y, Z).
//Here we're not being specific about the situation
//Depending on the facts defined earlier, and the input recieved in the rule we will get an answer
//So X is jealous of  Y if X loves Z and Y loves Z.
```
```c
?- jealous(marsellus, W). //whos marsellus jealous of ?
W=vincent
?- jealous(marsellus, vincent). // is marsellus jealous of vincent ?
yes
```

# Prolog Syntax
Here we will see what are [[🟩1 @ SWI Prolog#Knowledge Base 2 Facts Rules|facts & rules]] and queries are built out of
![[Pasted image 20220623130946.png | 500]]

## Atoms
What is an `atom`:
- A sequence of characters of upper-case letters, lower-case letters, digits, or underscore, starting with a `lowercase letter`
	*Examples: butch, big_kahuna_burger, playGuitar*
- An arbitrary sequence of characters enclosed in single quotes
	*Examples: 'Vincent', 'Five dollar shake', '@#%!'*
- A sequence of special characters
	*Examples: : , ; . :-*

## Numbers
- `Integers:` the ones you know
- `Floats:` the ones you know

## Variables
A sequence of characters of upper-case letters, lower-case letters, digits, or underscore, starting with either an `uppercase letter`  or an `underscore`
*Examples: X, Y, Variable, Vincent, _tag*

## Complex Terms
`Atoms, numbers and variables` are building blocks for **complex terms** which are built our of a `functor/function` directly followed by a sequence of `arguments`.  **(The functor must be an atom)**
`Arguments` are put in round brackets separated by commas.

*The best example for a complex term is any [[🟩1 @ SWI Prolog#Knowledge Base 2 Facts Rules|rule]]*

### Arity
`Arity` is basically the number of arguments in a `complex term`. In Prolog you can define two [[🟩1 @ SWI Prolog#Clauses Predicates|predicaes]] with the same functor but with different `arity`. Prolog will treat them as two different predicates.

In Prolog documentation, arity of a predicate is usually indicated with the suffix `/` followed by a number to indicate the arity.