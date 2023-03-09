Obviously a list is an ordered collection of selectable choices. 
![[Pasted image 20230308082917.png]]

The key attributes of a list in XML:
![[Pasted image 20230308082952.png|600]]

# Static Lists
Static lists, as the name suggests, are content fixed and known before the app runs.

You have to declare the list elements in the `strings.xml` resource file.
```xml
<resources>
	<string-array name = "operating systems">
		<item>Android</item>
		<item>IOS</item>
		...
	</string-array>
</resources>
```

Adding the elements to your static list:
```xml
<ListView 
	... 
	android:id="@+id/mylist" 
	android:entries="@array/operating systems"/>
```

# Dynamic Lists
Dynamic lists, as the name suggests, content is read or generated as the program runs. _(Comes from a data file, or from the internet, etc.)_

**The new elements must be set in the Java code.**

# List Adapters
_Reminder: [[🟩2 @ Spinners#^adapter|Adapters]]_ 
You can use those as like in [[🟩2 @ Spinners]]. Just remember to use the `android.R.layout.simple_list_item_1` instead of the spinner layout.

_For example:_
```java
ArrayList<String> myArray = ...;

ArrayAdapter<String> adapter = new ArrayAdapter<String>(
	this, android.R.layout.simple_list_item_1, myArray);

ListView list = (ListView)findViewById(R.id.mylist);
list.setAdapter(myAdapter);
```

# Lists Events
**Lists dont use `onClick` event**. The event listeners must be attached in the Java code, not in the XML.
For this we need to use Java **anonymous inner classes.** 

## Anonymous Inner Class
Basically they are a shorthand syntax for declaring a small class without giving it an explicit name.

Typically the class is declared and a single of it is constructed and used all at once.

We will see an example in the following heading.

## Attaching an event listener to an object
```java
Button button = ...;
button.setOnClickListener(new View.OnClickListener(){
	public void onClick(View v){
		// do ur thing
	}
})
```

## List Events
There are many list events, but we'll just cover the main ones:
- `setOnItemClickListener(AdapterView.OnItemClickListener):` Listener for when an item in the list has been clicked.
- `setOnItemLongClickListener(AdapterView.OnItemLongClickListener):` Listener for when an item in the list has been clicked and held.
- `setOnItemSelectedListener(AdapterView.OnItemSelectedListener):`  Listener for when an item in the list has been selected _(more like highlighted if that helps)_.

_For example:_
![[Pasted image 20230308091200.png|700]]

# Custom List Layouts
To make a custom list:
1. Write a short layout XML file describing the layout for each row.
2. Write a subclass of `ArrayAdapter` that overrides `getView()` to describe what view must be returned for each row.