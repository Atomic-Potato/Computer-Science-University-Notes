_Next [[🟩4 @ Resources & Measurements]]_
_Previous [[🟩2 @ Layout Editor & Constraint Layout]]_

---

Events are something that happens
- In UI: Click, tap, drag
- Device: `DetectedActivity` such as walking, driving, tilting

A method, called an **event handler**, is triggered by a specific event and does something in response to the event

# Event Handler: 1st Method
Attach a function to the view triggering the event in XML and implement it in Java:

In XML add the attribute _(as an example for a button)_:
```c
android:onClick="showToast" // showToast is the name of the function in Java
```

Implement handler in Java activity: _(Note that the handler should be **public void** and takes as a parameter the view that calls it)_
```java
public void showToast(View view) {
	// Respond to event
}
```

# Event Handler: 2nd Method
In this method we get a reference to the button and set for it a **Listener** to that event.
```java
final Button button = (Button) findViewById(R.id.button_id);

button.setOnClickListener(new View.OnClickListener() {
	public void onClick(View v) {
		//Respond to event
	}
});
```
_Notice how we **implemented** the OnClickListener class inside the parameter_

---

_Next [[🟩4 @ Resources & Measurements]]_
_Previous [[🟩2 @ Layout Editor & Constraint Layout]]_