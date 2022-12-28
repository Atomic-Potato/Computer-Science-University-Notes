This process is time consuming but worth it.

## What is Requirements Gathering?
- Figuring out the requirements & whether it is feasible to implement
- You need to find out:
	- what the customers **wants** and what the customers **needs**
	- also the non-functional requirements (like speed)
- Who is the customer? 
	Could be your company, as in your own software idea. And sometimes it can be unclear whos the targeted audience/customer is 

## Requirements documents 
After determining the customer’s want and needs, you can turn them into a **`requirements documents`** :
- tell the customers what they will be getting
- tell the project members (designers, developers, testers) what they will be building

These can be used as a reference to see if the project is heading in the right direction.

---
# High-Level Design
The `high-level design` include things such as decisions about:
- what platform to use (desktop, laptop…)
- what data design to use (direct access, 2-tier, or 3-tier)
- interfaces/end-points with other systems (external purchasing systems)
	(Interfaces is here meant as how different systems communicate with eachother, like a bank account with a bank mobile application)

The high-level design should also include information about the project architecture at a relatively high level (UML Diagram). And it should cover every aspect of the requirements

---

# Low-Level Design
- Assign high-level design pieces to groups within the project so that they can work on low-level designs
- The low-level design includes information about how that piece of the project should work
- The design needs to give every last detail necessary to implement the project pieces
	They should give enough guidance to the developers who will implement those pieces

---

# Development
- The programmers continue refining the low-level design until they know how to implement those design in code
- As the programmers write the code, they test it (`Unit Testing`) to find and remove as many bugs as they reasonably can

---

# Testing
Effectively testing your own code is extremely hard. And even if the code is tested theres no guarantee it will work with other parts of the system.

So developers test their own code. Then testers who didn’t write the code test it (its always better for someone else to test others code).
After that the code s integrated into the rest of the project, and the whole thing is tested to see if the new code broke anything.

And its **IMPORTANT** that if you detect an error in previous phases, it should be fixed right away. Since the more an error goes down in phases, the harder it will be to fix. So if we're in the `Development` stage and error is found in the `Requirements Gathering Docs` then it will be really hard to fix this issue since there could be many systems that are built around that error.
![[Pasted image 20221208181112.png | 300]]

---

# Deployment
Deployment might involve any or all of the following:
- New computers for the back-end database
- A new network
- New computers for the users
- User training
- On-site support while the users get to know the new system
- Parallel operations: while some users get to know the new system and other users keep using the old system
- Special data maintenance tasks to keep the old and new databases synchronized
- Massive bug fixing when the 250 users discover dozens or hundreds of bugs that testing didn’t uncover
- Other nonsense that no one could possibly predict

For example suppose you’ve written a new billing system to track payments from your company’s millions of customer accounts. And now you have to migrate these accounts to the new system.

The main step is to persuade users to adapt to this new software

--- 

# Maintenance
As soon as the users start pounding away on your software, they’ll find bugs that you have to fix.
And If your application is successful, users may come up with enhancements, improvements, and new features that they want added immediately.

---

# Wrap-up
- You need to evaluate the project and decide what went right and what went wrong
- You need to figure out how to make the things that went well occur more often in the future
- You need to determine how to prevent the things that went badly in the future