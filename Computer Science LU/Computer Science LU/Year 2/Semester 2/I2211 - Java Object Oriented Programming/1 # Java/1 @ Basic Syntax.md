```java
import java.util.Scanner

public class ClassName
{
	//ARRAYS

	//same syntax for an array of a class
	int[] array = new int[69];
	//or
	int[] arr = {1, 2, 3};
	//When declaring an array of classes, you dont put a copy of the object inside the array, 
	//you put a reference to that object. 
	//(Pretty much the same in normal arrays 
	//when you think of the pointer notation of an array)


	//CODE EXECUTION
	
	//Equivalent for main function, used for testing the class
	public static void main(String[] agrs)
	{
		//Ouput
		System.out.println("I love phat potatoes");
		//Input
		Scanner input = new Scanner(System.in /*read from the keyboard*/)
		int a = input.nextInt();
		double b = input.nextDouble();
	}
}
```

- The `new` keyword is like the `malloc()` but we dont really have to do all of that stuff for malloc. So you can conclude that a lot of things in java variables are pointers.

![[Pasted image 20220520163940.png | 800]]

# The `static` keyword
- The `static` keyword in `function` declaration means this function can be accessed using the **class name** instead of having to use it with a variable from that class
- The `static` keyword in `variable` declaration means every object that belongs to this class has this variable in common. So if *object1* changes it, it changes for all the other objects. Also you can access this value directly from the class.
`Just note that you can use the "const" keyword to make it public but without the ability for it to be changed by any object.`


# Functions
```java
public int function(Class var){return 0;}
```

Just want to point out that when you pass in a variable you are passing a **copy not the reference**
And if this function is contained in class **X** and the parameter is of type **X** then you can access the private variables of this **copy** and modify them.