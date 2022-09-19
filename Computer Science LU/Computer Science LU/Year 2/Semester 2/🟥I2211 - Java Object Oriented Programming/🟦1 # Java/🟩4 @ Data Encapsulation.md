`Daya Encapsulation` is basically using only getters and setters to alter the values of the array, so we have control over the values that go in and out.

# Immutable Class
For a class to be immutable, it must satisfy the three properties:
- All variable data in the class **must be private**
- **No public** `set methods` for any data field
- Return a copy of the `non primitive` data types *(such as classes)* and **not the reference to the variable** *(This only applies to types that are mutable)*
*Example:*
```java
	public class Student
	{
		private int id; //Primitive type
		private String name; //Non primitive type + Immutable class
		private Date creationDate; //Non primitive type + Mutable class

		//Constructor
		public Student(int id, String name)
		{
			this.id = id;
			this.name = name;
			creationDate = new Date();
		}
		
		//Since String class is immutable
		//It creates a new string object containing the value of "name"
		//and returns the reference of this new object
		public String GetName() { return name }
		
		//Since Date calss is mutable
		//We had to manually create a new object 
		//and give it the value of the date in this object
		//and return the reference of the new object that was created
		public Date GetDate()
		{
			Date d = new Date(creationDate.getTime());
			return d;
		}
	}
```
**`NOTE:`** the `return` keyword returns a **copy** of primitive types, while for non primitive it returns **the reference** to the variable.