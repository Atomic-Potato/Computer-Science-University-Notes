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

# Activities Results
When an Intent is used to start an Activity or a Service, the component that is started can return a result back to the component that started it. This is known as an Intent result.

To use an Intent result, you typically start the Activity or Service using the `startActivityForResult()` method instead of the `startActivity()` method. 
When the Activity or Service finishes, it sets a result code and any additional data it wants to return to the calling component, and then finishes itself.

The calling component can then override the `onActivityResult()` method to receive the result data. The result data is passed to this method as a parameter, and can be used by the calling component to take further action based on the result.

## _Example_
In this example, when the user clicks the button in the `MainActivity`, it starts the `SecondActivity` using `startActivityForResult()`. When the `SecondActivity` finishes, it sets the result using `setResult()` and finishes itself. The `MainActivity` then receives the result in the `onActivityResult()` method, where it can be used as needed.

In the first activity, we'll start the second activity using `startActivityForResult()`:
```java
public class MainActivity extends AppCompatActivity {
    private static final int REQUEST_CODE = 1;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                startActivityForResult(intent, REQUEST_CODE);
            }
        });
    }
    
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_CODE) {
            if (resultCode == RESULT_OK) {
                String result = data.getStringExtra("result");
                Toast.makeText(this, "Result: " + result, Toast.LENGTH_SHORT).show();
            }
        }
    }
}
```

In the `SecondActivity`, we'll set the result and finish the activity:
```java
public class SecondActivity extends AppCompatActivity {
    private EditText editText;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        
        editText = findViewById(R.id.editText);
        
        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String result = editText.getText().toString();
                Intent intent = new Intent();
                intent.putExtra("result", result);
                setResult(RESULT_OK, intent);
                finish();
            }
        });
    }
}
```
# How Activities Run
All Activity instances are managed by the Android runtime. Started by an _"Intent"_, a message to the Android runtime to run an activity.

![[Pasted image 20230111152428.png|800]]