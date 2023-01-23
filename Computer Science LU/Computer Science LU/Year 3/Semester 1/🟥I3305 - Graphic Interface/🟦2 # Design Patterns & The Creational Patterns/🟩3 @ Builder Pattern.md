_Next [[🟩4 @ Singleton Pattern]]_
_Previous [[🟩2 @ Factory Method]]_

---

`Builder` is a creational design pattern that lets you **construct complex objects step by step**. The pattern allows you to produce different types and representations of an object using the same construction code.

_For example:_
The process of building a burger, first you bake the bun, then you girl the cheese, make the salad, etc.
You build complex objects step by step.

# Problem (implementation)
The first approach is to make a **super class** that contains the common building steps for any kind of product / sub-class. And then make a **sub-class** for each different type of object with different variables and building steps. However this may **make the program too complex.**

The second approach is to make a constructor that has many parameters, and let the client pick which parameters to be constructed. So not all of them may be used and its quite messy.
![[Pasted image 20230122130828.png|550]]

# Structure
![[Pasted image 20230122131019.png | 550]]

- The `Builder` interface declares product construction steps that are common to all types of builders.
- `Concrete Builders` provide different implementations of the construction steps. Concrete builders may produce products that don’t follow the common interface.
- `Products` are resulting objects. Products constructed by different builders don’t have to belong to the same class hierarchy or interface.

## Director
The `Director` class defines **the order in which to execute the building steps**, while the builder provides the implementation for those steps. 

Having a director class in your program **isn’t strictly necessary**. You can always call the building steps in a specific order directly from the client code.

In addition, the director class completely h**ides the details of product construction from the client code**. The client only needs to associate a builder with a director, launch the construction with the director, and get the result from the builder.

## Improving Structure With A Director
![[Pasted image 20230122131654.png|550]]
- The `Client` must associate one of the builder objects with the director.
- The `Director` class defines the order in which to call construction steps, so you can create and reuse specific configurations of products.

# Example
_I recommend you find a better example, since in this one the building order of the product doesn't make any difference_

- Product Class
	![[Pasted image 20230122131856.png|550]]
-  Abstract builder class:
	![[Pasted image 20230122131921.png|550]]
- Concrete builder class:
	![[Pasted image 20230122131949.png|400]]
	![[Pasted image 20230122132010.png|400]]
- Director Class:
	![[Pasted image 20230122132052.png|550]]
- Main program:
	![[Pasted image 20230122132112.png|550]]

---
_Next [[🟩4 @ Singleton Pattern]]_
_Previous [[🟩2 @ Factory Method]]_
