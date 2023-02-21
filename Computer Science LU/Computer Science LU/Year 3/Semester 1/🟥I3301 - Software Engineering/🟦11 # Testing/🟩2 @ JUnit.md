_Previous [[🟩1 @ Testing]]_

---
JUnit is an open source framework that has been designed for the purpose of **writing and running tests in Java**.

JUnit runs a suite of tests and reports results. For each test in the test suite:
- JUnit calls `setUp()`:
  This method should create any objects you may need for testing. _(You can create objects in the testing functions, however this is used to create objects used in multiple test. It also acts like `Start()` in Unity)_
- JUnit calls `tearDown()`:
  This method should remove any objects you created. But it is not necessary since most of it is handled by the garbage collector.
- JUnit **calls once** the test method:
  You can create as many test methods as you want and test whatever you want in them. _(We will see later how to run a test method multiple times)_

# Coding Conventions for JUnit Class
- Name of the test class must end with `"Test"`.
- Name of the method must begin with `"test"`.
- Return type of a test method must be `void`.
- Test method must not throw any exception.
- Test method must not have any parameter.
- Test methods must be annotated by the `@Test` annotation

# Example
```java
public class StackTest(){
	@Test public void testEmpty(){
		Stack s = new Stack();
		assertTrue(s.empty());
		assertEquals(0, s.size());
	}
}
```

# Assertions
Assertions are the actual-ish test, they're like if statements but in form of functions. 
Failing an assertions functions means failing the test.
After failing the assertion, an `AssertionFailedError` exception is thrown which stops the execution of the test method.

_**Note:**_ The `() -> {}` is a lambda expression;

There are many assertion functions, but here are the essential ones:
- `assertTrue(condition)` check if the condition is true
- `assertEqual(expected, actual)` checks if _"expected"_ equals _"actual"_
- `assertNotNull(object)` i cant bother anymore.
- `assertThrowsExeption(ExceptionClass.class, function)` checks if the function throws an exception. 
  ```java
  assertThrows(AbcXyzException.class,
	  ()-> {
	  callMethodCausingAnExceptionWith(exceptionalVal);
  });
  ```
- `assertAll()` theres many of these, but they check a bunch of assertions together i guess
- `assertTimeout(ofSeconds(x), function)` For example:
  ```java
  assertTimeout(ofSeconds(5),
	  () -> {
	  // ... Code that may take so long
	  } , () -> "The above code took more than 5secs");
  ```
- `assertTimeoutPreemptively(ofSeconds(x), function)` For example:
  ```java
	assertTimeoutPreemptively(ofSeconds(5),
		() -> {
        // ... Code that may take so long
        }, () -> "The above code took more than 5secs & was aborted");
  ```

## `assertAll()`
![[Pasted image 20230221180635.png|700]]

_Example:_ 

![[Pasted image 20230221180740.png|700]]

# Repeating a Test
For this we use the annotation `@RepeatedTest(times)` instead of `@Test`
```java
@RepeatedTest(100)
public void testRepeat(){}
```

# Test Suites
Suites are groups of tests that can be run together
```java
import org.junit.runner.*;
import org.junit.runners.*;

@RunWith(Suite.class)
@Suite.SuiteClasses({
    <test class name>.class,
    <test class name>.class
})

public class <name> {}
```

# Tip
You can print out a message in the console before failing the test like so:
```java
try{
	assert();
} catch(AssertionFailedError e){
	System.out.println("Stoopid hooman, you broke your app!");
	throw e;
}
```

---
_Previous [[🟩1 @ Testing]]_