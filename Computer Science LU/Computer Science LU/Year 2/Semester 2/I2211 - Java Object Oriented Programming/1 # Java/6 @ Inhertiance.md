It is pretty much obvious. Say you have a `class X` and a `class Y`, if Y inherits from X, it means it copies all the variables and methods of class X, and you can work with them as you would with the class X.

To make a class inherit from another class we use the keyword `extend`
```java
public class X extends Y { /*...*/}
```

Class X is usually called: *super class* or *parent class*
Class Y is usually called: *subclass*

**What if we have constructors in the `super class`:**
In the `subclass` constructor, the first the constructor does is **call the empty constructor of the super class.** *(This is done behind the scene, and cant be done manually)* 
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