_Previous [[🟩3 @ Event Handling]]_

---

# Resources
Resources are separate static data from code in your layouts. Such as:  Strings, dimensions, images, menu text, colors, styles

They are stored in the `res` folder
![[Pasted image 20230107153003.png]]

## Accessing Resources
- `Layout:`
	```java
	// R.layout.activity_main
	setContentView(R.layout.activity_main);
	```
	_Reminder [[🟩1 @ Views#`setContentView()`|setContentView()]]_

- `View:`
	```java
	// R.id.recyclerview
	RecyclerView rv = (RecyclerView) findViewById(R.id.recyclerview);
	```
- `String:`
	In Java: **R.string.title**
	In XML: **android:text="@string/title"**

# Measurements
Its best to use these units when sizing your views and texts: 
- `Density-independent Pixels (dp):` for Views
- `Scale-independent Pixels (sp):` for text

**Avoid these units as much as possible:**
- Actual Pixels (px)
- Actual Measurement (in, mm)
- Points - typography 1/72 inch (pt)

--- 

_Previous [[🟩3 @ Event Handling]]_
