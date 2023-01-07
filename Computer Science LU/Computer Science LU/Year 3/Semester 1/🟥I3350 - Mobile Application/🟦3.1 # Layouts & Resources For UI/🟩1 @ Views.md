_Next [[🟩2 @ Layout Editor & Constraint Layout]]_

---

If you look at your mobile device, every user interface element that you see is a `View`.
Views are defined in `XML`

View subclasses are basic user interface building blocks, like:
- Display text _(TextView class)_, edit text _(EditText class)_
- Buttons _(Button class)_, menus, other controls
- Scrollable _(ScrollView, RecyclerView)_
- Show images _(ImageView)_
- Group views _(ConstraintLayout and LinearLayout)_

# Creating a View in Java code
```java
TextView myText = new TextView(this); //The parameter is the context
myText.setText("Display this text!");
```

## What is the Context
`Context` is an interface to global information about an application environment.

And an Activity is its own context:
```java
TextView myText = new TextView(this);
```

To get the application context
```java
Context context = getApplicationContext();
```

# ViewGroup
As the name suggests, its a group of views.

Some of these view groups are:
- `ConstraintLayout:` Positions UI elements using constraint connections to other elements and to the layout edges
- `ScrollView:` Contains one element and enables scrolling
- `RecyclerView:` Contains a list of elements and enables scrolling by adding and removing elements dynamically

## Layouts
Layouts are specific types of `ViewGroups` _(subclasses of ViewGroup)_. They contain child views and can be in a row, column, grid, table or absolute.

The common layout classes:
- `LinearLayout:` Horizontal or vertical row
	![[Pasted image 20230107142142.png|100]]
- `ConstraintLayout:` _(Default)_ Connect views with constraints
	![[Pasted image 20230107142229.png|100]]
- `GridLayout:`
	![[Pasted image 20230107142307.png|100]]
- `TableLayout:` Same as `GridLayout` but the rows and columns can spawn over multiple cells
	![[Pasted image 20230107142434.png|100]]
- `RelativeLayout:` Child views relative to each other
-  `FrameLayout:` Shows one child of a stack of children _(I think its like when you swipe left or right between tabs)_

# Class hierarchy vs. layout hierarchy
- View class-hierarchy is standard object-oriented class inheritance
	For example, _Button_ is-a _TextView_ is-a _View_ is-an _Object_. Superclass-subclass relationship
- Layout hierarchy is how views are visually arranged
	For example, _LinearLayout_ can contain _Buttons_ arranged in a row. Parent-child relationship

# Hierarchy of ViewGroups and views
![[Pasted image 20230107143142.png | 600]]

# Layout Implementation
![[Pasted image 20230107143348.png | 400]]

## This layout in XML 
```xml
<LinearLayout
	android:orientation="vertical"
	android:layout_width="match_parent"
	android:layout_height="match_parent">
		<Button
		... />
		<TextView
		... />
		<Button
		... />
</LinearLayout>
```

## This layout in Java
```java
LinearLayout linearL = new LinearLayout(this);
linearL.setOrientation(LinearLayout.VERTICAL);

TextView myText = new TextView(this);
myText.setText("Display this text!");

linearL.addView(myText);
setContentView(linearL); //Explained down below
```

To set width and height in Java code
```java
LinearLayout.LayoutParams layoutParams = new Linear.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_CONTENT);
myView.setLayoutParams(layoutParams);
```

### `setContentView()`
In Android the visual design is stored in XML files and each [Activity](https://developer.android.com/guide/components/activities/intro-activities) is associated to a design.
```scss
setContentView(R.layout.main)
```
`R` means Resource
`layout` means design
`main` is the xml you have created under `res->layout->main.xml`

Whenever you want to change the current look of an Activity or when you move from one Activity to another, the new Activity must have a design to show. We call [`setContentView`](https://developer.android.com/reference/android/app/Activity.html#setContentView(int)) in `onCreate()` with the desired design as argument.

# Best practices for view hierarchies
Arrangement of view hierarchy affects app performance. So use smallest number of simplest views possible and keep the hierarchy flat-limit nesting of views and view groups

---

_Next [[🟩2 @ Layout Editor & Constraint Layout]]_
