_Next [[🟩5 @ Proxy Pattern]]_
_Previous [[🟩3 @ Bridge Pattern]]_

---
`Composite` is a structural design pattern that lets you **compose objects into tree structures** and then work with these structures as if they were individual objects.

In other words, when we need to create a structure in a way that the objects in the structure has to be treated the same way, we can apply composite design pattern.

In object-oriented programming, we make a composite object when we have many objects with common functionalities. This relationship is also termed a _“has-a”_ relationship among objects.

# Problem
A Box can contain several Products as well as a number of smaller Boxes. These little Boxes can also hold some Products or even smaller Boxes, and so on.
_How would you determine the total price of such an order?_
![[Pasted image 20230210133123.png|300]]

The direct approach would be to unwrap all boxes and go over all the products, which would work IRL. But in a program its not as simple, you have to know the classes of the objects as you go through them beforehand.

# Solution
![[Pasted image 20230210133401.png|300]]

The `Component interface` describes operations that are common to both simple and complex elements of the tree.

The `Leaf` is a basic element of a tree that **doesn’t have sub-elements**.

The `Container` _(aka composite)_ is an element that has sub-elements: leaves or other containers. 
**A container doesn’t know the concrete classes of its children**. It works with all sub-elements only via the component interface.
Upon receiving a request, a container delegates the work to its sub-elements, processes intermediate results and then returns the final result to the client.

## Solution Example
![[Pasted image 20230210133652.png|700]]
![[Pasted image 20230210133719.png|700]]

![[Pasted image 20230210133800.png|500]]
![[Pasted image 20230210133812.png]]
![[Pasted image 20230210133822.png|450]]
![[Pasted image 20230210133844.png|500]]

---

_Next [[🟩5 @ Proxy Pattern]]_
_Previous [[🟩3 @ Bridge Pattern]]_