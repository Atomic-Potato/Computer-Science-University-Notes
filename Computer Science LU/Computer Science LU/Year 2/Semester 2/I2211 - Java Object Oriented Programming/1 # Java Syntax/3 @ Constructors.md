Constructors allow us to call a function upon the creation of a new object of a specific class. A constructor can take parameters, execute other functions, etc. just like any other function.

# Declaration
A constructor has the same name of the class and doesnt take any return types, not even void, because if so it just becomes like any other function of the class.
```java
class Potato
{
	int variable;

	//An empty constructor is the default constructor
	//that is made even if you create other constructors
	Potato(){}

	Potato(int var1)
	{
		//instructions
	}

	//We can have different constructors,
	//but they need to have different parameter types 
	//or just a different parameter count
	Potato(boolean sexy, float potato)
	{
		//instructions
	}
}
```

# Calling constructors
Just like how you would create a `new` object of the class, but you just give it the arguments it demands, not necessary btw
```java
Potato newPotato = new Potato(true, 69.0);
```