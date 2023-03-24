```java
public static class MyReceiver extends BroadcastReceiver{
	Context c;
	Int param1;
	
	public MyReceiver(Int param1, Context context){
		c = context;
		this.param1 = param1;
		// ...
	}
	
	@Override
	public void onReceive(Context, Intent intent){
		// handle broadcast
	}
}

// Its usually a good idea to declare the receiver
// inside the main class
// so you wont have to send in vars
// through the constructor
```

```java
// In the maind class
MyReceiver reciever;
@Override
protected void onCreate(){
	// ...

	// Registering the broadcast
	reciever = new MyReceiver(69, this);
	registerReceiver(receiver, new IntentFilter("android.intent.action.AIRPLANE_MODE"));
}

@Override
protected void onDestroy(){
	super.onDestroy();
	unregisterReceiver(receiver);
}
```

# Permissions
```xml
// in AndroidManifest.xml
<uses-permission android:name="android.permission.INTERNET">
```