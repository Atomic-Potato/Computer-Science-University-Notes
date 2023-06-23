_Previous:_ [[🟩1 @ Modularity]]
_Next:_ [[🟩3 @ Important Examples]]

___

# Designing Software
## Functional Decomposition
`Top-down`, approach, classic in engineering
- Proceed by decomposition of the main function of the software into sub-problems
-  Repeat the decomposition until you get basic sub problems that are easy to solving it
![[Pasted image 20221208150653.png | 300]]

### Problems
- The software can have multiple main functions.
- In a functional view, with a time division (B then C….), certain distinct parts are difficult to separate from each other, _(e.g. user interface / functional core)_
- Often leads to a specific decomposition, the elements of which are not very reusable

## Object-oriented Software Construction
It is a `bottom-up` process of building robust and extendible solutions to parts of the problem, and combining them into more and more powerful assemblies — until the final assembly which yields a solution of the original problem

This method is `Extendable` and `Reusable` (a set of functions “associated with a type” is more reusable than an isolated function)

### Problems
- How to find the relevant object types.
- How to describe the relations between object types.

--- 
_Next:_ [[🟩3 @ Important Examples]]
_Previous:_ [[🟩1 @ Modularity]]