_Next:_ [[🟩2 @ Requirements]]

---

# What is `Requirements Engineering` (RE)
Process of establishing the **needs** of stakeholders that are to be solved by software
Requirements Engineering is important because the cost of correcting an error in the requirements depends on the number of subsequent decisions based on it.
The final result of RE is the `Software Requirements Specification (SRS)`^srs

We also are **not only** talking about:
- The requirements of the client, but also
- The constraints of the system under which the software operates 

Its also important to note that this process is interested in **WHAT?** the software will do, and not **HOW?** it will do it.


# Steps of RE
**Stakeholders (definition):** All of the people handling/using/included in the software ^stakeholders

- `Elicitation`:  collection of requirements from the stakeholders ^elicitation
- `Requirement  analysis`:  study and deeper understanding of the collected requirements
- `Specification`:  suitably represent and organize the requirements to be shared
- `Verification`: verify them (requirements are complete, consistent, not redundant…)
- `Management`: managing changes of requirements during the lifetime of the project
![[Pasted image 20221227162340.png]]

# Software Intensive System
**REMINDER. Definition of software:** set of complications that becomes concrete/useful only when we run it on some hardware and in the context of some human activity that it can support

`Software Intesive System` **= software + hardware + context/business**
_For example:  ATM functionality = Coding + ATM hardware + bank_

# Software Quality
The quality of a software doesnt depend only on how well it runs or the quality of the code, but 2 things:
- Good robust code
- Meets the customer needs _(What if the program is functional but doesnt do at all the the customers need?)_

# RE Hierarchy
`Business Requirements` (General Requirements) -> `User requirements` (Features) -> `System requirements` (Technical details)

![[Pasted image 20221227163642.png | 600]]

# The difficulty in defining the requirements
(Or identifying the purpose)

Theres many reasons why it is hard to do so:
- Sheer complexity of the purpose/requirements
- It's hard to extract what people want from you. _Theres a saying: "people don’t know what they want until you show it to them"_
- Customers demands/requirements keep changing
- Multiple [[🟩1 @ Requirements Engineering#^stakeholders|stakeholders]] with conflicting requirements

# RE Definition in Depth
RE is a  `set of activities` **(not a phase or a stage)** concerned with  `identifying and communicating` **(communication is as important as analysis)** the  `purpose` **(quality means fitness- - for- - purpose)** of a [[🟩1 @ Requirements Engineering#Software Intensive System|software intensive system]], and the `context` **(designers need to know how and where the system will be used)** in which it will be used. Hence, RE acts as the bridge between the `real world needs` **(requirements are partly about what is needed)** of users, customer, and other `constituencies` **(need to identify  all the stakeholders  not just the  users)** affected by a software system, and the `capabilities and opportunities` **(…and partly about what is possible)** afforded by software-intensive technologies.

---
_Next:_ [[🟩2 @ Requirements]]