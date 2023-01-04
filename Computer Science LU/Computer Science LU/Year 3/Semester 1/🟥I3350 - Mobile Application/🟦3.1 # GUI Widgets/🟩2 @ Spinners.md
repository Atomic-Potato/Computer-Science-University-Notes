_Previous [[🟩1 @ Common Widgets]]_

---

A spinner is a drop-down menu of selectable choices
![[Pasted image 20230104133702.png|100]]

Key attributes: _Reminder [[🟧Unorganized Notes#strings.xml|strings.xml]]_
```java
android:clickable="bool"       // set to false to disable the spinner
android:entries="@array/array" // set of options to appear in spinner
		                       // (must match an array in strings.xml)
android:prompt="@string/text"  // title text when dialog of choices pops up
```

Represented by `Spinner` class in Java code.
Use the `setOnItemSelectedListener` method to do what it says (explained in [[🟩2 @ Spinners#Spinner Event|Spinner Event]]).

# Transferring the xml array data to the java array
We do this using an `ArrayAdapter`. 

`Adapters` are use whenever we want to bind some data which we get from any data source _(e.g. ArrayList, HashMap, SQLite, etc.)_ with a UI component _(e.g. ListView, GridView, etc.)_ then Adapter comes into the picture. Basically Adapter **acts as a bridge between the UI component and data sources** ^adapter

`ArrayAdapter` is the most commonly used adapter in android. When you have a list of **single type items** which are stored in an array you can use `ArrayAdapter`.

```java
Spinner spinner = (Spinner) findViewById(R.id.spinner);

// Create an ArrayAdapter using the string array and a default spinner layout
ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.array_name, android.R.layout.simple_spinner_item); 

// Specify the layout to use when the list of choices appears
adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item); 

// Apply the adapter to the spinner
spinner.setAdapter(adapter);
```

You can skip most of the adapter creation by just creating a new adapter object, **if you have an array in the code**
```java
spinner.setAdapter(new AdapterArray<>(this, R.layout.support_simple_spinner_dropdown_item, array_name));
```

Or you can just do this heh:
```java
spinner.setAdapter(new ArrayAdapter<>(this, R.layout.support_simple_spinner_dropdown_item, getResources().getStringArray(R.array.array_name)));
```

# Spinner Event
Now i dont get this quite yet, but ill fix it once i do.

So **i think** if we want to add custom spinner events we use the function `setOnItemSelectedListener()` that creates a new event listener for the spinner. 
And as parameters we give it a new instance of `AdapterView.OnItemSelecedListener()` and we implement this function with the following functions/events to be triggered when the even listener gets a signal.
```java
public void onItemSelected(AdepterView<?> parent, View view, int pos, long id){
	// An item was selected. You can retrieve the se/ected item using 
	parent.getItemAtPosition(pos)
}

public void onNothingSelected(AdapterView<?> parent){
	// Another interface callback
}
```


Things to note:
- _`AdapterView.OnItemSelecedListener` is called an  **inner class** (since it is a class inside a class)_
- Remember to `@Override` the parameter functions.

```java
public class MainActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		Spinner spin = (Spinner) findViewById(R.id.tmnt);
		
		spin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener()
		{
			@Override
			public void onItemSelected(AdapterView<?> spin, View v, int i, long id)
			{
				TextView result = (TextView) findViewById(R.id.turtle_result);
				result.setText("You chose " + spin.getSelectedItem());
			}
			
			@Override
			public void onNothingSelected(AdapterView<?> parent)
			{
				// empty
			} 
		});
	}
}
```

## Alternative Way
We can make the activity class implement `AdapterView.OnItemSelectedListener`, so we dont have to write the selection functions inside the `AdapterView.OnItemSelectedListener()`
```java 
public class MainActivity extends Activity implements AdapterView.OnItemSelectedListener{
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		//...
		spin.setOnItemSelectedListener(this);
	}
	@Override
	public void onItemSelected(AdapterView<?> spin, View v, int i, long id){
		// do your thing
	}
	@Override
	public void onNothingSelected(AdapterView<?> parent){
		// do your thing
	} 
}
```

You can also do this on a separate class, where you make it `extends Activity implements AdapterView.OnItemSelectedListener` and write the `onItemSelected()` and `onNothingSelected()` functions, then create a new an instance of this of this class and set as the parameter of the function `setOnItemSelectedListener()`.
```java
public class SpinnerActivity extends activity implements OnItemSelectedListener{
	public void onItemSelected(AdepterView<?> parent, View view, int pos, long id){}
	public void onNothingSelected(AdapterView<?> parent){}
}

public class MainActivity extends Activity implements AdapterView.OnItemSelectedListener{
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		//...
		SpinnerActivity act = new SpinnerActivity();
		spin.setOnItemSelectedListener(act);
	}
```

This, as you have probably figured, helps us use these functions in other spinners as well.

# `ArrayAdapter` Flex~~tape~~bility
ArrayAdapters make it easier to switch the values in a spinner.

For example: I have 2 languages for the drop-down menu → I need 2 arrays → if the user changes the language, I change the array by changing the ArrayAdapter set to the spinner.

---
_Previous [[🟩1 @ Common Widgets]]_