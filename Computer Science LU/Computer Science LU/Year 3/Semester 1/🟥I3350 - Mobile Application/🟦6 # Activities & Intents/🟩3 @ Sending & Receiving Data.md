There are 2 types of sending data with intents:
- `data` which is a one piece of information whose data location can be represented by an URI
- `Extras` one or more pieces of information as a collection of key-value pairs in a `Bundle`

# Sending Information Functions
You can send `URI`s as an Intent data
```java
// A web page URL
intent.setData(Uri.parse("http://www.google.com"));
// a Sample file URI
intent.setData(Uri.fromFile(new File("/sdcard/sample.jpg")));
```

or other info as extras
```java
// putExtra(String name, int value)
intent.putExtra("level", 406);
// putExtra(String name, String[] value)
String[] foodList = {"Rice", "Beans", "Fruit"};
intent.putExtra("food", foodList);
// if theres lots of data, then send them as a bundle
putExtras(bundle)
```

# Receiving Information Functions
First we get the intent from the activity that sent it using the `getIntent()` function
```java
Intent intent = getIntent();
```

- To receive `URI`s use the `getData()` function
	```java
	 Uri locationUri = intent.getData();
	```
- To receive other information, use `getXExtras()` _(where X is the value type of the data)_
	```java
	// int getIntExtra (String name, int defaultValue)
	int level = intent.getIntExtra("level", 0);
	
	// dont include a value type for a bundle
	Bundle bundle = intent.getExtras();
	```

# Communication Between Activities
In the previous section, [[🟩3 @ Sending & Receiving Data#Receiving Information Functions|Receiving Information Functions]], we saw how to extract info from intents. But how do we get the intent in the first place? _\*Plays Vsauce music\* _