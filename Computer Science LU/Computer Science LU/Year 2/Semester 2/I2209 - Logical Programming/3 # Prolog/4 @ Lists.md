# Definition
Basically arrays lol, examples:
```prolog
[a, b, c, d]
[a, f(d), c]
[]
[a, [1, 2], []]
```

All sorts of Prolog terms can be elements of a list.

A non-empty list has 2 parts:
- `head:`  the first element of the list
- `tail:` the rest of the list without the head

## Operator `|`
The bar `|` operator is used to **decompose** the list into head and tail
```prolog
?-[Head|Tail] = [a,b,c,d]

Head = a
Tail = [b,c,d]
yes

?-[X|Y] = []
no

?-[H1, H2|T] = [a,b,c,d]
H1 = a
H2 = b
T = [c,d]
yes
```

## Anonymous variable
If we are not interested in the result we use `anonymous` variables with the `underscore _` notation
```prolog
?- [ _,X2, _,X4|_ ] = [mia, vincent, marsellus, jody, yolanda].
X2 = vincent
X4 = jody
yes
```

# Predicates (methods)
The notation here is `predicateName/x` where x is the **parity** / number of arguments of the function

## member/2
**This method finds if the given element X is part of the list T.**
It works by:
- Check if X is the head of the List T
- if not then X is the member of List T with head H **if X is member of the List T**
- Repeat with the new list without the head
```prolog
member(X,[X|T]).
member(X,[H|T]):- member(X,T).
```
More clean
```prolog
member(X,[X|_]).
member(X,[_|T]):- member(X,T).
```

## a2b/2
**This predicate checks if the first argument is a list of (a)s and the second argument is a list of (b)s of exactly the same length**

It works by:
- Let the first case be if they are empty then its true
- if not, take the first head of the first and of both lists and call the function again with the new lists
(Just remember that when we branch down the list, the first a and b are now defined and so if they change along the way, it returns no)
```prolog
a2b([],[]).
a2b([a|L1],[b|L2]):- a2b(L1,L2).
```