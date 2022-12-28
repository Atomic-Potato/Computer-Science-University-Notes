_Previous:_ [[🟩2 @ Requirements]]
_Next:_ [[🟩4 @ Gathering Requirements]]

--- 
# Audience-Oriented

- `Business requirements` lay out the project’s high‐level goals. They explain what the customer hopes to achieve with the project.
	_The business case is a more marketing‐style document that attempts to justify the project._
- `User Requirements:` They often include things like sketches of forms, scripts that show the steps users will perform to accomplish specific tasks, use cases, and prototypes.
	_Often they specify what  the user needs to accomplish but not necessarily how the application must accomplish it._
- `Functional Requirements:` detailed statements of the project’s desired capabilities. They not only describe a task that will be performed by the user, but they also describe something that the application will do. 
	_similar to the user requirements but they may also include things that the users won’t see directly (reports, interfaces to other applications)._ ^functionalRequirements

- `Non-functional Requirements:` statements about the quality of the application’s behavior or constraints on how it produces a desired result. 
	_performance, reliability, and security characteristics_ ^nonFunctionalRequirements
- `Implementation Requirements:` temporary features that are needed to transition to using the new system but that will be later discarded.
	Other implementation requirements include:
	- hiring new staff,
	- buying new hardware,
	- preparing training materials,
	- and actually training the users to use the new system.

## Functional VS Non-Functional Requirements
- `Functional:`
	- Product features
	- Describe the work that is done
	- Describe the actions with which the work is concerned
	- Characterized by verbs
- `Non-Functional:`
	- Product properties
	- Describes the characteristics of the work _(For example an elevator should take 30 seconds to reach the top floor)_
	- Describe the experience of the user while doing work
	- Characterized by adjectives

## User VS System Requirements
- `User Requirements:`
	- Written for customers
	- Often in natural language, no technical details
- `System Requirements:`
	- Written for devs
	- detailed functional and non-functional requirements
	- clearly and more rigorously specified

_Example:_
![[Pasted image 20221228143153.png | 700]]

---

# Common Requirements
- `Screens:` What screens are needed?
- `Menus:` What menus will the screens have?
- `Navigation:` How will the users navigate through different parts of the system?
	_buttons, use menus, or click forward and backward arrows? Or some combination of those methods?_
- `Work flow:` How does data (work orders, purchase requests, invoices, and other data) move through the system?
- `Login:` How is login information stored and validated?
	_What are the password formats (such as, must require at least one letter and number) and rules (as in, passwords must be changed monthly)?_
- `User types:` Are there different kinds of users such as order entry clerk, shipping clerk, supervisor, and admin?
- `Audit tracking and history:` Does the system need to keep track of who made changes to the data?
- `Archiving:` Does the system need to archive older data to free up space in the database? Does it need to copy data into a data warehouse for analysis?
- `Configuration:`Should the application provide configuration screens that let the system administrators change the way the program works?

---

_Next:_ [[🟩4 @ Gathering Requirements]]
_Previous:_ [[🟩2 @ Requirements]]