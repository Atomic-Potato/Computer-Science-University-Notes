_Next [[🟩2 @ Factory Method]]_

---

In software engineering, a `design pattern` is a general **repeatable solution** to a **commonly occurring problem** in the design of object-oriented applications. ^designPattern

Note that at the design level, Design Patterns are independent of the programming languages used.

# Building Blocks of A Design Pattern
- `Name :` which allows to identify it clearly
- `Problem :` explains the problem and its context.
- `Solution :` describes the elements that make up the design, their relationships, responsibilities, and collaborations (UML)
	_The solution doesn't describe a particular concrete design or implementation, because a pattern is like a template that can be applied in many different situations._

# Types of Design Patterns
There are **23 design patterns** which can be classified in three categories:

## Creational
These design patterns provide a way to create objects while **hiding the creation logic**, rather than instantiating objects directly using new operator.

This gives program more flexibility in deciding which objects need to be created for a given use case.

Some of the patterns that  concern the process of object creation:
- [[🟩2 @ Factory Method|Factory Method]]
- [[🟩3 @ Builder Pattern|Builder]]
- [[🟩4 @ Singleton Pattern|Singleton]]

## Structural 
These design patterns deal with decoupling interface and implementation of classes and objects. Plus the composition of classes or objects

Some of the patterns that deal with the composition of classes or objects:
- [[🟩2 @ Flyweight Pattern|Flyweight]]
- [[🟩3 @ Bridge Pattern|Bridge]]
- [[🟩4 @ Composite Pattern|Composite]]
- [[🟩5 @ Proxy Pattern|Proxy]]

## Behavioral
These design patterns deal with dynamic interactions among societies of classes and objects
and how they distribute responsibility.

Some of the patterns that characterize the ways in which classes or objects interact and distribute responsibility:
- `Visitor`
- `Observer-MVC`
- `Strategy`
- `Iterator`

---

_Next [[🟩2 @ Factory Method]]_
