# Polymorphism
Polymorphism means "**many forms**", and it occurs when we have many classes that are related to each other by [[6 @ Inhertiance|inheritance]].

In practice:
- Since any class inherits from the `Object` class then we can create it using any class that inherits from it
	```java
	Object obj = new ClassName();
	//^                ^
	//Declared type    Actual Type
	```
- Same for functions where you can send in as parameter any class that inherits from that class
	```java
	void Function(Object obj){}
	
	String str = new String("Potato");
	Function(str);
	```

This can be useful in cases like filling an array with objects of different classes for example.

# Dynamic Binding
Consider the following:
```java
Object obj = new String("str");

long length = obj.lenght();                 //Compilation Error
							                //This happens because the compiler sees obj of class Object
											//And Object does not contain the function lenght();
							
long length2 = ((String)obj).length();      //Correct
											//Typecasting it to the actual type
										
long length3 = ((ArrayList)obj).lentg();    //Runtime Error
											//The compiler doesnt catch this error 
											//because it assumes ArrayList inherits from oBject
											//However when typecasting, it doesnt find it equal to the actual type 
											//and results in an erro
```
This is called `Dynamic Binding`

--- 
The `instanceof` operator in Java is **used to check whether an object is an instance of a particular class or not**. (Note that it returns true if its an instance of a class that inherits from another)