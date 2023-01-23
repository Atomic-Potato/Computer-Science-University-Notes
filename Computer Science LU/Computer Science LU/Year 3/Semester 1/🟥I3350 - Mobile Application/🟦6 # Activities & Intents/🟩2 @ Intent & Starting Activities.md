An Intent is a description of an operation to be performed. It is an object used to request an action from another app component via the Android system.

In other words it is used to launch other activities and carry information between them.
![[Pasted image 20230111145514.png|300]]

Intents can:
- `Start an Activity:` _A button click starts a new Activity for text entry_
- `Start an Service:` _Initiate downloading a file in the background_
- `Deliver Broadcast:` _The system informs everybody that the phone is now charging_

# Explicit & Implicit Intents
- An `explicit` intent starts a specific Activity:
	![[Pasted image 20230111150958.png|500]]
- An `implicit` activity asks the system to find an Activity that can handle this request:
	_Like find an open store that sells green tea or clicking Share opens a chooser with a list of apps_

# Starting Activities
To start a specific Activity , use an **explicit Intent**
```java
Intent intent = new Intent(this, ActivityName.class); // "this" is the context of the current activity
// start the activity by sending out the intent
startActivity(intent);
```

To ask Android to find an Activity to handle your request, use an **implicit Intent**
```java
Intent intent = new Intent(action, uri); // An action can be like the share activity,
										 // the dial pad, or anything that is in built in the system 
// start the activity by sending out the intent
startActivity(intent);
```
_For example_
- _Show a web page:_
	```java
	Uri uri = Uri.parse("http://www.google.com");
	Intent it = new Intent(Intent.ACTION_VIEW,uri);
	startActivity(it);
	```
- _Dial a phone number:_
	```java
	Uri uri = Uri.parse("tel:8005551234");
	Intent it = new Intent(Intent.ACTION_DIAL, uri);
	startActivity(it);
	```

# How Activities Run
All Activity instances are managed by the Android runtime. Started by an _"Intent"_, a message to the Android runtime to run an activity.

![[Pasted image 20230111152428.png|800]]