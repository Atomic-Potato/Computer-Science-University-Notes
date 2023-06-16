_Previous: [[🟩4 @ Gathering Requirements]]_
_Next:_ [[🟩6 @ Software Requirements Specification (SRS)]]

---

# Modeling (Visualizing) Requirements
After gathering the requirements we need to model / visualize them so we can structure, analyze and refine them. So we have to decide **what we want to model** and **how we want to model it.**

First we need to decide or **emphasis / focus.** And each focus has a **way** to model it:
- `Modeling Enterprise:`
	- goals and objectives
	- organizational structure
	- task and dependencies
	- agents, roles, intentionality
	**These are the possible models for this focus:** #model
	![[Pasted image 20221228175337.png | 300]]
- `Modeling Information And Behaviors:`
	- information structure
	- behavioral view
		- scenarios and use cases
		- state machine models
		- sequence diagrams
		- information flow
	- time / sequencing requirements
	**These are the possible models for this focus:** #model
	![[Pasted image 20221228175424.png | 300]] 
- `Modeling System Qualities` ([[🟩3 @ Requirement Categories#^nonFunctionalRequirements|NFRs]])
	**These are the possible models for this focus:** #model
	![[Pasted image 20221228175457.png | 300]]

#model are complementary to eachother, especially from different categories. They can provide views of the requirements from different perspectives.

---

# Refining Requirements (Analysis)
Develop ideas for solving the user’s problems.

You need to distill the **goals** (what the customers need to do) into **approaches** (how the application will do it).

Figure out how the users will select records to edit, what screens they will use, and how they will navigate between the screens. ([[🟩3 @ Requirement Categories#Common Requirements|Common Requirements]])
	_Those **decisions** will lead to requirements describing the forms, navigation techniques, and other features that the application must provide to let the users do their jobs._

## Analyzing Requirements
There are 3 types of analysis
- `Verification:` Checking for properties and issues discussed in [[🟩2 @ Requirements]] such as completeness, ambiguity, etc.
- `Validation:` validate the requirements with the stakeholder through either the **documentation** or by **testing a prototype**
- `Risk Analysis:` Identify and analyze the main risks. If a requirement deems to be too risky, it may result in changes in the requirements model to address / eliminate these risks

---

# Recording Requirements
**Note:** If you're still struggling to understand this part, it will be explained in detail in this chapter -> [[INSERT NOTE LINK]] _(i forgot which chapter)_

You can just write the requirements down as a **sequence of commandments**

- `User Stories:` a short story explaining how the system will let the user do something. The scope of each story should also be limited so that no story should take too long to implement. And its up to the developer to know how to implement these requirements.
- `Use Cases:` a use case is a description of a series of interactions between actors. The actors can be users or parts of the application.
- `Prototypes:` mockup of some or all of the application. Theres also 2 types:
	- **evolutionary prototype:** a prototype to be used later and continue developing it
	- **throwaway prototype:** a prototype used just for validation and then discarded
- `Requirements Specification` ([[🟩6 @ Software Requirements Specification (SRS)|SRS]]): formally writing the requirements.

---

# Validation And Verification
**Requirement `validation` (during Analysis)** is the process of making sure that the requirements say the right things.

**Requirement `verification`** is the process of checking that the **finished application** actually satisfies the requirements.

**Validation VS Verification:**
![[Pasted image 20221228184450.png | 600]]

# Changing Requirements
In many projects, requirements evolve over time. Often changes are driven by the customers.
Depending on the kind of project, you may accommodate some changes, as long as they don’t get out of hand.

---

_Next:_ [[🟩6 @ Software Requirements Specification (SRS)]]
_Previous: [[🟩4 @ Gathering Requirements]]_