_Next [[🟩4 @ Strategy]]_
_Previous [[🟩2 @ Iterator]]_

---
The purpose of a `Visitor pattern` is to **define a new operation without introducing the modifications to an existing object structure.**

# Problem
Imagine that we have a [[🟩4 @ Composite Pattern|composite object]] which consists of components. The object’s structure is fixed, we either can’t change it, or we don’t plan to add new types of elements to the structure.

Now, how could we add new functionality to our code without modification of existing classes?

_For example:_ 
We need to add the following functionality to the example mentioned in [[🟩4 @ Composite Pattern]]:

1. _Print()_ the names and their corresponding salaries of all the employees _(except managers)_ of a given manager.
2. _Increase()_ the salary of all the employees of a given manager _(manager included)_.

![[Pasted image 20230210152909.png|500]]

# Solution
We need to do the following:
- `EmployeeVisitable interface`. Declares accept method.
- Our base class, `Employee`, implements `EmployeeVisitable`
- **_accept()_** takes an `EmployeeVisitorobject` as argument
- Implementations of accept invoke **_EmployeeVisitor.visit()_** as appropriate
	- **_accept()_** `Developer` and `Designer` invoke **_visit()_** for this
	- _**accept()**_ in `Manager` invokes **_visit()_** for this and then invokes **_accept()_** for all subordinate employees, which will cause visit to be called for them, and all their subordinates, etc.

![[Pasted image 20230210153228.png|500]]

## Implementation
_(Feel free to skip to [[🟩3 @ Visitor#Structure|Structure]])_

![[Pasted image 20230210153309.png|550]]
![[Pasted image 20230210153329.png|550]]
![[Pasted image 20230210153344.png|700]]
![[Pasted image 20230210153358.png|700]]
![[Pasted image 20230210153426.png|700]]
![[Pasted image 20230210153441.png|550]]

# Structure
![[Pasted image 20230210153555.png]]
The `Visitor interface` declares a set of _**visiting**_ methods that can take concrete elements of an object structure as arguments.

Each `Concrete Visitor` implements several versions of the same behaviors, tailored for different concrete element classes.

The `Element interface` declares a method for _**“accepting”**_ visitors.

Each `Concrete Element` must implement the **_acceptance_** method. The purpose of this method is to redirect the call to the proper visitor’s method corresponding to the current element class.

## Sequence Diagram
![[Pasted image 20230210153900.png|500]]

---
_Next [[🟩4 @ Strategy]]_
_Previous [[🟩2 @ Iterator]]_