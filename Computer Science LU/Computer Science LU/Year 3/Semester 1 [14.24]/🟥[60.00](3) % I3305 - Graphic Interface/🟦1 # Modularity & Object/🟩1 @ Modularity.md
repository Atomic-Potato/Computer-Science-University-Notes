_Next:_ [[🟩2 @ Object]]

---
# What is **Modularity**?
Modularity is breaking down a problem into smaller parts that can be translated into code. 

## The **goals** of modularity
- Extendable, Readable, reliable, reusable, maintainable components
- Smaller problems are easier to understand
- Easier to test/ debug
- Easier to update in future releases
- Distribution of effort team

### Ideal Qualities of a good Module
- Encapsulates just one system task or function
- Reusable
- Testable:
	Some say a module is the smallest chunk of code that can be tested independently
- Hides a design decision from the rest of the system
- Can be modified internally without affecting the rest of the system
## What can be a module & what makes it good
- Any basic block of code
- if you can take a piece of code an encapsulate it in some way, then it can become a module

To make a good module you have to answer these questions:
- What should be a separate module or subprogram and why?
- How do modules share information?
- What should modules « know» about other modules or the rest of the system?
- How is control organized in the system?

## Criteria of modular architecture
- **`Decomposability`**: if it helps in the task of decomposing a software problem into a small number of less complex subproblems
- **`Composability`** : if it favors the production of software elements which may then be freely combined with each other to produce new systems
- **`Understandability`** : if it helps produce software in which a human reader can understand each module without having to know the others
- **`Continuity`**: a small change in a problem specification will trigger a change of just one module, or a small number of modules.
- **`Protection`** : if it yields architectures in which the effect of an abnormal condition occurring at run time in a module will remain confined to that module
- **`Information Hiding`**
- **`Uniform Access`**: A rule which influences many aspects of object-oriented design and the supporting notation (getter Setter methods).
- **`The Open-Closed principle`**:
	A module is said to be open if it is still available for extension and closed to modifications. (e.g. inheritance)
---
# Information Hiding
`Information Hiding` is the principle of segregation _(differentiation)_ of the design decisions in a computer program that are most likely to change, thus protecting other parts o program from extensive modification if the design decision is changed.
![[Pasted image 20221208144056.png | 500]]

# Inheritance and modularity
The ingredients of the `Inheritance`
- new definitions and redefinitions (Overriding)
- [[🟩8 @ Polymorphism & Dynamic Binding#Polymorphism|Polymorphism]]
- [[🟩8 @ Polymorphism & Dynamic Binding#Dynamic Binding|Dynamic binding]]

Allow the principle of opening / closing to be applied:
- the parent class (SuperClass) is not changed by inheritance, as a module it remains closed to modifications
- the child class (SubClass) inherits the characteristics of its parents but can change and complete them, it constitutes the same module but open to extensions
---
_Next:_ [[🟩2 @ Object]]