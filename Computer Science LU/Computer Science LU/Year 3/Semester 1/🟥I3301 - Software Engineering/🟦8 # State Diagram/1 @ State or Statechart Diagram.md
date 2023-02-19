**State diagrams represent the condition of the system or part of the system at finite instances of time** _(Can be applied to any element that has behavior not only objects)_

State diagrams describe the life of an object using three main elements:
- States of an object  
- Transitions between states
- Events that trigger the transitions

A state diagram or statechart specifies a state machine. A state machine is described for a class. _(Each object has it’s own state machine)_

# States
It is a condition or situation during the life of an object within which it performs some activity, or waits for some events.

It is composed of:
- `name`  
- `actions :`  like execute the state  
- `internal transitions :`  transitions cause no change in a state  
- `substates :` the nested structure of a state involving disjoint or concurrent substates

_Example:_
![[Pasted image 20230207215443.png]]

## Initial & Final States
The `initial` state of a state machine is indicated with a solid circle
The `final` state of a state machine is shown as concentric circles
![[Pasted image 20230207215843.png|400]]

# Actions and Activities
`Actions:` typically one-time behaviors that are triggered by an event or transition. They consume or trigger external events  

`Activities:` ongoing behaviors that continue until they are interrupted or completed. They model the internal behavior of a state, and they don't consume or trigger any external event

_Example:_
![[Pasted image 20230207220349.png]]

# Event
Events appear in the internal transition compartment of a state or on a transition between states

An event **signature** is described as 
```java
event-name(data-type data-name , dt2 dn2, ...)
```

An event may be one of four types:

## Signal Event
The arrival of a signal.

_For example:_
A button press event: buttonPress(Button button)

## Call Event
The arrival of a procedural call to an operation

_For example:_
An event triggered by a request to a services: serviceCall(string serviceName)

## Time Event
An event that happens after a specified time has elapsed.

**Signature:**
```java
after(time)
```

_For example:_
- after(10 seconds after state "At Work" is entered)
- after(2 seconds)

## Changing Event
When a condition is met.

**Signature**
```java
when(condition)
```

_For example:_
- when(state = At Work)
- when(date = Jan 1 2069)

# Transitions
A transition is drawn as an arrow between states annotated with a transition string. The transition string denotes the event and consequent action.

There are 2 kinds of transitions:
- A transition with a guard. 
	If the guard condition is met the transition occurs immediately.
	Else the event is discarded
	**The guard condition is checked only once**
	```java
	event_name [guard_condition]
	```
- A change event, which occurs whenever its associated condition is met
    **It Behaves as if the condition were being continually evaluated**
	```java
	event_name action_or_method_call
	```

A transition whose **string contains neither an event signature nor a guard condition** is said to be `unlabeled`. These kinds of transitions occur immediately and may still carry an action expression

# State Diagram Notation
![[Pasted image 20230207224213.png]]

# Entry & Exit
`Entry action :` any action that is marked as linked to the entry action is **executed whenever the given state is entered** via a transition
![[Pasted image 20230207224514.png]]

`Exit action :` any action that is marked as linked to the exit action is **executed whenever the state is left** via a transition
![[Pasted image 20230207224657.png]]

# Nested States
 If _event-2_ happened being either in _state A_ or _state B_ it will lead to a transition to _state C_
![[Pasted image 20230207225030.png]]

# Concurrent State Model
In the box are 2 different outcomes separated by dashed lines. The subject object can be either in `state S` or `state T`, and not both.

![[Pasted image 20230207225551.png]]