_Previous:_ [[🟩1 @ Requirements Engineering]]
_Next:_ [[🟩3 @ Requirement Categories]]

---

**Requirements come from:** stakeholders, application domain/context/business, documentation (i dont get the documentation one)

# What are requirements
![[Pasted image 20221227182632.png | 700]]
- `Machine Domain:` The hardware, OS, libraries, etc. on which the software operates on.
- `Application Domain:` The world in which the software will operate.
	- **Domain Properties:** the assumptions we make on the domain
	- **Requirements:** the actual requirements we aim to collect
- `Specification:` It's description of what the system should do to meet the requirements. To help define the specification we have 2 types of phenomenon:
	- Events in the real-world that the machine can directly sense _(Application Domain -> Machine Domain)_
		_Example: A button being pushed, a sensor being activated_
	- Actions in the real-world that the machine can directly cause _(Machine Domain -> Application Domain)_
		_Example: Image appearing on a screen, a device being turned on/off_

# Properties
- `Clear:` They can’t be pumped full of management‐speak, florid text, and confusing jargon. And must state in concrete, no‐nonsense terms, exactly what it requires.
- `Unambiguous:` Make sure you can’t think of any way to interpret them other than the way you intend.
- `Consistent:` Cannot **contradict** eachother. Dont provide many constraints that problems become unsolvable
- `Fast, good, cheap. Pick 2:` It has only 3 possible combinations _(do i really have to point them out?)_
- `Verifiable` 
- `Limited and precisely defined`

# Words to Avoid
- `Comparatives:` Words like faster, better, more, and shinier. How much faster?
	_It's always better when the description is **quantifiable**_
- `Imprecise adjectives:` Words like fast, robust, user‐friendly, efficient, flexible, and glorious.
- `Vague commands:` Words like minimize, maximize, improve, and optimize.

# MOSCOW Method
Requirements must be **prioritized.** If you’ve assigned costs (usually in terms of time to implement) and  priorities to the requirements, then you can defer the high‐cost, low‐priority requirements until a later release.

We use the `moscow` method to split prioritization into sections:
- `M—Must`: These are required features that must be included. They are necessary for the project to be considered a success.
- `S—Should`: These are important features that should be included if possible. If there’s a work-around and there’s no room in the release 1 schedule, these may be deferred until release 2.
- `C—Could`: These are desirable features that can be omitted if they won’t fit in the schedule. They can be pushed back into release 2, but they’re not as important as the “should” features, so they may not make it into release 2, either.
- `W—Won’t`: These are completely optional features that the customers have agreed will not be included in the current release.

# Completeness and Pertinence
- `Completness problem:` when we dont have enough requirements to build the software / not realize the full purpose of the software
- `Pertinence problem:` when we have extra requirements that are not adding anything to the program and maybe even causing conflicts between the program making it impossible to develop

_Note that its also possible that we can have both problems at the same time_
![[Pasted image 20221228140848.png| 600]]



---
_Next:_ [[🟩3 @ Requirement Categories]]
_Previous:_ [[🟩1 @ Requirements Engineering]]

