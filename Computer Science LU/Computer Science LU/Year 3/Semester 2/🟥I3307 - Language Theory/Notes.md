> When a state is circled twice it means it is the accepted state
> ![[Pasted image 20230630202539.png]]


> ![[Pasted image 20230630211003.png]]
> A* is the set of all possible combinations

> ![[Pasted image 20230630220740.png]]
> A DFA consists of a finite set of states, an input alphabet, a transition function, a start state, and a set of accepting states. The key characteristic of a DFA is that for every state in the machine and for every input symbol, there is exactly one transition defined. This means that the next state of the machine is uniquely determined by the current state and the input symbol. As a result, a DFA accepts or rejects an input string based on whether it reaches an accepting state or not after reading the entire input.
> ![[Pasted image 20230701135556.png]]


> ![[Pasted image 20230630220955.png]]
> ![[Pasted image 20230630221657.png]]
> NFA allows for multiple transitions from a given state on the same input symbol, and it can also have ε-transitions, which are transitions that don't consume any input. This non-determinism gives an NFA more flexibility in its behavior compared to a DFA. An NFA accepts an input string if there is at least one path from the start state to an accepting state that can be traversed by following the transitions and consuming the input symbols.
> ![[Pasted image 20230701135518.png]]
> Also remember that in a given word, at least one of the paths leads to the accepted state. What i mean is you have multiple choices of paths with a sequence, if theres a path using that sequence that leads to the accepted state then it is an accepted word.

> NFA to DFA
> ![[Pasted image 20230701142200.png]]
> We can simplify the result because as you can see theres no way we can reach F in the first place
> ![[Pasted image 20230701142407.png]]
> To do the simplification directly from the table, instead of just listing all the states and find their transitions, we just add new states when a transition leads to a new state
> ![[Pasted image 20230701142953.png]]


> The opposite of an automaton is basically setting as accepted state everything that was a normal state and setting accepted states as normal states

> Proving a language is regular
> ![[Pasted image 20230702102128.png]]

> If you truncate a language *(that is remove the last character from each word)*, then for the truncated language to be regular, all you have to do is set the accepted states to be the one before the last ones of the original language
> ![[Pasted image 20230702103732.png]]

> When we have an Epsilon as a transition input, it means that we are at both of the states at the same time.
> Now when converting from NFA to DFA, 
> say we are on q1 and we wanna see where input a takes us
> 1. q1 to q3
> 2. q1 to q2 (BUT a is not consumed yet, so we dont consider q2 yet)
> 3. now we can consume that a by going from q2 to q1, and so q2 is added to the list as well as q1
> And so we transition from q1 to q1q2q3 if input is a
> 
> Now say we are on q1 and we wanna see where input b takes us
> 1. q1 doesnt have any b input
> 2. We go through the epsilon to q2 but also q2 cant consume b
> So we cant go to anywhere from q1 with a b input
> ![[Pasted image 20230702131053.png]] 

> In regular expressions, the union can be expanded *(its reflexive or something, i cant remember what this was called)*
> ![[Pasted image 20230702172727.png]]
>Also
>![[Pasted image 20230702172956.png]]


> proving a language is regular using regular expressions to nfa
> ![[Pasted image 20230702204306.png]]


> ![[Pasted image 20230703212634.png]]

> A good rule in CFG is to work from outside in