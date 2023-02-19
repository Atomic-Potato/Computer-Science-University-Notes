A sequence diagram is an _"interaction diagram"_  that models a single scenario executing in a system. It shows what messages are sent and when.

To be exact, it shows the interactions between objects in the sequential order that those interactions occur.

It also does the following:
- Models a `single scenario` executing in a system
- Models object communication with each other in a system
- Models `dynamic behavior` of the system
- Provides `High level view` of the system

# Key Parts
- `Participant`: an object or an entity; the sequence diagram actor.
- `Message`: communication between objects
- `Axes` in a sequence diagram:
	- **horizontal**: which participant is acting
	- **vertical**: time (↓ forward in time)

The sequence diagram starts with an unattached "found message" arrow
![[Screen Shot 2023-02-07 at 8.19.08 PM.png|325]]

# Representing Objects
A box with an underlined label that specifies the object type, and optionally the object name. _(Write the object's name if it clarifies the diagram.)_
![[Pasted image 20230207203204.png|200]]

An object's `life line`  represents the life span of the object during the scenario being modeled. It is represented by a dashed vertical line.
![[Pasted image 20230207203254.png|400]]

# Messages
A message _(method call)_ is a horizontal arrow to the receiving object. _(Write message name and arguments above the arrow)_
![[Pasted image 20230207203550.png|250]]

Type of arrow indicates types of messages:
-   `Synchronous message:` requires a response before the interaction can continue. **Represented by a solid arrow with a solid head.**
-   `Asynchronous message:` don't need a reply for interaction to continue. **Represented by a solid arrow with a stick head.**
-   `Return message:` **dashed arrow with stick head.**
![[Pasted image 20230207203930.png|200]]

# Indicating method execution
A method is indicated by a thick box over object's `life line`, drawn when an object's method is on the stack.
Either that object is running its code,  or it is on the stack waiting for another object's method to finish.
![[Pasted image 20230207204458.png|200]]

Nest methods to indicate an object calling itself.
![[Pasted image 20230207204840.png|200]]

# Lifetime of objects
`Object creation:` an arrow with new written above it. An object created after the start of the scenario appears lower than the others.

`Object deletion:` X at the bottom of object's lifeline. Java doesn't explicitly delete objects; they fall out of scope and are garbage collected.

![[Pasted image 20230207205612.png|300]]

# Alternatives, Options, & Loops
`Frame:` a box around part of a sequence diagram
- if → (opt) **[condition]** 
- if/else → (alt) **[condition]**, separated by horizontal dashed line 
- loop → (loop) **[condition or items to loop over]**
![[Pasted image 20230207210004.png|500]]

# Linking Sequence Diagrams
If one sequence diagram is too large or refers to another diagram, we can do one of the following ways:
- An unfinished arrow and comment.
	![[Pasted image 20230207210556.png|200]]
-   A `ref` frame that names the other diagram.
	![[Pasted image 20230207210640.png|250]]
