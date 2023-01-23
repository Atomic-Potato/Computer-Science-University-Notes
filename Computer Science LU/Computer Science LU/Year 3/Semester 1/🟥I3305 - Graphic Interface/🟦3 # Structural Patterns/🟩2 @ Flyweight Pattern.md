_Next [[🟩3 @ Bridge Pattern]]_
_Previous  [[🟩1 @ Structural Patterns]]_

---

`Flyweight` is a structural design pattern that lets you fit more objects into the available amount of RAM by **sharing common parts of state between multiple objects instead of keeping all of the data in each object.** It is used when you need to create a large number of similar objects. 

So to reduce memory usage you share Objects that are similar in some way rather than creating new ones.

_For example:_
Say you want to create 20 different circles with different colors and locations
![[Pasted image 20230122143403.png|200]]

# Problem
We are going to create a `Shape` interface and concrete class `Circle` implementing the Shape interface.
![[Pasted image 20230122154331.png|150]]

```java
public interface Shape {
	void draw();
}
```

```java
public class Circle implements Shape {
	private String color;
	private int x;
	private int y;
	private int radius;
	
	public Circle(String color){
		this.color = color;
	}
	public void setX(int x) {
		this.x = x;
	}
	public void setY(int y) {
		this.y = y;
	}
	public void setRadius(int radius) {
		this.radius = radius;
	}
	@Override
	public void draw() {
		System.out.println("Circle: Draw() [Color : " + color + ", x : " + x + 
							", y :" + y + ", radius :" + radius);
	}
}
```

Now we're gonna create a demo class to represent the problem of which we create 20 circles without conserving memory.
```java
public class Demo {
	private static final String colors[] = {"Red", "Green", "Blue", "Black",
											"White"};
	public static void main(String[] args) {
		for(int i=0; i < 20; ++i) {
			Circle circle = new Circle(color [(int(Math.random()*colors.length)]);
			circle.setX(Math.random()*100);
			circle.setY(Math.random()*100);
			circle.setRadius(Math.random()*100);
			circle.draw();
		}
	}
}
```

# Solution
Flyweight pattern tries to **reuse already existing similar kind objects** by storing them and creates new object when no matching object is found.

A `flyweight` is an object through which we try to minimize memory usage by sharing data as much as possible.

Two common terms are used here:
- `intrinsic state` : The constant data of an object, i.e. not public and can only be read _(color in this case)_
- `extrinsic state` : The data and variables that can be accessed and altered _(size and position in this case)_

The first category _(intrinsic)_ can be stored in the `flyweight` and is **shareable**. The other one depends on the `flyweight`’s context and is **non-shareable**.

## Example Solution

In the circles example, we have the color as an intrinsic state, while the other variables are extrinsic. So we can group the circles by colors
![[Pasted image 20230122155209.png|200]]

![[Pasted image 20230122155329.png |300]]

- `ShapeFactory` has a `HashMap` of `Circle` having key as color _(intrinsic state)_ of the `Circle` object.  Whenever a request comes to create a circle of particular color to `ShapeFactory`, it checks the circle object in its `HashMap`, **if object of Circle found, that object is returned otherwise a new object is created**, stored in `hashmap` for future use, and returned to client.
- `FlyWeightPatternDemo`, our execution class, will use `ShapeFactory` to get a `Shapeobject`. It will pass information _(red / green / blue/ white/ black)_ to `ShapeFactory` to get the circle of desired color it needs.

### Implementation
![[Pasted image 20230122160129.png|450]]
![[Pasted image 20230122160157.png||700]]

# Structure
![[Pasted image 20230122160233.png|700]]
- The `Flyweight Factory` manages a pool of existing flyweights. With the factory, client don’t create flyweights directly. Instead, they call the factory, passing it bits of e intrinsic state of the desired flyweight. **The factory looks over previously created flyweights and either returns an existing one that matches search criteria or creates a new one if nothing is found.**
- The `Flyweight` class contains the portion of the original object’s state that can be shared between multiple objects. The same flyweight object can be used in many different contexts. The state stored inside a flyweight is called intrinsic. The state passed to the flyweight’s methods is called extrinsic.

---
_Next [[🟩3 @ Bridge Pattern]]_
_Previous  [[🟩1 @ Structural Patterns]]_
