_Previous [[🟩5 @ Observer]]_

---

# Model View Controller (MVC)
- The `Model` is the actual internal representation.
- The `View` is a way of looking at or displaying the model
- The `Controller` acts on both `model` and `view`. It controls the data flow into model object and updates the view whenever data changes.

_These three components are usually implemented as separate classes._

# Model
The Model is the part that does the work. **It models the actual problem being solved**. It should be independent of both the `Controller` and the `View`, but it provides methods for them to use. _Independence gives flexibility._

# Controller
The Controller **decides what the `model` is to do.**

Often, the user is put in control by means of a GUI, in this case, **the `GUI` and the `Controller` are often the same** **_(bad design)_**

The `Controller` and the `Model` can always be separated _(what to do, controller, versus how to do it, model)_

The `Model` should not depend on the `Controller`

# View
Typically, the user has to be able to see, or view, what the program is doing. **The View describes the state of the `Model`**

The `Model` should be **independent** of the `View`, but it can provide access methods. It is more flexible to let the `View` be independent of the model.

# Combining Controller & View
Sometimes the `Controller` and `View` are combined, especially in small programs. Combining the `Controller` and `View` is appropriate if they are very interdependent.

The `Model` should still be independent. **Never mix `Model` code with `GUI` code!**

# MVC in Java: Observer & Observable

## Observable
An Observable is an object that can be observed

An `Observer` is notified when an object that it is observing announces a change

When an `Observable` wants the world to know about what it has done, it executes:
```java
setChanged();
notifyObservers();
```

The `Observable` doesn't know or care who is looking. But you have to attach an `Observer` to the `Observable` with:
```java
myObservable.addObserver(myObserver);
```
**This is best done in the `controller` class, not in the `model` class!**

## Observer
Observer is an interface
An `Observer` implements:
```java
public void update ( Observable obs , Object arg)
```
This method is invoked whenever an `Observable` that it is listening to does an **_notifyObservers([obs])_** and the `Observable` object called **_setChanged()_**
_The obs argument is a reference to the observable object itself._

# Example (a counter app)
![[Pasted image 20230210170036.png|700]]

## Model
![[Pasted image 20230210170103.png|500]]

## View
![[Pasted image 20230210170132.png|700]]

## Controller
![[Pasted image 20230210170212.png|700]]

# Diagram
![[Pasted image 20230210170339.png|350]]
- The user interacts with the `view`.
- `Controller` calls methods of the `model` _(to update or to get some information)_
- `Controller` sends the data to the `viewer`.

---
_Previous [[🟩5 @ Observer]]_
