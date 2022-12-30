_Next:_ [[🟩2 @ Actors]]

---


UML depicts and object oriented (OO) system. Its better to use a UML since programming languages are not abstract enough for OO design, and now days UML is an open standard among companies. Many programmers either know UML or a UML-like variant

# UML Diagrams
- `Use Case diagram:` Describes functional behavior of the system as seen by the user
- `Class diagram:` Describes static structure of the system: object, attributes, associations
- `Sequence Diagram:` Describes dynamic behavior between objects of the system
- `Statechart diagram:` Describes dynamic behavior of an individual object

Extra diagrams: Object Diagram and Activity Diagram

# Tools to draw UML
![[Pasted image 20221230102242.png | 700]]

# Use Case Diagrams (UCD)
UCDs are used during [[🟩6 @ Software Requirements Specification (SRS)|requirements specification]] and analysis to represent external behavior (visible from the outside of the system)

In UCDs we have:
- An `Actor` represents a role, that is, a type of user of the system ^actor
- A `Use Case` represents a class of functionality provided by the system _(The use case must be a certain feature/act that has a meaning, like purchasing a ticket and not like pressing a button)_ ^useCase
- `Use Case Model:` The set of all use cases that completely describe the functionality of the system.

_Example: An actor (passenger) with a use case (purchase ticket):_
![[Pasted image 20221230102641.png | 300]]

_Example: Use case model_
![[Pasted image 20221230103040.png | 400]]

# Importance of Use Cases
- `Requirement` [[🟩1 @ Requirements Engineering#^elicitation|elicitation]]`:` easier to describe what the system should do if we think of it as scenarios of usage
- `Architectural analysis:` building block for architectural analysis of our system (it will help in the case diagram)
	![[Pasted image 20221230104131.png | 200]]
- `User prioritization:` You may want to make a distinction between the users / actors and give different functionality, _for example provide functionality with the administrator and then the client._ Or you can prioritize features
- `Planning:` helps better plan the development of the software
- `Testing:` Use cases allow for early description of system functionality & interaction which means we can easily define test cases even before writing the code

---
_Next:_ [[🟩2 @ Actors]]