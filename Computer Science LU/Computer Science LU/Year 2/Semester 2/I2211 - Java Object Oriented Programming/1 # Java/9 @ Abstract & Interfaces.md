# `abstract`
- In `classes:` an abstract class is a restricted class that cannot be used to create objects **(to access it, it must be inherited from another class).**
- In `methods:` an abstract method can only be used in an abstract class, and it does not have a body. The body is provided by the subclass (inherited from).
	```java
	abstract void Function()
	{
		//Function body
	}
	```

# Interface
An interface is basically a blueprint of a class that tell the class that `implements` it what can it do and what it cannot do.
It is also a way to allow multiple inheritances.

There can be only **abstract** methods in the Java `interface`, **not the method body.** 

**Why do we use an Interface?**
The reason is, `abstract` classes may contain **non-final variables**, whereas variables in the interface are `final`, `public` and `static`.

*Example:*
```java
// Java program to demonstrate working of
// interface

import java.io.*;

// A simple interface
interface In1 {
	
	// public, static and final
	final int a = 10;

	// public and abstract
	void display();
}

// A class that implements the interface.
class TestClass implements In1 {
	
	// Implementing the capabilities of
	// interface.
	public void display(){
	System.out.println("Geek");
	}

	// Driver Code
	public static void main(String[] args)
	{
		TestClass t = new TestClass();
		t.display();
		System.out.println(a);
	}
}
```

Just note that implementing `interfaces` is like `inheritance`
So we can for example put inside an interface pointer, a class that implements it
```java
public interface Drawable{}
public class Circle implements Drawable{}

Drawable d = new Circle();
```

---
## Comparable Interface
Java `Comparable interface` is used to order the objects of the user-defined class. This interface is found in java.lang package and **contains only one method named `compareTo(Object)`.**
We usually `override` this method.

To make a class comparable we do:
```java
public class ClassName implements Comparable<ClassName>
{
	//usual class stuff
	@Override
	public int compareTo(ClassaName cn)
	{
		//compare
		//usually we reduct the caller from the parameter
		return this - cn;
	}	
}
```