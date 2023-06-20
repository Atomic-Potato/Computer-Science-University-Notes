
We have different types of file explorers in Android Studio. The most important 2 are the `Project` (which shows us how the files are stored on our computer) and `Android` (which shows us how our app files are stored on android)
![[Pasted image 20221222153003.png | 200]]

The `java files` **define the behavior of our app**
![[Pasted image 20221222153406.png | 1000]]

`Activity files` are files of type `xml` that **define the properties of the elements / views we see in the page**.
_(When you create a new page it creates a java and an activity file for it)_
![[Pasted image 20221222153529.png  | 1500]]

`Views` are the elements we currently see in our page (Currently the Hello World text and the button).
If we wanna add more views we can go to the `Design` tab and drag and drop the view onto the page (Make sure you have the XML script open)
![[Pasted image 20221222154648.png | 750]]
![[Pasted image 20221222154744.png | 900]]

You can customize your view attributes as well
![[Pasted image 20221222155049.png | 300]]
Once you get a new view inside the page, this view is translated with its attributes into XML tags (Go back to `Text` tab):
![[Pasted image 20221222154858.png]]
![[Pasted image 20221222154936.png]]
These tags act as objects of classes like in OOP languages. So we can make our own tags (classes) with our own attributes.

---

# Adding functionality with Java
The **`R`** keyword refers to the the `Resources` folders. With it we can find any view we want and store it in a variable.
So to get access into view we can use the `findViewById` function with the combination of the view ID using `R`:
```java
Button b = findViewById(R.id.points);
// Remember to press Alt+Enter to import the button library
```

We can now access all the attributes of that view. _For example:_
```java
String text = b.getText();
b.setText(text);
```

## Basic Methods
## `onCreate()` 
This function is called **once** when the page is opened. (Just like `Start()` or `Awake()` if you ever used Unity) 
It is written for us by default when we create a new java file:
```java
@Override  
protected void onCreate(Bundle savedInstanceState) {  
    super.onCreate(savedInstanceState);  
    setContentView(R.layout.activity_main);  
}
```
In this function we mostly set our variables (using `findViewById`) to be used later in other functions.

## `findViewById()`
Does what it says.
For example say we want access to our `Text View`
```java
TextView txt = findViewById(R.id.text_view_id);
```

The `R` stands for **Resources** folder

## Getting & Setting Text
We use the functions `textView.getText()` and `textView.setText(str)`. 
Just note that `getText()` returns the text as an array of characters, so you have to convert it into a string using `toString()`

```java
string str = textView.getText().toString();
```

# Listeners
Listeners basically subscribe to an event. When this event occurs, it sends a signal to all of its listeners. Now these listeners execute a function written by the programmer once the signal is received.

## `setOnClickListener`
This function **sets a listener for the button** using a new instance of `View.OnClickListener()` . And this listener triggers a function once the button is clicked during the execution of the program.

```java
button.setOnClickListener(new View.OnClickListener() {
	public void onClick(View v) {
		// Code here executes on main thread after user presses button
	}
});
```