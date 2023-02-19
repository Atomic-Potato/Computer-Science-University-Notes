This chapter is gonna be a little scattered since a lot of things are trivial and i kept only things that are worth highlighting.

---
# Which bugs to fix
Use a simple cost/benefit analysis to prioritize them. evaluate the following factors:
- `Severity :` How painful is the bug for the users? How much work, time, money, or other resources are lost?
- `Work-arounds :` Are there work-arounds?
- `Frequency :` How often does the bug occur?
- `Difficulty :` How hard would it be to fix the bug? _(Of course, this is just a guess.)_
- `Riskiness :` How risky would it be to fix the bug? If the bug is in particularly complex code, fixing it may introduce new bugs.

# Levels of Testing
There are several levels of testing:

## Unit Testing
A unit test verifies the correctness of a specific piece of code.
Usually unit tests **apply to methods**. You write a method and then test it.

Write method’s unit tests before you write the method.
Save the test code for later use.

## Integration & Regression Testing
After unit testing, it’s time to integrate it into the existing codebase.

An integration test verifies that the **new method works and plays well with others**.
It checks that existing code calls the new method correctly, and that the new method can call other methods correctly.
Verify that the new code didn’t mess up anything that seems unrelated.

In regression testing, you test the program’s entire functionality to see if anything changed when you added new code to the project.

## Automated Testing
Automated testing tools let you define tests and the results they should produce.
A good testing tool should let you schedule tests.

## Component Interface Testing
It studies the interactions between components.

Strategy :
- think of the interactions between components as one component sending a message _(a request or a response)_ to another.
- make each component record its interactions _(plus a timestamp)_ in a file.

To test the component interfaces, you exercise the system and then review the timeline of recorded events to see if everything makes sense.

## System Testing
An end‐to‐end run-through of the whole system.

Ideally, a system test exercises every part of the system to discover as many bugs as possible.

An in-depth system test may need to explore many possible paths of interaction with the application.

Unfortunately, even simple programs usually contain a practically unlimited number of possible paths of interaction.

## Acceptance Testing
Determine whether the finished application meets the customers’ requirements.

Normally, a user or other customer representative sits down with the application and runs through all the user cases you identified during the requirements gathering phase to make sure everything works as advertised.

Customers may decide that their interpretation of a use case is different from yours.

Or they may decide that what they need is different from what they thought they needed during requirements gathering.

## Other Testing Categories
`Accessibility test` —Tests the application for accessibility by those with visual, hearing, or other impairments.

`Alpha test` —First round testing by selected customers or independent testers. Alpha tests usually uncover lots of bugs and defects, so they generally aren’t open to a huge number of users because that might ruin your reputation for building good software.

`Beta test` —Second round testing after alpha test. Generally, you shouldn’t give users beta versions until the application is quite solid or you might damage your reputation for building good software.

`Compatibility test` —Focuses on compatibility with different environments such as computers running older operating system versions. Also checks compatibility with older versions of the application’s files, databases, and other saved data.

`Destructive test` —Makes the application fail so that you can study its behavior when the worst happens. You won’t actually destroy the code. You’ll destroy the application’s performance.

`Functional test` —Deals with features the application provides. These are generally listed in the requirements.

`Installation test` —Makes sure you can successfully install the system on a fresh computer.

`Internationalization test` —Tests the application on computers localized for different parts of the world. This should be carried out by people who are natives of the locales.

`Nonfunctional test` —Studies application characteristics that aren’t related to specific functions the users will perform. For example, these tests might check performance under a heavy user load, with limited memory, or with missing network connections. These often identify minimal requirements.

`Performance test` —Studies the application’s performance under various conditions such as normal usage, heavy user load, limited resources (such as disk space), and time of day. Records metrics such as the number of records processed per hour under different conditions.

`Security test` —Studies the application’s security. This includes security of the login process, communications, and data.

`Usability test` —Determines whether the user interface is intuitive and easy to use.

# Testing Techniques 

## Exhaustive Testing
In some cases, you may be able to test a method with every possible input.

Unfortunately, most methods take too many combinations of input parameters for you to exhaustively try them all.

## Black-Box Testing
You pretend the method is a black box that you can’t peek inside.

You know what it is supposed to do, but you have no idea how it works. You then throw all sorts of inputs at the method to see what it does.

You can start black‐box testing by sending it a bunch of random inputs. so you can test a lot of random values.

If a method takes a variable number of inputs, make sure it can handle 0 inputs and a really large number of inputs.

If it takes an array or list as a parameter, see what it does if the array or list is empty or missing.

Finally, look at boundary values. If a method expects a floating point parameter between 0.0 and 1.0, make sure it can handle those two values.

## White-Box Testing
You get to know how the method does its work.

You then use your extra knowledge to design tests to try to make the method crash and burn.

You can try to pick particularly difficult test cases.

The disadvantage that you know how the method works, so you might skip some test cases that you assume work.

## Gray-Box Testing
Combination of white‐box and black‐box testing.

Here you know some but not all the internals of the method you are testing.
For instance it contains sorting of an array

# Testing Habits
Test Your Own Code
Test and Debug When Alert
Have Someone Else Test Your Code
Fix Your Own Bugs
Don’t Believe in Magic
See What Changed
Fix Bugs, Not Symptoms
Test Your Tests

# How to fix a bug
Ask yourself how you could prevent a similar bug in the future.
- What techniques could you use in your code?
- What tests could you run to detect the bug sooner?

Ask yourself if a similar bug could be lurking somewhere else.
- If other pieces of code contain a similar problem, it will be easier if you find them now instead of waiting for them to break something else.

Look for bugs hidden behind this one.

Examine the code’s method and look for other possibly unrelated bugs.

Make sure your fix doesn’t introduce a new bug.
- The chances of a line of modified code containing a bug are much higher than those for an original line of code.