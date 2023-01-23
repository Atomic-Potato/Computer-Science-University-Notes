_Previous [[🟩3 @ Builder Pattern]]_

---

`Singleton` is a creational design pattern that lets you ensure that a class has **only one instance**, while providing a global access point to this instance.

# Problem
In the context of a dynamic web application, the connection to the database server is unique.  Imagine that you’re creating a class that manages the database connection, the implementation of this class should allow clients to access e same instance of the database connection throughout the program.

# Solution
All implementations of the Singleton have these two steps in common:
1. **Make the default constructor private**, to prevent other objects from using the new operator with the Singleton class.
2. **Create a static creation method that acts as a constructor**. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object.

# Structure
- Class diagram:
	![[Pasted image 20230122132849.png|350]]

# Example
```java
public class Database{
	private static Database DatabaseInstance;
	
	private DataBase(){
		// Initialization code
	}
	
	public static Database getInstance(){
		if(DatabaseInstance == null)
			DatabaseInstance = new Database();
	}
	
	// Any singleton should define some business logic
	// which can be executed on its instance
	public void query(String sql){
		//...
	}
}
```

---

_Previous [[🟩3 @ Builder Pattern]]_
