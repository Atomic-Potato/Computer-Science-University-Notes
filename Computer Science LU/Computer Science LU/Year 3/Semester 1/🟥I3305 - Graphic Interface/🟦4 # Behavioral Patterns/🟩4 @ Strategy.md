_Next [[🟩5 @ Observer]]_
_Previous [[🟩3 @ Visitor]]_

---

`Strategy` is a behavioral design pattern that lets you **define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.**

# Problem
One day you decided to create a navigation app for casual travelers. The app was centered around a beautiful map which helped users quickly orient themselves in any city.

The first version of the app could only build the routes over roads. People who traveled by car were bursting with joy. But apparently, not everybody likes to drive on their vacation. So with the next update, you added an option to build walking routes. Right after that, you added another option to let people use public transport in their routes.

Each time you added a new routing algorithm, the main class of the navigator doubled in size. At some point, the beast became too hard to maintain.

# Solution
The Strategy pattern suggests that you take a class that does something specific in a lot of different ways and extract all of these algorithms into separate classes called strategies.

_How this solution applies on the previous problem:_
![[Pasted image 20230210160859.png|500]]

# Structure
![[Pasted image 20230210161005.png|500]]

The `Context` maintains a reference to one of the `concrete strategies` and communicates with this object only via the `strategy interface`.

`Concrete Strategies` implement different variations of an algorithm the context uses.

The `Client` creates a specific strategy object and passes it to the `context`. The `context` exposes a setter which lets clients replace the **_strategy_** associated with the context at runtime.

## Implementation
![[Pasted image 20230210161216.png|450]]
![[Pasted image 20230210161233.png|450]]
![[Pasted image 20230210161248.png|450]]

---
_Next [[🟩5 @ Observer]]_
_Previous [[🟩3 @ Visitor]]_