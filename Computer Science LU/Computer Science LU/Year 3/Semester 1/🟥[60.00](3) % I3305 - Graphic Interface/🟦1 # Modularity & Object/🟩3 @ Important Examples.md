_Previous:_ [[🟩2 @ Object]] 

---

**_Reminder:_**
![[Pasted image 20221208152452.png |400]]
_\* in java_

---

# Coordinate System
There are 2 types of coordinate systems, `Cartesian` $\large (x.y)$ and `Polar` $(r,\theta)$ (which means distance and angle from the origin).

Lets make a `Point` class based on the **Cartesian** system
```java
class Point{
	double x;
	double y;
	
	double rho(){
		return Math.sqrt(x*x + y*y);
	}
	double theta(){
		return Math.atan2(y,x);
	}
}
```

Our Point class example goes against the rules and principles of modular architecture
- No uniform access
	- attributes via `p.x` and `p.y`
	- access to methods via `p.rho()` and `p.theta()`
- No information hiding
	attributes and methods accessible by the main program

_(Same goes if we implemented the class using the **Polar** system)_

## Solution
What we want is to make a point class without letting the user know which kind of system we used. We thus hide the implementation choices:
```java
class Point { 
	private double rho
	private double theta; 
	
	double x(){
		return rho.Math.cos(theta);
	} 
	double y(){
		return rho*Math.sin(theta);
	} 
	
	void setX(double x){
		double y = y();
		rho = Math.sqrt(x*x+y*y); 
		theta = Math.atan2(y, x);
	}
	void setY(double y){
		double x = x(); 
		rho = Math.sqrt(x*x+ry); 
		theta = Math.atan2(y, x);
	} 
 
	double rho() {return rho;}
	double theta() {return theta;} 
	 
	void setRho(double r) {rho = r;} 
	void setTheta(double t) {theta = t;} 
} 
```

This way in the main program we can access the values just using the methods
