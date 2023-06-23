# ==GET THE CHATGPT THINGS==

- The sequence diagram is based on the class diagranm
- In the sequence diagram, for loops dont wait for asynchronous messages to be done, only synchronous because its waiting for a message to continue
- In generlization if i have a relation with the parrent and i want to specify the quantity of one of the children, then i the quantity next to the child in the generlization, not for the parrent (Check screenshots)
- If you want to translate DEPENDANCY into java, then you would say X depends on Y by meaning Y is passed as a function parameter in X
- In AGGREGATION when the parent is destroyed, then the children dont need to be destroyed, in code this means if the parent is destroyed, only the reference to that child is null
- In COMPOSITION destroying the parent, destroys the children. In code this means, the child object it self becomes null. (Relations with inner classes are ofcourse composition)
- The event statement gets executed before the exit statement, so first the condition and then you print To S3 and then you execute the Exit Statement
- The event statement gets executed before the exit statement, so first the condition and then you print To S3 and then you execute the Exit Statement
  ![[1..png]]
- ![[Screenshot 2023-03-14 164542.png]]
- ![[Screenshot 2023-03-14 173829.png]]
- Note that when you have a relation between 2 classes, then obviously you dont put them as attributes inside the classes
    ![[2.png]]


![[Pasted image 20230315202655.png]]

# Quest
![[Pasted image 20230315155710.png]]
![[Pasted image 20230315155742.png]]
![[Pasted image 20230315155802.png]]
![[Pasted image 20230315155834.png]]
![[Pasted image 20230315155851.png]]
![[Pasted image 20230315160019.png]]

- Actors are any entities that can interact with the system (not inner systems functionalities interacting with each other)
- You should put in use cases even they have a condition to exist
- secondary actor means this actor completes this use case. Which means not necessarily every to actors connected to the same use case need to be secondary (like one of them)
- We can have an **automated** external system interact with a use case by representing inside a square
  ![[Pasted image 20230315170613.png]]
- We can have multiple includes / extends from the same use case
- Its okay to add use cases not listed in the requirements if youre asked to **"PROPOSE"** the use case diagram. Otherwise if its **"translate"**, then you have to do it word for word ==(Professor didnt say the difference between these words, but im pretty positive this is the right decision. Plus he did modify the requirements when he was proposing a diagram so yee)==
- No link between an actor and an `extended` use case _(Unless the actor is an automated system or a secondary actor)_
- No link between an actor and an `including` use case _(Unless the actor is an automated system or a secondary actor)_
- Remember that there may be some bullshit that you dont need in your use case diagram
- Think of when you add a use case alone, like what will it do for the user? Is it actually a part of another use case that you have to include to? Or is it actually a result of another use case (in this case it is included in the DTD i think)? 
- Automated systems dont need to be secondary actors
- ![[Pasted image 20230315182029.png]] (The admin is not the developer) 
- Remember that a use case should not be a single button press
- Some bullshit in the question can help you in the DTD
- Postcondition is the result of the use case in a DTD
- Secondary actors can be also actors who are not connected to the main use case but connected to an "included" use case IN DTD
- Its preferred that you write optional things in the main scenario instead of making a branch for it 