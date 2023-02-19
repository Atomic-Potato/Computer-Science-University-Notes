_Next:_ [[🟩3 @ Relationships Among Use Cases]]
_Previous:_ [[🟩1 @ Unified Modeling Language (UML)]]

---

An actor is **an external entity which interacts (communicates) with the system_(which means it has a role)_**.  It has a unique name and an optional description

_Note that an actor can play more than a role and more than one entity can play the same role_

An actor may represent:
- `Physical User` _(managers, employees, customers, etc.)_
- `External systems`
- `Physical environment` _(weather – input to system through sensors)_

# Primary And Secondary Actors
- `Primary:` solicits the execution of the use case (active role)
- `Secondary:` is solicited during the execution of the use case (passive). And also should have the “secondary”  stereotype on the connection with the feature, unless the actor is autonomous (i have no idea what that means)

_For example:  Bank during online payment. If the client didn’t initiate the active process of paying, the bank wouldn’t be involved._

![[Pasted image 20221230112315.png | 600]]

## Simplification
To simplify this use case we split it into 2 use cases. The link between the actors and their features can be stated in their [[🟩5 @ Detailed Textual Description (DTD)|detailed textual description]]

![[Pasted image 20221230210054.png|600]]

# Inheritance
Actor B inherits actor A if all what A can do, B can do too

![[Pasted image 20221230210433.png | 600]]

---
_Next:_ [[🟩3 @ Relationships Among Use Cases]]
_Previous:_ [[🟩1 @ Unified Modeling Language (UML)]]
