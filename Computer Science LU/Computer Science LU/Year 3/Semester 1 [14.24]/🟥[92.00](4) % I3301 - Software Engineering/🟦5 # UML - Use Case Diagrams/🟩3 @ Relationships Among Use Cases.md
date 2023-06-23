_Next:_ [[🟩4 @ Scenarios]]
_Previous:_ [[🟩2 @ Actors]]

--- 

# Types

## Extends
**Definition:** X extends Y _equivalent to_ X might be optionally executed from Y. Alternatively, seldom (rarely) invoked use cases or optional functionalities (not necessarily executed)

**Arrow direction is from extending _(X)_ to extended use case _(Y)_**

It models a special alternative branch in a use case scenario.

_Example_
![[Pasted image 20221230220736.png | 400]]

## Includes
**Definition:** X includes Y _equivalent to_ X requires/triggers the execution of Y. Alternatively, functions automatically/necessarily triggered in another one.

**Arrow direction is from including _(X)_ to included use case _(Y)_**

_Example_
![[Pasted image 20221230221342.png|400]]

## Generalizes
**Definition:** X generalizes Y _equivalent to_ Z ó X can be performed as either Y or Z. Alternatively, function that may occur in two or more different ways.

_Example_
![[Pasted image 20221230222148.png|400]]

its sort of like an if statement as well
![[Pasted image 20230315193316.png]]


## Note
Both `included` and `extended` use cases can be common to more than one other use cases. Alternatively meaning use case **factorization** and **reuse**.

![[Pasted image 20221230221911.png | 400]]

--- 

# Relationships rules
1. No `include` nor `extend` from 2 use cases of 2 different actors _(Exception: when solicited actor is an automated external system)_. However this can be stated in the [[🟩5 @ Detailed Textual Description (DTD)|detailed textual description]]
2. No `include` between any use case and the `login` use case _(idk why he had to include this)_
	![[Pasted image 20221230223534.png | 400]]
3. No link between an actor and an `extended` use case _(Unless the actor is an automated system or a secondary actor)_
4. No link between an actor and an `including` use case _(Unless the actor is an automated system or a secondary actor)_

**Note:** Sometimes an actor can trigger both use cases with a relation.
_Example:_ 
If a customer wants to buy an item, he doesn’t necessarily have to search for it to buy it (maybe it was on his “recommended” page). However, the user can buy an item while searching. _(client is the actor of buying & searching. And, buying extends searching)_

# Rule of Thumb
Use them only when clear and necessary to vehicle a specific idea. Do not overuse them!!

---

_Next:_ [[🟩4 @ Scenarios]]
_Previous:_ [[🟩2 @ Actors]]
