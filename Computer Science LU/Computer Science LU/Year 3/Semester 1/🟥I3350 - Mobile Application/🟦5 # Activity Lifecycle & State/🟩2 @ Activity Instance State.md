_Previous [[🟩1 @ Activity Lifecycle & Callbacks]]_

---

# Configuration
The app configuration changes invalidate the current layout or other resources in your activity when the user:
- Rotates the device
- Chooses different system language, so locale changes
- Enters multi-window mode (from Android 7)

On configuration change, Android: _(check out [[🟩1 @ Activity Lifecycle & Callbacks]])_
1. Shuts down Activity by calling:
	 - `onPause()`
	- `onStop()`
	- `onDestroy()`
2. Starts Activity over again by calling:
	- `onCreate()`
	- `onStart()`
	- `onResume()`

# Instance State
**State information** is created while the Activity is running, _such as a counter, user text, animation progression_.  **State is lost** when device is rotated, language changes, back-button is pressed, or the system clears memory.

## Saving And Restoring Activity State
The system saves only:
- State of views with unique ID (android:id) _such as text entered into EditText_
- Intent that started activity and data in its extras

### Saving
The programmer is responsible for saving other activity and user progress data. So to save the instance state implement `onSaveInstanceState()` in your Activity.
This function is called  by Android runtime when there is a possibility the Activity may be destroyed, and it saves data only for this instance of the Activity during current session.

Save your variables using a `Bundle` that can be accessed after configuration:
```java
@Override
public void onSaveInstanceState(Bundle outState) {
	super.onSaveInstanceState(outState);
	// outState.putString(variable_name, content_of_the_variable);
	outState.putString("count", String.valueOf(mShowCount.getText()));
}
```

### Restoring
There are 2 ways to retrieve the saved `Bundle`:
- in `onCreate(Bundle mySavedState)`
	Preferred, to ensure that your user interface, including any saved state, is backed up and running as quickly as possible
	```java
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		mShowCount = findViewById(R.id.show_count);
		
		if (savedInstanceState != null) {
			String count = savedInstanceState.getString("count");
			if (mShowCount != null)
				mShowCount.setText(count);
		}
	}
	```
- Implement callback _(called after `onStart()`)_ `onRestoreInstanceState(Bundle mySavedState)`
	```java
	@Override
	public void onRestoreInstanceState (Bundle mySavedState) {
		super.onRestoreInstanceState(mySavedState);
		if (mySavedState != null) {
			String count = mySavedState.getString("count");
			if (count != null)
				mShowCount.setText(count);
		}
	}
	```

## App Restart
When you stop and restart a new app session, the Activity instance states are lost and your activities will revert to their default appearance.
If you need to save user data between app sessions, use shared preferences or a database.

---

_Previous [[🟩1 @ Activity Lifecycle & Callbacks]]_
