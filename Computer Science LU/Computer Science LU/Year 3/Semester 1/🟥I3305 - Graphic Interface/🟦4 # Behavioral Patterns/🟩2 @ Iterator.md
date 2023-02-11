_Next [[🟩3 @ Visitor]]_
_Previous [[🟩1 @ Behavioral Patterns]]_

---
`Iterator` is a behavioral design pattern that lets you **traverse elements of a collection without exposing its underlying representation** _(list, stack, tree, etc.)_ 

Iterator pattern is very commonly used design pattern in Java and .Net programming environment.

_Example : Java collections iterators_

# Problem
Collections are one of the most used data types in programming. Nonetheless, a collection is just a container for a group of objects.

If you have a collection based on a list. You just loop over all of the elements. But how do you sequentially traverse elements of a complex data structure, such as a tree?
![[Pasted image 20230210144438.png|700]]

# Solution
The main idea of the Iterator pattern is to **extract the traversal behavior of a collection into a separate object called an `iterator`.**

Usually, iterators provide one primary method for fetching elements of the collection.

**All iterators must implement the same interface.**

If you need a special way to traverse a collection, you just create a new iterator class, without having to change the collection or the client.

![[Pasted image 20230210144649.png|350]]

# Structure
![[Pasted image 20230210144758.png|500]]
The `Iterator interface` declares the operations required for traversing a collection: _fetching the next element, retrieving the current position, restarting iteration, etc._

`Concrete Iterators` implement specific algorithms for traversing a collection.

The `Collection interface` declares one or multiple methods for getting iterators compatible with the collection. 
**_Note:_** the return type of the methods must be declared as the iterator interface so that the concrete collections can return various kinds of iterators.

`Concrete Collections` return new instances of a particular concrete iterator class each time the client requests one

# Example
**Prerequisites:**
![[Pasted image 20230210145136.png|700]]

**Iterator:**
![[Pasted image 20230210145211.png|500]]

**Application:**
![[Pasted image 20230210145245.png|600]]

---

_Next [[🟩3 @ Visitor]]_
_Previous [[🟩1 @ Behavioral Patterns]]_
