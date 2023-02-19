This chapter is gonna be a little scattered since a lot of things are trivial and i kept only things that are worth highlighting.

---

# Tools
- `Source Code Control :` 
	It enables you to go back through past versions of the software and see exactly what changes were made and when.
	It prevents multiple programmers from tripping over each other as they try to modify the same code at the same time.
- `Profilers :`
	Let you determine what parts of the program use the most time, memory, files, or other resources.
- `Static Analysis Tools :`
  Static analysis tools study code without executing program _(how interconnected different pieces of code, how complex a piece of code is, average the number of lines of code per method, etc.)_.
- `Testing Tools :`
	Testing tools, particularly automated tools, can make testing a whole lot faster, easier, and more reliable.
- `Source Code Formatters :`
	Some development environments do a better job of formatting code than others.
	**It makes code easier to read and understand.**
- `Refactoring Tools :`
	Rearranging code to make it easier to understand, more maintainable, or generally better.
	Define new classes or methods, or extract a chunk of code into a new method _(existing code)_.

# Tips N' Trick
**I highly recommend that you watch Uncle Bob lectures on writing clean code**

## Komments
Many programmers write the bare minimum of comments because they think that writing lots of comments is a waste of time. 

Two bad ways of writing comments :
- `X` Write comments as you code.
- `X` Write all the code without comments. Then, write comments.

The real problem is that you’re trying to write comments to explain what the code **does** and not what it **should do**.

One way to write comments that explain what the program is supposed to be doing is to write the comments first.

**Remember, you might be debugging this code in a year or two.**

## Methods
- **Avoid Side Effects**
	A side effect is an unexpected result of a method call.
- **Validate Results** 
	Add validation code to your methods.
	It should examine the input data to make sure it’s correct, and it should verify that the result your code produces is right.
	The main tool for validating code is the **assertion**.

_(Assertion: In [computer programming](https://en.wikipedia.org/wiki/Computer_programming "Computer programming"), specifically when using the [imperative programming](https://en.wikipedia.org/wiki/Imperative_programming "Imperative programming") paradigm, an **assertion** is a predicate (a [Boolean-valued function] over the [state space](https://en.wikipedia.org/wiki/State_space "State space"), usually expressed as a [logical proposition](https://en.wikipedia.org/wiki/Logical_proposition "Logical proposition") using the variables of a program) connected to a point in the program, that always should evaluate to true at that point in code execution.)_

- **Practice Offensive Programming**
	- The idea behind **defensive programming** is to make code working no matter what kind of garbage is passed into it for data. The code should work and produce some kind of result no matter what.
	![[Pasted image 20230208192434.png|400]]
	- In **offensive programming** we force the code to run properly with proper conditions and not return back a result even if we get garbage input.
	  ![[Pasted image 20230208192639.png|400]]
	  The call to _Debug.Assert_ throws an exception if its  condition is false .
	  The _checked_ block throws an exception if the calculations cause integer overflow.
- **Use exceptions & write exception handlers first**
	To create better error handlers is to follow the same strategy you can use when writing comments and validation code: **Do it first.**
	When you start writing a method, paste in all the comments that you got from top‐down design, **add code to validate** the inputs and **verify the outputs**, and then **wrap error handling** code around the whole thing
- **Defer Optimization:**
	First make it work. Then make it faster if necessary.
