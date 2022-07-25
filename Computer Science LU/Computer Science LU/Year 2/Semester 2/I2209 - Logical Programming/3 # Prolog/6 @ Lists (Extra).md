# append/3
**Appends two lists together**
Arguments: (List1, List2, Result)
How it works:
- Get to the last head of the first list
- Add the second List
- Append the heads to the start of the second list as you go back in recursion 
	```prolog
	append([], L, L).
	apend([H|L1], L2, [H|L3]):- append(L1, L2, L3).
	```
	Best explained with a search tree
	![[Pasted image 20220722151108.png | 450]]

## prefix/2
**Gets you the start of the list**
```prolog
prefix(P,L):- append(P,_,L)

%Example:
?-prefix(X, [a,b,c,d])
X=[];
X=[a];
X=[a,b];
X=[a,b,c];
X=[a,b,c,d];
no
```

## suffix/2
**Gets the end of the list**
```prolog
suffix(S,L):- append(_,S,L)

%Example:
?-prefix(X, [a,b,c,d])
X=[a,b,c,d];
X=[a,b,c];
%...
```

## sublist/2
**Its just mixing both suffix and prefix**
```prolog
sublist(Sub, List):- suffix(Suffix,List), prefix(Sub, Suffix).
```

# Efficiency of append/3
If the order of appending lists doesnt matter then it would be inefficient to traverse down the longer list instead of the smaller list (e.g. a list with millions of elements and a list of a single element)

But if we do, we can make our code more efficient with reversing

## Reversing a list 
How it works: **(The naive way)**
- Ending condition: reversing an empty list returns an empty list
- If we reverse the list [H|T], we end up with the list obtained by reversing T and concatenating it with [H]
	```prolog
	naiveReverse([],[]).
	naiveReverse([H|T],R):- naiveReverse(T,RT), append(RT,[H],R).
	```
	This works but its inefficient

**Reversing with an accumulator**
How its works:
- The accumulator will be a list, and when we start reversing it will be empty
- We simply take the head of the list that we want to reverse and add it to the the head of the accumulator list
- Repeat until the list is empty, and then the Acc. list will be the reversed list 

	```prolog
	accReverse([ ],L,L).
	accReverse([H|T],Acc,Rev):- accReverse(T,[H|Acc],Rev).
	
	%wrapper
	reverse(L1,L2):- accReverse(L1,[ ],L2).
	```