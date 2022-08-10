Quick video if its your first time: https://youtu.be/ceGnVDrMy1A

--- 

In Java, `exceptions` allows us to check for errors at the **compile time instead of runtime** and we can create custom exceptions making the code recovery and debugging easier.

# The `throw` keyword
```java
throw new exception_class("error message");
```
We specify the `exception` **object** which is to be thrown. The Exception has some message with it that provides the error description. These exceptions may be related to user inputs, server, etc.

We can throw either `checked` or `unchecked` exceptions in Java by `throw` keyword. It is mainly used to throw a **custom exception**.

We can also define our own set of **conditions and throw an exception** explicitly using `throw` keyword. For example, we can throw `ArithmeticException` if we divide a number by another number.
```java
if(x < 69)
	throw new ArithmeticException("No 69 for you!");
```

Just note that the **Instance must be of type `Throwable` or subclass of `Throwable`**. For example, **Exception is the sub class of Throwable** and the user-defined exceptions usually extend the Exception class.
![[Pasted image 20220810222034.png | 600]]

## Unchecked `throw`
```java
public class Unchecked
{
	public static void Validate(int potato)
	{
		if(potato < 420)
			throw new ArithmeticException("Not enough taters maan !");
		else
			System.out.println("Potato guud");
	}
	
	public static void main(String args[])
	{
		Validate(69);
		System.out.println("Rest of the code...");
	}
}
```
**Output:**
![[Pasted image 20220810222837.png | 600]]
If we throw a checked exception using throw keyword, **it is must to handle the exception** using `catch` block or the method must declare it using throws declaration.

## Checked `throw`
```java
public class TestThrow2 
{   

	//function to check if person is eligible to vote or not   
	public static void method() throws FileNotFoundException //we can have multiple exception types here, seperated by a comma
	{  
		//This function decleration suggests that a FileNotFoundException might occcur in this function
		
		FileReader file = new FileReader("C:\\Users\\Anurati\\Desktop\\abc.txt");  
		BufferedReader fileInput = new BufferedReader(file);  

	    throw new FileNotFoundException();  

    }  
    //main method  
    public static void main(String args[])
    {  
	    try  
		{  
	        method();  
        }   
        catch (FileNotFoundException e)   
        {  
	        e.printStackTrace();  
        }  
		System.out.println("rest of the code...");    
    }    
}
```
**Output**
![[Pasted image 20220810223325.png | 600]]

## Throwing user defined exceptions
exception is everything else under the `Throwable` class.
```java
// class represents user-defined exception
class UserDefinedException extends Exception
{
	public UserDefinedException(String str)
	{
		// Calling constructor of parent Exception
		super(str);
	}
}
```

---
### Extra
```java
catch(Exception ex)
{
	ex.getMessage(); //gets the message from the exception object
}
```