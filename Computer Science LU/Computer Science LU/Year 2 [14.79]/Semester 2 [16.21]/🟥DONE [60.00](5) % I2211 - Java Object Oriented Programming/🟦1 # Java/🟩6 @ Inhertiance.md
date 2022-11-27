# Inheritance

It is pretty much obvious. Say you have a `class X` and a `class Y`, if Y inherits from X, it means it copies all the variables and methods of class X, and you can work with them as you would with the class X.

To make a class inherit from another class we use the keyword `extend`
```java
public class X extends Y { /*...*/}
```

Class Y is usually called: *super class* or *parent class*
Class X is usually called: *subclass*

**What if we have constructors in the `super class`:**
In the `subclass` constructor, first the constructor **calls the empty constructor of the super class.** *(This is done behind the scene, and cant be done manually)* 
Unless we call the function `super(var1, var2);` which calls the constructor of the super class with relevant variables.

*Example:*
```java
public class Enemy 
{
    int health = 100;
    int speed = 10;
    
    Enemy(int health, int speed){
        this.health = health;
        this.speed = speed;
    }
    
    public void getSpeed() { return speed; }
    public void setSpeed(int speed) 
    {
	    this.speed = speed;
    }
}
```
```java 
public class Flyer extends Enemy
{
    int bulletCount = 1;
    boolean isFiring = false;
    
    public Flyer(int bulletCount, int health, int speed)
    {
        super(420, speed);
        this.bulletCount = bulletCount;
        this.speed = speed;
    }
    
    public void Nyoom(){
        speed = 999; // Notice how we didnt need to use the getter and setter of the Enemy class
    }
}
```

# `super` & `this`
The `this` keyword refers to the attributes and methods that are contained in the current instance of this class.
**This includes constructors**, so you can actually call the empty constructor for example like so:
```java
public class Flyer extends Enemy
{
	public void DoAFlip()
	{
		this(); //calls the constructor Flyer();
		Flip();
	}
}
```

Same thing for the `super` keyword, but instead it is for the attributes and methods of **the super class**

# Super class methods access
- If a super class method is **`private`** then it **cannot be accessed** by the subclass. However creating a new method with the same name in the subclass **will not  cause any ambiguity** in any of the classes.
- When creating a **`static`** method, we need to remember that this method now **belongs to the class** and that accessing the super class attributes and methods using `super` **is not an option** because this method now is specific to **only the subclass**

# Overriding & Overloading
- `@Override` : In any object-oriented programming language, Overriding is **a feature that allows a subclass or child class to provide a specific implementation of a method that is already provided by one of its super-classes or parent classes**. 
- `Overloading:` is when we create multiple methods with the **same name but  different arguments** like constructors for example.

# `Object` Super class
By default, every class created extends the `Object` class (directly) even if it extends to a new class, the new class will extend the object class, and even if the super class does, the same thing happens and so on (indirectly)

This class contains the following functions:
- `toString()` which converts the class into a string and returns it, which is not very useful and most times it is overridden.
- `clone()` which clones the class object and returns it. This method is `protected` and so it can only be accessed within the class and not through the class objects, a cheap way to avoid this is to create a method inside the class that returns the value of **clone();** 
	One other thing to note that when it clones non primitive variables, it clones the reference and not create a new object of that class, this is why it is mostly overridden.

# `protected`
The `protected` keyword means that the variable / method is **private** but accessible in the subclass