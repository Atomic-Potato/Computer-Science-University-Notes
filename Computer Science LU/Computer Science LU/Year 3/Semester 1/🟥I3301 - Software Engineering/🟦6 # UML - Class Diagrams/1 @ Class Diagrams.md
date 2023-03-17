A class diagram is static, structural view of the system. And it describes classes and their structure relationships among classes.

# The parts of a class diagram
- `Classes : ` represnt the types of data themselves
- `Associations : ` represent linkages between instances of classes
- `Attributes : ` are simple data found in classes and their instances
- `Operations : ` represent the functions performed by the classes and their instances
- `Generalizatiins : ` group classes into inheritance hierarchies

# Classes
A class is simply represented as a box with the name of the class inside
The diagram may also show the attributes and operations

The complete signature of an operation is:
```c
operationName(parameterName: parameterType …): returnType
```
![[Screen Shot 2023-02-07 at 3.37.19 PM.png]]

# Relationships
There are different types of relations in a class diagram:

## `Dependency` 
X uses/depends on Y, its represented with a doted arrow from X to Y 
	![[Screen Shot 2023-02-07 at 3.49.26 PM.png|150]]

## `Association` 
Represented with a straight line. It is also the same as in databse, like one to many and many to one: 
**Its important to note that this relation works 2 ways, from X to Y and from Y to X**	
![[Screen Shot 2023-02-07 at 3.50.57 PM.png|150]]
![[Screen Shot 2023-02-07 at 4.22.07 PM.png|150]]

For example:
	![[Screen Shot 2023-02-07 at 4.24.33 PM.png]]
	
![[Screen Shot 2023-02-07 at 4.28.14 PM.png]]

Theres also reflexive associations, i.e. the class has an association with itself.
	
If we want to have a one way association, we add an arrow head
![[Screen Shot 2023-02-07 at 4.36.20 PM.png|300]]
	
## `Aggregation`  
Its a special association that represent **`part-whole`** relationships, 
The `whole` side is often called the **assembly** or the **aggregate**
This symol is a shorthand notation association name **isPartOf**
![[Screen Shot 2023-02-07 at 4.46.36 PM.png|300]]

### When to use aggeregation
As a general rule, you can mark an association as an aggregation if the following are true:
- the parts **are part of** the aggregate
- or the aggregate **is composed of** the parts

When something owns or controls the aggregate, then they also own or control the parts

## `Composition`
Composition is actually a special case of the aggregation relationship. Aggregation models _has-a_ relationships and represents an ownership relationship between two objects. 
**The owner object is called an aggregating object and its class an aggregating class**. 
**The subject object is called an aggregated object and its class an aggregated class.**

An object may be owned by several other aggregating objects. If an object is exclusively owned by an aggregating object, the relationship between them is referred to as composition. 

![[Screen Shot 2023-02-07 at 5.02.05 PM.png]]


For example, “a student has a name” is a composition relationship between the Student class and the Name class, whereas “a student has an address” is an aggregation relationship between the Student class and the Address class, because an address may be shared by several students.

## `Generalization` 
X is a Y, represented with a straight line and a hollow arrow
**Remember that this also means inheritance!**
![[🟩3 @ Relationships Among Use Cases#Generalizes|It is the same as in a use case diagram]]

## `Implementation` _(interfaces)_
An interface describes a portion of the visible behaviour of a set of objects.

An interface is similar to a class, except it lacks instance variables and implemented methods.

![[Screen Shot 2023-02-07 at 5.04.48 PM.png|300]]


# `Comments / notes` 
Optional descriptive text:
![[Screen Shot 2023-02-07 at 5.10.35 PM.png|300]]

---
_(In all of these cases, the arrow starts from X and ends with Y)_