- A strat to convert to clausal form.
	- First start from the biggest parentheses (i.e. the one that surrounds the most) and convert it to PNF then to clause and then slowly make your way inside instead of making your way out 
	- Example
	  ![[Pasted image 20220630131949.png]]
	  Here it is in the form `!(A and B -> C)` <=> `(A and B and !C)` and so we have it in clausal form, and we just convert each part to skolem form 