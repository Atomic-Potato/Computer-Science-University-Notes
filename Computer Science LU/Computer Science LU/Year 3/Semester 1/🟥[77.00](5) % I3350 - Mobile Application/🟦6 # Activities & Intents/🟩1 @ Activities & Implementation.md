An Activity is an application component and it represents one window / one hierarchy of views.
Typically fills the screen, but can be embedded in other Activity or appear as floating window.

Activities are loosely tied together to make up an app. The first Activity user sees is typically called **_"main activity"_**. They can be organized in parent-child relationships in the Android manifest to aid navigation.

An Activity typically has a UI layout which is usually defined in one or more XML files.

# Implementation
An activity first needs a layout defined in **XML**:
```xml
<?xml version="1.0" encoding="utf-8"?>
<RelativeLayout
	xmlns:android="http://schemas.android.com/apk/res/android"
	android:layout_width="match_parent"
	android:layout_height="match_parent">
</RelativeLayout>
```

And a **Java class** to write functionality:
```java
public class MainActivity extends AppCompatActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main); 
	}
}
```

To connect the activity class with the layout we use the `setContentView()` function. _(More on it here: [[🟩1 @ Views#`setContentView()`]])_

Finally in the **manifest file** we declare this tag for our activity:
```xml
<activity android:name=".MainActivity">
```
 
And we need to include an `intent-filter` which states that this activity is the main activity which will be first opened when program is launched:
```xml
<activity android:name=".MainActivity">
	<intent-filter>
		<action android:name="android.intent.action.MAIN" />
		<category android:name="android.intent.category.LAUNCHER" />
	</intent-filter>
</activity>
```