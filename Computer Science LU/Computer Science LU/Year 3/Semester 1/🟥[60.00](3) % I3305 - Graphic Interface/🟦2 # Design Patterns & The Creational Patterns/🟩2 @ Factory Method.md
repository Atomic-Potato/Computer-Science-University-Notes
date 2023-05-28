_Next [[🟩3 @ Builder Pattern]]_
_Previous [[🟩1 @ Design Patterns]]_

---
**_Its recommended that you read this pattern twice to understand it_**

---

# When do we use the `Factory Pattern`?
The `Factory Pattern` is used to create different objects from a **factory**.  If we have a **super class** and **n sub-classes**, and based on **input parameters**, we have to return the object of one of the sub-classes, we use a factory pattern . ^factoryPattern

In Factory pattern, we create object **without exposing the creation logic** to the client and refer to newly created object using a common interface. So instead of having object creation code on client side we encapsulate inside a **Factory method**.

**The `new` operator is considered harmful**

# Problem
_(I dont really understand the problem, but once you read the example you'll realize how useful this pattern is)_

A framework needs to standardize the architectural model for a range of applications, but allow for individual applications to define their own domain objects and provide for their instantiation.

# Example
_Skip to [[🟩2 @ Factory Method#Structure|Structure]] if you already grasp this pattern_

Imagine that you’re creating a simulator to represent a bicycle race _(with different types of races)_, a race consists of many bicycle, _(i.e. **bicycle for normal race**, **Road bicycle for the tour de France race** and **Mountain Bicycle for Cyclocross race**)_

## The traditional bad solution
![[Pasted image 20230122120441.png | 700]]

```java
public class Race{
	List<Bicycle> bikes;
	
	public void createRace(String type){
		if(type.equals("Normal"))
			// add to "bikes", bicycles of class Bicycle
			// (using new Bicycle())
		else if(type.equals("Tour de France"))
			// add to "bikes", bicycles of class RoadBicylce
			// (using new RoadBicycle())
		else if(type.equals("Cyclocross"))
			// add to "bikes", bicycles of class MountainBicycle 
			// (using new MountainBicycle())
	}
}
```

The **problems** with this solution:
- What if the types of bicycles needed extra work _(extra parameters, methods)_, then you have to, for example, add these parameters to the `createRace()` function and that the user may fill without needing to
- Solution is not clean, i.e. its hard to add new race types/bicycle types without modifying existing methods _(createRace() in this case)_

## Factory Method Solution
The Factory Method pattern suggests that you **replace direct object construction calls** _(using the `new` operator)_ **with calls to a special factory method**. 

_Note that the objects are still created via the `new` operator, but it’s being called from within the factory method._

![[Pasted image 20230122121733.png | 900]]

_Reminder: [[🟩9 @ Abstract & Interfaces#`abstract`|abstract keyword]]_

- Factory class: 
	```java
	public abstract class Race{
		List<Bicycle> bikes'
		
		// Factory Method
		abstract Bicycle createBicycle();
		
		public void createRace(){
			for(int i=0; i<n; i++)
				bikes.add(createBicycle());
		}
	}
	```
	
- Creator Classes:
	```java
	public class NormalRace extends Race{
		@Override
		Bicycle createBicycle(){
			return new Bicycle();
		}
	} 
	```
	
	```java
	public class TourDeFrance extends Race{
		@Override
		Bicycle createBicycle(){
			return new RoadBicycle();
		}
	} 
	```
	
	```java
	public class CycloCross extends Race{
		@Override
		Bicycle createBicycle(){
			return new MountainBicycle();
		}
	} 
	```
	
- Execution:
	```java
	Race race = new TourDeFrance();
	race.createRace();
	```

---

# Structure
![[Pasted image 20230122122446.png|800]]

- The `Creator` class declares the factory method that returns new product objects. **It’s important that the return type of this method matches the `Product` interface.**
	- `Concrete Creators` override the base factory method so it returns a different type of product.
- The `Product` declares the interface, which is common to all objects that can be produced by the creator and its subclasses.
	- `Concrete Products` are different implementations of the product interface.

---
_Next [[🟩3 @ Builder Pattern]]_
_Previous [[🟩1 @ Design Patterns]]_
