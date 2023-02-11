_Next [[🟩6 @ Observer-MVC]]_
_Previous [[🟩4 @ Strategy]]_

---

`Observer` is a behavioral design pattern that lets you **define a subscription mechanism to notify multiple objects** about any events that happen to the object they’re observing.

# Problem
Imagine creating an application that can have several graphical representations for the same object.

How to notify graphical representations of changes?
![[Pasted image 20230210162444.png|500]]

# Solution
The object that has some interesting state is often called _subject_, but since it’s also going to notify other objects about the changes to its state, we’ll call it `publisher`.
All other objects that want to track changes to the publisher’s state are called `subscribers`.

The Observer pattern suggests that you add a **subscription mechanism** to the publisher class so individual objects can _**subscribe**_ to or **_unsubscribe_** from a stream of events coming from that publisher.
![[Pasted image 20230210162650.png|400]]

# Structure
![[Pasted image 20230210162832.png|700]]
The `Publisher` issues events of interest to other objects. These events occur when the publisher changes its state or executes some behaviors.
_When a new event happens, the `publisher` goes over the **subscription** list and calls the **notification method** declared in the `subscriber interface` on each `subscriber object`._

The `Subscriber interface` declares the `notification interface`. In most cases, it consists of a single **_update method_**.

The `Client` creates a `publisher` and `subscriber` objects separately and then registers subscribers for publisher updates.

---
_Next [[🟩6 @ Observer-MVC]]_
_Previous [[🟩4 @ Strategy]]_
